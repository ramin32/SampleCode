####################################################################
# my_pof_messages.py
#
# A simple script to scrape your pof messages and 
# print them to single html file. Also outputs to json.
# 
# Usage: 
# sudo pip install beautifulsoup4 requests jinja2
# python my_pof_messages.py <username> <password> <output_prefix>
# firefox output_prefix.html
#
# Author: 
# Ramin Rahkhamimov
# ramin32@gmail.com
# http://raminrakhamimov.com
#####################################################################

import requests
from bs4 import BeautifulSoup
import re
from jinja2 import Template
import json
import sys
from datetime import datetime

pof_url = lambda x: "https://www.pof.com/%s" % x
session = requests.session()
                                                           
def append_message_links(e, links):
    soup = BeautifulSoup(e.text)
    for a in soup.find_all(attrs={'href': re.compile('viewallmessages.*')}):
        links.append(pof_url(a.attrs['href']))

    next_page = soup.find('a', text='Next Page')
    return next_page and pof_url(next_page.attrs['href'])



def get_all_message_links(username, password):
    links = []
    payload = dict(username=username,
                   password=password,
                   tfset="300",
                   callback="http%3a%2f%2fwww.pof.com%2finbox.aspx",
                   sid="ikdnixh1pblvis1dlqaa0mb3") 

    e = session.post(pof_url("processLogin.aspx"), data=payload)
    next_page = append_message_links(e, links)
     
    while next_page:
        e = session.get(next_page)
        next_page = append_message_links(e, links)
    return set(links)

def clean_string(string):
    return string.encode('ascii', 'ignore')

def to_date(date_string):
    return datetime.strptime(date_string, '%m/%d/%Y %I:%M:%S %p')

def parse_all_messages(links):
    messages = []
    for link in links:
        comment_page = session.get(link)
        soup = BeautifulSoup(comment_page.text)
        for message in soup.find_all(attrs={'style': re.compile('width:500px.*')}):
            user = soup.find('span', 'username-inbox')
            user_image_url = soup.find('td', attrs={'width':"60px"}).img.attrs['src']
            messages.append(dict(user_username=clean_string(user.text),
                                 user_url=pof_url(user.a.attrs['href']),
                                 user_image_url=user_image_url,
                                 date=user.parent.find('div').text,
                                 message=clean_string(message.text)))
    return sorted(messages, key=lambda m: to_date(m['date']), reverse=True)


def save_messages(messages, prefix):
    template = Template("""
    <html>
    <head>
        <style>
            .user, .message, .date {
                display: inline-block;
                vertical-align: top;
            }
            .message { 
                width: 500px;
                padding-left: 10px;
            }
        </style>
    </head>
    <body>
        <ol>
        {% for message in messages %}
            <li>
            <a href="{{message.user_url}}" class="user">
            <img src="{{message.user_image_url}}"/>
            <div>
                {{message.user_username}}
            </div>

            </a>
            <div class="message">
                {{message.message}}
            </div>
            <div class="date">
                {{message.date}}
            </div>
            </li>
        {% endfor %}
        </ol>
    </body>
    </html>
    """)

    with open('%s.html' % prefix, 'w') as f:
        f.write(template.render(messages=messages))

    with open('%s.json' % prefix, 'w') as f:
        f.write(json.dumps(messages))

if __name__ == '__main__':
    if len(sys.argv) != 4:
        print "Usage: my_pof_messages.py <username> <password> <output_prefix>"

    links = get_all_message_links(sys.argv[1], sys.argv[2])
    messages = parse_all_messages(links)
    save_messages(messages, sys.argv[3])

