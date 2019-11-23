#!/bin/python3

import math
import os
import random
import re
import sys

def getHourGlassPatternIndexes(width):
 retList = [0, 1, 2, 1+width, 0+2*width, 1+2*width, 2+2*width]
 return retList

# Complete the hourglassSum function below.
def hourglassSum(arr):
    widthOfHourGlass = 3

    arrHeight = 6
    arrWidth  = int(len(arr)/arrHeight)

    #print(" arrWidth = {} arrHeight = {} ".format(arrWidth, arrHeight))

    largestHourGlassSum = []

    for numOfHourGlassY in range(0, int(arrHeight-widthOfHourGlass+1)):
        for numOfHourGlassX in range(0, int(arrWidth-widthOfHourGlass+1)): 
            hourGlassIndexList = getHourGlassPatternIndexes(arrWidth)
            sumVal = 0

            for indexAdjustment in hourGlassIndexList:
               pos = numOfHourGlassY * (arrWidth) + numOfHourGlassX 
               finalIndex = pos + indexAdjustment
               sumVal += arr[ finalIndex ]

            largestHourGlassSum.append(sumVal)

    largestHourGlassSum.sort()
    largestHourGlassSum = largestHourGlassSum[::-1]

    #print(largestHourGlassSum)
    retVal = largestHourGlassSum[0]

    return retVal

if __name__ == '__main__':

    arr = []

    
    for _ in range(2):
        arr.append(list(map(in 7t, input().rstrip().split())))

    
    for y, arrRow in enumerate(arr):
        for x, arrCol in enumerate(arrRow):
            array.append(arrCol)

    print(array)


    '''
    arr = [ 1, 1,  1,  0,   0,  0,
            0, 1,  0,  0,   0,  0,
            1, 1,  1,  0,   0,  0,
            0, 9,  2, -4,  -4,  0,
            0, 0,  0, -2,   0,  0,
            0, 0, -1, -2,  -4,  0]

    arr = [-9, -9, -9,  1, 1, 1,
            0, -9,  0,  4, 3, 2,
           -9, -9, -9,  1, 2, 3,
            0,  0,  8,  6, 6, 0,
            0,  0,  0, -2, 0, 0,
            0,  0,  1,  2, 4, 0  ]

    arr = [ 1, 1, 1, 0, 0, 0,
            0, 1, 0, 0, 0, 0,
            1, 1, 1, 0, 0, 0,
            0, 0, 2, 4, 4, 0,
            0, 0, 0, 2, 0, 0,
            0, 0, 1, 2, 4, 0 ]
    '''

    result = hourglassSum(arr)

    print(str(result))