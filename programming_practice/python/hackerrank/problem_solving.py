#!/bin/python3

import math
import os
import random
import re
import sys

def checkMagazine(magazine, note):
    countNumOfOccurencesInMagDict  = {}
    countNumOfOccurencesInNoteDict = {}

    for element in magazine:
        countNumOfOccurencesInMagDict[element] = magazine.count(element)
    

    for element in note:
        countNumOfOccurencesInNoteDict[element] = note.count(element)

    probable = 0
    count = 0
    for key in note: 
        listData = countNumOfOccurencesInMagDict.keys()
        for element in listData:
            if(element == key):
                count+=1

        if((listData.count(key) == 0) or (count == 0)):
            probable = 0
            print("No")
            break
        else:
         if(countNumOfOccurencesInMagDict[key] >= countNumOfOccurencesInNoteDict[key]):
                probable = 1

    if(probable == 1):
        print("Yes")



if __name__ == '__main__':

    #6 5
    magazineInput = "two times three is not four"
    noteInput     = "two times two is five"

    #magazineInput = "give me one grand today night"
    #noteInput     = "give one grand today"

    magazine = []
    note = []

    a = ""
    for magazineChar in magazineInput:
        a += magazineChar
        if(magazineChar == ' '):
            magazine.append(a)
            a = ""
        magazine.append(a)

    a = ""
    for noteInputChar in noteInput:
        a += noteInputChar
        if(noteInputChar == ' '):
            note.append(a)
            a = ""

        note.append(a)

    checkMagazine(magazine, note)
