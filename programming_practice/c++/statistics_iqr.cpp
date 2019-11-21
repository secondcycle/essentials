#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <bits/stdc++.h> 


double computeMedian(std::list<double> inputListOfNumbers){
    double median, medianValueHigh, medianValueLow;
    int medianLow, medianHigh;
    int inputSize, iterate = 0;

    std::list<double> tempCopyList;

    tempCopyList = inputListOfNumbers;

    inputSize = inputListOfNumbers.size();

    if(inputSize & 1){
        medianHigh = (int)inputSize >> 1;

        while(iterate <= medianHigh){
            median = inputListOfNumbers.front();
            inputListOfNumbers.pop_front();
            iterate++;
        }
    }
    else{
        medianHigh = (int) inputSize >> 1 ;
        medianLow  = medianHigh - 1;
        
        while(iterate <= medianLow){
            medianValueLow = inputListOfNumbers.front();
            inputListOfNumbers.pop_front();
            iterate++;
        }
        medianValueHigh = inputListOfNumbers.front();

        median = (medianValueHigh + medianValueLow)/2.0;
    }

    inputListOfNumbers = tempCopyList;

    return median;
}

template <typename T>
std::list<T> copyElementsOfTheList(std::list<T>inputList, int startIndex, int endIndex){
	std::list<T> outputList, tempCopyList;
	T tempValue;

	tempCopyList = inputList;

	for(int intIndex = 0; intIndex < inputList.size(); intIndex++){

		if( (intIndex >= startIndex) and (intIndex < endIndex) ){
			tempValue =  tempCopyList.front();
			outputList.push_back( tempValue );

			tempCopyList.pop_front();
		}
		else{
			tempCopyList.pop_front();
		}	
	}

	return outputList;
}

template <typename T>
printContentOfTheList(std::list<T> inputList ){
	std::list<T> outputList, tempCopyList;

	std::cout << "---------------------------------" << std::endl;

	tempCopyList = inputList;

	for(int intIndex=0; intIndex < inputList.size(); intIndex++){
		std::cout << tempCopyList.front() << std::endl;
		tempCopyList.pop_front();
	}

	std::cout << "*********************************" << std::endl;
}


double computeIQR(std::list<double> inputElementsList){

	double Q1,Q2,Q3;
	std::list<double> tempElementListOne;
	std::list<double> tempElementListTwo;
	int inputSizeQ1, inputSizeQ2;
	int isEven;

	Q2 = computeMedian(inputElementsList);
 

	inputSizeQ1 = (int)inputElementsList.size()/2;

	isEven = ((inputElementsList.size() & 1) == 0);

	tempElementListOne = copyElementsOfTheList(inputElementsList, 0, inputSizeQ1+isEven);

	printContentOfTheList(tempElementListOne);

	//construct list for Q1 computation
	Q1 = computeMedian(tempElementListOne);
	

	tempElementListTwo = copyElementsOfTheList(inputElementsList, inputSizeQ1+1-isEven, inputElementsList.size()+1);

	printContentOfTheList(tempElementListTwo);

	//construct list for Q3 computation
	Q3 = computeMedian(tempElementListTwo);

	std::cout << Q1 << std::endl;   
	std::cout << Q2 << std::endl;  
	std::cout << Q3 << std::endl;   

	return(Q3 - Q1);
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int inputSize;
    char tempValue[100];
    std::list<double> inputElementsList;
    std::list<double> inputWeightsList;
    double iqrValue;
    int i;

    
    std::cin >> tempValue;
    inputSize = std::atoi(tempValue);

    for(int i=0; i < inputSize; i++){
        std::cin >> tempValue;
        inputElementsList.push_back(std::atof(tempValue));
    }

    std::cout << " output" << std::endl;

    inputElementsList.sort();

    printContentOfTheList(inputElementsList);

    iqrValue = computeIQR(inputElementsList); 
    
    return 0;
}