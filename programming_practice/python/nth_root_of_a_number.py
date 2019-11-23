


def recurrenceComputeNthRoot(inputNumber, nthRoot, delta):

	x = inputNumber;

	numOfIter = 0;

	while(1):

		x1 = (1.0/(1.0*nthRoot) ) * ( (nthRoot - 1.0) * x + (inputNumber/(1.0* pow(x,(nthRoot-1))) ) )

		isFound = (abs(x1**nthRoot - inputNumber)  < delta)

		if(isFound == True):
			break

		x = x1
		numOfIter = numOfIter + 1

	return x



if __name__=="__main__":

	print(" IN python ")

	print(" Input the base value of the number : ")
	inputNumber = input()

	print(" Input the nth root value to be computed : ")
	nthRoot     = input()

	delta = 0.0001

	print("inputNumber = {} nthRoot = {} ".format(inputNumber, nthRoot))

	nthRootSolution = recurrenceComputeNthRoot(inputNumber, nthRoot, delta)

	actualValue = pow(inputNumber, (1/(nthRoot*1.0)))

	errorPercentage = abs((nthRootSolution - actualValue))/(1.0 * actualValue) * 100.0

	print(" {} Root of InputNumber {} is {}  with error percentage of {} with the actual value {} ".format(nthRoot, inputNumber, nthRootSolution, errorPercentage, actualValue))
