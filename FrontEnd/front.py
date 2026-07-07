from flask import Flask, render_template
import subprocess

app = Flask(__name__)

@app.route('/')
def hello():
    # result = subprocess.run(['ASCII-CAM/BackEnd/cam.cpp'], capture_output=True, text=True)
    # cpp_value = result.stdout.strip()

    return render_template('front.html')

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)   