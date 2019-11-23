
# BST, create, traverse, and modify

class node():

	right = "NULL"
	left  = "NULL"

	def __init__(self, data, right="NULL", left="NULL", nodeIdx=-1):
		self.data    = data
		self.right   = right
		self.left    = left
		self.nodeIdx = nodeIdx
		return

	def setDataForTheNode(self, data):
		self.data = data
		return 

	def setChildNodes(self, left, right):
		self.right = right
		self.left  = left

	def getDataFromNode(self):
		return self.data

	def getRelatedNodes(self):
		retDict= {}
		retDict["left"]  = self.left
		retDict["right"] = self.right
		return(retDict)

	def printNodeContent(self):
		print(" Node Data {}::{} \n  Node  Left : {}  \n  Node Right :  {} ".format(self.data, self.nodeIdx, self.left, self.right))
		return


if __name__=="__main__":

	numOfNodes = 11

	data = [chr(i) for i in range(65,65+numOfNodes)] 

	nodeObj = {}

	# just fill in the data
	j = 0
	while(j < numOfNodes):
		nodeObj[data[j]] = node(data[j], nodeIdx=j)
		j = j + 1

	i = 1
	j = 0
	# build up the tree
	while(j < numOfNodes/2):
		print(" @ j {}  -> {}  {}".format(j, i, i+1) )

		# left node
		nodeObjLeft = node(data[i])
		# right node
		nodeObjRight = node(data[i+1])
		nodeObj[data[j]].setChildNodes(nodeObjLeft, nodeObjRight)

		i = i + 2
		j = j + 1


	# print content of each node
	for key, value in nodeObj.items():
		nodeObj[key].printNodeContent()


	# traverse a certain path and print content
	listOfNodesToTraverse = [0, 1, 3, 7]

	for listIdx in listOfNodesToTraverse:
		dataContent = nodeObj[data[listIdx]]
		dataContent = dataContent.getDataFromNode()
		print("IDX {} ---DATA- {} ".format(listIdx, dataContent))
