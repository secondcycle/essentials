import numpy as np

class tree:
    data  = 0
    left  = "NULL"
    right = "NULL"
    
    def __init__(self, data):
        self.data = data
        
    def setRightNode(self, right):
        self.right = right
        
    def setLeftNode(self, left):
        self.left = left
    
    def getLeftNode(self):
        return self.left
    
    def getRightNode(self):
        return self.right    



if __name__ == "__main__":
    # update data for each of the given nodes of the tree
    # with -1 for non-existent node
    
    inputArray = [2,7,5,2,6,-1,9,-1,-1,5,11,4,-1]

    inputArray = [1, 2, 3, 4, 5 , 6, 7, 8, 9, 10, 11, -1, 13, 14]

    inputArray = [3, 2, 5, 1, -1, 4, 6, -1, -1, -1,-1, -1, -1, -1, 7]

    print(inputArray)
    nodeData = []

    j = 0
    for i,element in enumerate(inputArray):
        nodeData.append(tree(int(element)))
        j = j+1


    numOfNodes = j
    # traverse Tree data array
    # after root node
    update = 0
    localCount = 0
    for i, element in enumerate(inputArray):


        #print("nodeData[{}].getdata = {}".format(i, nodeData[i].data))

        if((i+update+1) >= numOfNodes):
            nodeData[i].setLeftNode("NULL")
            #print("nodeData[{}].getLeftNode = {}".format(i, nodeData[i].getLeftNode()))
        else:
            if(nodeData[i+update+1] == -1):
                nodeData[i].setLeftNode(0)
            else:
                 nodeData[i].setLeftNode(nodeData[i+update+1])   
            #print("nodeData[{}].getLeftNode = {}".format(i, nodeData[i+update+1].data))


        if((i+update+2) >= numOfNodes):
            nodeData[i].setRightNode("NULL")
            #print("nodeData[{}].getRightNode = {}".format(i, nodeData[i].getRightNode()))
        else:
            if(nodeData[i+update+2] == -1):
                nodeData[i].setRightNode(0)
            else:
                nodeData[i].setRightNode(nodeData[i+update+2])

            #print("nodeData[{}].getRightNode = {}".format(i, nodeData[i+update+2].data))

        if(i == 0):
            update = update + 1 
        else:
            update = update + 1
            #print(" i = {} update = {} ".format(i, update))
        

    i = 0
    for i, element in enumerate(inputArray[::-1]):
        modifiedI = len(inputArray) - i -1;

        leftNode  = nodeData[modifiedI].getLeftNode()
        rightNode = nodeData[modifiedI].getRightNode() 

        if(leftNode == "NULL" and rightNode == "NULL"):
            if(nodeData[modifiedI].data == -1):
                nodeData[modifiedI].data = 0            
            else:
                nodeData[modifiedI].data = nodeData[modifiedI].data         

        elif(leftNode == "NULL" and rightNode != "NULL"):
            if(nodeData[modifiedI].data == -1):
                nodeData[modifiedI].data += 0            
            else:
                nodeData[modifiedI].data += int(rightNode.data)


        elif(leftNode != "NULL" and rightNode == "NULL"):
            if(nodeData[modifiedI].data == -1):
                nodeData[modifiedI].data += 0           
            else:
                nodeData[modifiedI].data += int(leftNode.data) 
        else:
            if(nodeData[modifiedI].data == -1):
                nodeData[modifiedI].data += 0
                nodeDataInPlace = 0
            else:
                nodeDataInPlace = nodeData[modifiedI].data

            nodeData[modifiedI].data = nodeDataInPlace + int(leftNode.data) + int(rightNode.data)

    '''
    print("Sum\n")
    for i in range(0, len(inputArray)):
        print("nodeData[{}].getdata = {}".format(i, nodeData[i].data))
        print("nodeData[{}].getLeftNode = {}".format(i, nodeData[i].getLeftNode()))
        print("nodeData[{}].getRightNode = {}".format(i, nodeData[i].getRightNode()))
        print("\n")
    '''

    print("nodeData[{}].getLeftNode = {}".format(0, nodeData[0].getLeftNode().data))
    print("nodeData[{}].getRightNode = {}".format(0, nodeData[0].getRightNode().data))

    if( nodeData[0].getLeftNode().data > nodeData[0].getRightNode().data ):
        print("Left")

    elif(nodeData[0].getLeftNode().data == nodeData[0].getRightNode().data ):
        print("Equal")

    else:
        print("Right")        
