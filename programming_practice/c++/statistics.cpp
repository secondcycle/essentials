#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <bits/stdc++.h> 

using namespace std;

#define MAXCONSTRAINT_ON_N 2501
#define MINCONSTRAINT_ON_N 8

#define MAXCONSTRAINT_ON_XI 100001
#define MINCONSTRAINT_ON_XI 0

void constructTheList(int size, std::list<double> *retList){
    
    double inputNumber;
    char inputStr[100];

    //std::cout << "Enter the numbers in the input list, enter "<< std::endl;
    for(int i=0; i < size ; i++){    
        std::cin >> inputStr ;
        inputNumber = std::atof(inputStr);
        retList->push_back(inputNumber);
    }

    return;
}

double computeMean(std::list<double> inputListOfNumbers){
    double mean;
    double sum =0;
    int count = 0;

    for(auto it= inputListOfNumbers.begin(); it != inputListOfNumbers.end(); it++){
        sum += *it;
        count++;
    }

    mean = sum/(1.0 * count);

    return mean;
}


double computeMedian(std::list<double> inputListOfNumbers, int inputSize){
    double median, medianValueHigh, medianValueLow;
    int medianLow, medianHigh;
    int iterate = 0;

    std::list<double> tempCopyList;

    tempCopyList = inputListOfNumbers;

    inputListOfNumbers.sort();

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

double computeMode(std::list<double> inputListOfNumbers){
    double mode = -1;
    int iteratorCount;
    int isFoundCount, notDuplicateEntry;
    int largestDuplicate;
    std::list<double> probableModeList; 
    std::list<int> numOfTimesOccuredList;


    inputListOfNumbers.sort();
    // write how many times a number has occured in the list
    notDuplicateEntry = 0;

    for(std::list<double>::iterator itOut=inputListOfNumbers.begin(); itOut != inputListOfNumbers.end(); itOut++){

            int tempVar= 0;

            // check if duplicate entry
            for(std::list<double>::iterator checkItOut= probableModeList.begin(); checkItOut != probableModeList.end(); checkItOut++){
                if(*checkItOut == *itOut){
                    notDuplicateEntry = 1;
                    tempVar = 1;
                }
                else{
                    notDuplicateEntry = 0;
                    tempVar = 0;
                    break;
                }
            }

            if((notDuplicateEntry == 1) and (tempVar == 1)){
                continue;
            }

            probableModeList.push_back(*itOut);
            isFoundCount = 0;
            
            if(notDuplicateEntry == 0){
                for(std::list<double>::iterator itIn = inputListOfNumbers.begin(); itIn != inputListOfNumbers.end(); itIn++){
                    if(*itIn == *itOut){
                        isFoundCount++;
                    }
                }
                
                numOfTimesOccuredList.push_back(isFoundCount);
            }
    }

    largestDuplicate = 0;
    iteratorCount = 0;
    
    std::list<double>::iterator iteratorProbableListIterator = probableModeList.begin();

    // determine the mode, smallest mode (if many);
    for(std::list<int>::iterator checkItOut= numOfTimesOccuredList.begin(); checkItOut != numOfTimesOccuredList.end(); checkItOut++){

        if(largestDuplicate < *checkItOut){
            largestDuplicate = *checkItOut;
            mode = *iteratorProbableListIterator;
        }

        iteratorProbableListIterator++;
    }

    return mode;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    std::list<double> inputListOfNumbers;
    int    size=0;
    double mean = 0;
    double median = 0;
    double mode = 0;
    

    //std::cout << "Enter Size of the array = " << std::endl;
    cin >> size;

    constructTheList(size, &inputListOfNumbers);

    //std::cout << "Size of the array = " << size << std::endl;

    mean   = computeMean(inputListOfNumbers);
    
    median = computeMedian(inputListOfNumbers, size);
    
    mode   = computeMode(inputListOfNumbers);

    //std::cout << "Size of the array = " << size << std::endl;

    std::cout << mean << std::endl;
    
    std::cout << median << std::endl;
    
    std::cout << mode << std::endl;
    
    return 0;
}
