import flask as fs
import re
import requests
from bs4 import BeautifulSoup

address ="https://www.365chess.com/opening.php?"
temp=""
Keys=[]
Moves=[]
app = fs.Flask(__name__)
function= ["\nget_keys"]

@app.route("/")
def home():
    return '''<h1>function:<h1> 
               get_keys <br/>
               get_move '''

@app.route("/<name>")
def function(name):
    print(name)
    return (get_keys(name))

def Make_url(key):
    url=address+key
    return url

def get_keys(key):
    r=requests.get(Make_url(key))
    Soup=BeautifulSoup(r.text,"lxml")
    tags=Soup.find_all("a")
    for tag in tags:
        temp=str(tag.get("href"))
        if temp.startswith("/opening.php?"):
           Keys.append(temp.split("?")[1])
    return Keys[0]



if __name__== "__main__":
    app.run()    


