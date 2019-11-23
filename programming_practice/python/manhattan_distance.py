import numpy as np


def findSmallestInaDictionary(inputDict):

	returnPosTuple = (-1,-1)
	returnPosDict = {}

	listForSorting = inputDict.values()
	listForSorting.sort()

	foundMatchingDistanceIndx = 0 
	for key, val in inputDict.items():
		
		if(val == listForSorting[0]):
			returnPosDict[foundMatchingDistanceIndx] = (key[2:key.find('_y_')], key[key.find('_y_')+3:])
			foundMatchingDistanceIndx = foundMatchingDistanceIndx + 1

	return returnPosDict



def findEuclideanDistanceFromCurrentLocation(currentLocationPawn, coinsPlaceList):

	# euclidean distance from the current position
	distanceDict = {}

	for coinsTuple in coinsPlaceList:
		xDistance = abs(currentLocationPawn[0] - coinsTuple[0])
		yDistance = abs(currentLocationPawn[1] - coinsTuple[1])

		key = 'x_' + str(coinsTuple[0]) + '_y_' + str(coinsTuple[1])
		distanceDict[key] = (xDistance**2 + yDistance**2)**0.5

	return distanceDict


def findManhattanDistanceFromCurrentLocation(currentLocationPawn, coinsPlaceList):

	# manhattan distance from the current position
	distanceDict = {}

	for coinsTuple in coinsPlaceList:
		xDistance = abs(currentLocationPawn[0] - coinsTuple[0])
		yDistance = abs(currentLocationPawn[1] - coinsTuple[1])

		key = 'x_' + str(coinsTuple[0]) + '_y_' + str(coinsTuple[1])
		distanceDict[key] = xDistance + yDistance

	return distanceDict


def placeCoinsRandomly(numOfCoins, grid, currentLocationPawn):

	coinsPlaceList = []
	ySize = len(grid[0])
	xSize = len(grid[0][:])

	isOverlapRandom = True
	isCurrentLocationPawnOverlap = True

	# construct the possible places list
	intermediateList = []

	for yIndex in range(0, yGridSize):
		for xIndex in range(0, xGridSize):
			if(currentLocationPawn == (yIndex, xIndex)):
				continue
			
			intermediateList.append((yIndex, xIndex))

	coins = 0
	while(coins < int(numOfCoins)):
		pos = np.random.randint(0,len(intermediateList))
		coinPlaceTuple = intermediateList[pos]
		xPos = coinPlaceTuple[ 1 ]
		yPos = coinPlaceTuple[ 0 ]
		intermediateList.remove((yPos,xPos))
		coinsPlaceList.append((yPos, xPos))
		coins = coins + 1
		grid[yPos][xPos] = [77]


	return coinsPlaceList, grid


def createGrid(xGridSize, yGridSize):

	grid = []

	for yPos in range(0,yGridSize):
		grid.append([])
		for xPos in range(0, xGridSize):
			grid[yPos].append(0)

	return grid

def printGridBeautifully(inputGrid, xGridSize, yGridSize):

	for y in range(0, yGridSize):
		print("\n {} \n".format(inputGrid[y]))


if __name__=="__main__":

	print(" Search for coin optimally")

	print(" Input x dimenstion of grid = ")
	xGridSize = input()

	print(" Input y dimenstion of grid = ")
	yGridSize = input()

	if(xGridSize*yGridSize < 2):
		print(" Error in gridSize ")
		exit(0)

	isCorrect = True
	while(isCorrect == True):
		if(isCorrect == True):
			print(" Input number of coins = ")
			numOfCoins = input()
			isCorrect = int(numOfCoins) > (int(xGridSize)*int(yGridSize)-1)
		else:
			isCorrect = True

	print(" Input position x of pawn position ")
	xPosOfPawn = input()

	print(" Input position y of pawn position ")
	yPosOfPawn = input()

	if((numOfCoins < 1 ) or (yGridSize <= 0) or (xGridSize <=0 ) or (xPosOfPawn < 0) or (yPosOfPawn < 0) or (xPosOfPawn > xGridSize) or (yPosOfPawn > yGridSize) ):
		print("Error in input parameters ")
		exit(0)


	print(" Creating grid  = xGridSize = {} yGridSize = {}".format(xGridSize, yGridSize))
	grid = createGrid(xGridSize, yGridSize)

	currentLocationPawn  = (yPosOfPawn,  xPosOfPawn)

	print("\n Placing grids randomly ")

	coinsPlaceList, grid = placeCoinsRandomly(numOfCoins, grid, currentLocationPawn)

	grid[xPosOfPawn][yPosOfPawn] = [99]

	print("\n Grid with coins placed randomly ")
	printGridBeautifully(grid,xGridSize, yGridSize)

	distanceDict = findManhattanDistanceFromCurrentLocation(currentLocationPawn, coinsPlaceList)

	nearestCoinTupleDict = findSmallestInaDictionary(distanceDict)	

	for key,value in nearestCoinTupleDict.items():
		xVal = int(value[1])
		yVal = int(value[0])
		distance = (xVal**2 + yVal**2)**0.5
		print("\n \n Nearest Coin location from {} is {} with Manhattan distance {}".format(currentLocationPawn, value , distance))

	print("\n \n Here Current Pawn location is {} and coin/s is/are @ {} and the free space/s is/are = {} ".format([99], [77], [00]))


	distanceDict = findEuclideanDistanceFromCurrentLocation(currentLocationPawn, coinsPlaceList)

	nearestCoinTupleDict = findSmallestInaDictionary(distanceDict)	

	for key,value in nearestCoinTupleDict.items():
		xVal = int(value[1])
		yVal = int(value[0])
		distance = (xVal**2 + yVal**2)**0.5		
		print("\n \n Nearest Coin location from {} is  {}  with Euclidean distance {} ".format(currentLocationPawn, value , distance))

	print("\n \n Here Current Pawn location is {} and coin/s is/are @ {} and the free space/s is/are = {} ".format([99], [77], [00]))