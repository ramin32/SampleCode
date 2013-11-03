#################################################################
# Push notifications with Flask, EventSource and redis
#
# 1. Run python push_notifications.py 
# 2. Open a bunch of browsers pointing to http:localhost:5000/
# 3. Open up each browser's console window.
# 4. Hit submit in one, the rest should update.
#
# Author: Ramin Rakhamimov
# http://raminrakhamimov.com
# ramin32@gmail.com
#################################################################

import flask, redis

app = flask.Flask(__name__)
red = redis.StrictRedis(host='localhost', port=6379, db=0)

def event_stream():
    pubsub = red.pubsub()
    pubsub.subscribe('notifications')
    for message in pubsub.listen():
        print message
        yield 'data: %s\n\n' % message['data']


@app.route('/post', methods=['POST'])
def post():
    red.publish('notifications', 'Hello!')
    return flask.redirect('/')


@app.route('/stream')
def stream():
    return flask.Response(event_stream(), mimetype="text/event-stream")

@app.route('/')
def index():
    return '''
<html>
<head>
    <script>
        var source = new EventSource('/stream');
        source.onmessage = function (event) {
             console.log(event.data);
        };
    </script>
</head>
<body>
    <form method="POST" action="/post">
        <input type="submit"/>
    </form>
</body>
</html>

'''

if __name__ == '__main__':
    app.debug = True
    app.run(threaded=True)
