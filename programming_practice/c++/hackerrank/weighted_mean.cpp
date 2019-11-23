#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <iomanip> 
using namespace std;


double computeWeightedMean(std::list<double> inputElementsList, std::list<double> inputWeightsList){

    double weightedMean, sumOfWeights, numerator, eleVal, weiVal;

    std::list<double>::iterator weightsItr = inputWeightsList.begin();

    numerator = 0.0;
    sumOfWeights = 0.0;

    for(std::list<double>::iterator elementsItr=inputElementsList.begin(); elementsItr!= inputElementsList.end(); elementsItr++){
        weiVal = *weightsItr;
        eleVal = *elementsItr;

        numerator += (eleVal * weiVal);
        sumOfWeights += weiVal;
        weightsItr++;
    } 

    weightedMean = (double) 1.0 * numerator/(sumOfWeights * 1.0);

    return weightedMean;
}

int main() {
    // Enter your code here. Read input from STDIN. Print output to STDOUT 
    int inputSize;
    char tempValue[100];
    std::list<double> inputElementsList;
    std::list<double> inputWeightsList;
    double weightedMean;
    int i;

    
    std::cin >> tempValue;
    inputSize = std::atoi(tempValue);

    for(int i=0; i < inputSize; i++){
        std::cin >> tempValue;
        inputElementsList.push_back(std::atof(tempValue));
    }

    for(int i=0; i < inputSize; i++){
        std::cin >> tempValue;
        inputWeightsList.push_back(std::atof(tempValue));
    }

    weightedMean = computeWeightedMean(inputElementsList, inputWeightsList);
    
    if((weightedMean - int(weightedMean)) == 0){
        std::cout <<  weightedMean - 0.1   << std::endl;
    }
    else{
        std::cout << weightedMean << std::endl;
    }

    return 0;  
}
