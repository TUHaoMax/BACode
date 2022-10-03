
import flask as fs
import re
import requests
from bs4 import BeautifulSoup

address ="https://www.365chess.com/opening.php?"

app = fs.Flask(__name__)


@app.route("/")
def home():
    return '''<h1>function:<h1> 
               get_Key(key) <br/>
               get_Move(key)'''

@app.route("/<name>/<input>", methods=["GET"])
def function(name,input):
    if fs.request.method == "GET":
        for f in functions:
            if f.__name__==name:
                return f(input)
            else:
                return "no Function"
    return "no methods"

def Make_url(key):
    url=address+key
    return url

def get_Key(key):
    Keys=[]
    r=requests.get(Make_url(key))
    Soup=BeautifulSoup(r.text,"lxml")
    tags=Soup.find_all("a")
    for tag in tags:
        temp=str(tag.get("href"))
        if temp.startswith("/opening.php?"):
           Keys.append(temp.split("?")[1])
    return Keys[0]

def get_Move(key):
    Moves=[]
    r=requests.get(Make_url(key))
    Soup=BeautifulSoup(r.text,"lxml")
    tags=Soup.find_all("a")
    for tag in tags:
        temp=str(tag.get("href"))
        if temp.startswith("/opening.php?"):
            temp_1=str(tag)
            Moves.append(temp_1.split(". ")[1].split("<")[0])
    return Moves[0]


functions= [get_Key,get_Move]

if __name__== "__main__":
    app.run()    


