#웹프레임 backend 연동가능
#flask run, jdango, gradio(머신러닝), streamlif, dash

#gui(윈도우 리눅스)
#

from flask import Flask

app = Flask(__name__)

@app.route('/')
def hello():
    return "<h1> Hello Flask </h1>"