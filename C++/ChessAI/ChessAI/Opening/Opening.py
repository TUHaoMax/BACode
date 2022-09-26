import re

import requests

from bs4 import BeautifulSoup

address ="https://www.365chess.com/opening.php?"
temp=""
Keys=[]
Moves=[]

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
    print(Keys)
    return Keys


def get_Moves(key):
    r=requests.get(Make_url(key))
    Soup=BeautifulSoup(r.text,"lxml")
    tags=Soup.find_all("a")
    for tag in tags:
        temp=str(tag.get("href"))
        if temp.startswith("/opening.php?"):
            temp_1=str(tag)
            Moves.append(temp_1.split(". ")[1].split("<")[0])
    print(Moves)
    return Moves

def check(key,move):
    b = b'No'
    key=str(key)
    key=key.split("'")[1].split("'")[0]
    r=requests.get(Make_url(key))
    Soup=BeautifulSoup(r.text,"lxml")
    tags=Soup.find_all("a")
    for tag in tags:
        temp=str(tag.get("href"))
        if temp.startswith("/opening.php?"):
            temp_1=str(tag)
            Keys.append(temp.split("?")[1])
            Moves.append(temp_1.split(". ")[1].split("<")[0])
    if move in Moves:
        i=Moves.index(move)
        Keys[i]=bytes(Keys[i],'utf-8')
        return Keys[0]
    else:
        return b

#get_keys("m=1&n=1")
#get_Moves("m=1&n=1")

