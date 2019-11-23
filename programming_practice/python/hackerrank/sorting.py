
if __name__=='__main__':

	transformedScoreDict = {}

	for a in range(int(raw_input())):
		name = raw_input()
		score = float(raw_input())
		transformedScoreDict[str(name)] = {}
		transformedScoreDict[str(name)]["name"] = name
		transformedScoreDict[str(name)]["score"] = float(score)
	
	print(transformedScoreDict)
	
	'''
	transformedScoreDict["Harry"] 		   = {}
	transformedScoreDict["Harry"]["name"]  = "Test1"
	transformedScoreDict["Harry"]["score"] = float(3)

	transformedScoreDict["Berry"] 		  = {}
	transformedScoreDict["Berry"]["name"]  = "Test2"
	transformedScoreDict["Berry"]["score"] = float(52)

	transformedScoreDict["Tiny"] 		  = {}
	transformedScoreDict["Tiny"]["name"]  = "Test3"
	transformedScoreDict["Tiny"]["score"] = float(53)

	transformedScoreDict["Akriti"] 		    = {}
	transformedScoreDict["Akriti"]["name"]  = "Test4"
	transformedScoreDict["Akriti"]["score"] = float(53)
	'''

	arr = []

	for key, valueDict in transformedScoreDict.items():
		scoreVal = valueDict["score"]
		arr.append(scoreVal)

	arr.sort()
	
	#print(arr)

	smallest = arr[0]
	secondSmallest = arr[1]

	for element in arr:
		if(element <= smallest):
			smallest = element

		if(element == smallest):
			continue

		if((element <= secondSmallest) or (secondSmallest == smallest)):
			secondSmallest = element
			break

	#print("Smallest {} ".format(smallest))
	#print(" Second Smallest {} ".format(secondSmallest))

	nameList = []
	for name, valueDict in transformedScoreDict.items():
		if(valueDict["score"] == secondSmallest):
			nameList.append(name)

	nameList.sort()
	
	for name in nameList:
		print(name)


'''	
5
Harry
37.21
Berry
37.21
Tina
37.2
Akriti
41
Harsh
39
'''