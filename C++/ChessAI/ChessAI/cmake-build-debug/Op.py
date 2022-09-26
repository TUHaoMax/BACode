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
    key=str(key)
    key=key.split("'")[1].split("'")[0]
    #print(key)
    r=requests.get(Make_url(key))
    Soup=BeautifulSoup(r.text,"lxml")
    tags=Soup.find_all("a")
    for tag in tags:
        temp=str(tag.get("href"))
        if temp.startswith("/opening.php?"):
            Keys.append(temp.split("?")[1])
            break
    #print(Keys)
    Keys[0]=bytes(Keys[0],'utf-8')
    return Keys[0]


def get_Moves(key):
    key=str(key)
    key=key.split("'")[1].split("'")[0]
    #print(key)
    r=requests.get(Make_url(key))
    Soup=BeautifulSoup(r.text,"lxml")
    tags=Soup.find_all("a")
    for tag in tags:
        temp=str(tag.get("href"))
        if temp.startswith("/opening.php?"):
            temp_1=str(tag)
            Moves.append(temp_1.split(". ")[1].split("<")[0])
            break
    #print(Moves)
    Moves[0]=bytes(Moves[0],'utf-8')
    return Moves[0]

def check(key):
    b = b'No'
    temp=str(key)
    key=temp.split("'")[1].split("'")[0].split("+")[0]
    #print(key)

    move=temp.split("'")[1].split("'")[0].split("+")[1]
    #print(move)

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
        print(move)
        print(i)
        Keys[i]=bytes(Keys[i],'utf-8')
        return Keys[i]
    else:
        return b

#get_keys("m=1&n=1")
#get_Moves("m=1&n=1")