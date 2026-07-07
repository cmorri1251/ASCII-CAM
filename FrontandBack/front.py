from flask import Flask, render_template
import subprocess

app = Flask(__name__)

@app.route('/')
def hello():

    return render_template('front.html')

@app.route('stream')
def stream():
    pass

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)   