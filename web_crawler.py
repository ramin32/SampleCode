#!/usr/bin/env python

########################################################
# web_crawler.py
# 
# A very naive web crawler.
# simply permutes over all possible ip cominations
# Prints title of each valid ip to stdout and index.txt
#
# Author:
# Ramin Rakhamimov
# ramin32 at gmail dot com
# http://raminrakhamimov.com
########################################################

import urllib2
import BeautifulSoup
#import pickle

ONE_BYTE = 256

index_file = open('index.txt', 'a')
#cache_file = open('ip_cache.txt', 'rw')

#ip_cache = pickle.load(cache_file)



# permute all ip bytes (permute backwards for more interesting results)
for i in reversed(xrange(ONE_BYTE)):
    for j in reversed(xrange(ONE_BYTE)):
        for k in reversed(xrange(ONE_BYTE)):
            for l in reversed(xrange(ONE_BYTE)):
                address = 'http://%s.%s.%s.%s' % (i, j, k, l)
                print 'Trying ip: %s' % address

                try:
                    url = urllib2.urlopen(address, timeout=5)
                    contents =  url.read()
                    print 'Contents: %s' % contents

                    soup = BeautifulSoup.BeautifulSoup(contents) 

                    url_title = ''.join(soup.html.head.title.string, '\n')

                    # log results
                    print 'URL title: %s ' % url_title
                    index_file.write(url_title)

                except urllib2.URLError, AttributeError:
                    print "Nothing Found!"
index_file.close()

