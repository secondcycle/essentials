#include<iostream>
#include<stack>
#include<bits/stdc++.h>
#include<string.h>
#include<list>


template <typename T>
std::stack<T> updateStack( std::stack<T> inputStack, std::list<T> inputList) {

	std::list<int>::iterator it;

	for(it = inputList.begin(); it != inputList.end(); it++){
		inputStack.push(*it);
		std::cout << " \n inputStack value : " <<  *it << std::endl;
	}

	return inputStack;
}

template <typename T>
std::stack<T> readFromStack(std::stack<T> inputStack){

	T tempValue;
	int stackSize;
	std::deque<T> tempDeque;

	stackSize = inputStack.size();

	std::cout << std::endl;

	for(int i=0 ; i < stackSize; i++){
		std::cout << " Top value : " << inputStack.top()  << std::endl;
		tempValue = inputStack.top();
		tempDeque.push_back(tempValue);
		inputStack.pop();
	}

	for( int i=0; i < tempDeque.size(); i++ ){
		tempValue = tempDeque.at(0);
		tempDeque.pop_front();
		inputStack.push(tempValue);
	}

	return inputStack;
}




int main(){

	std::cout << "main" << std::endl;

	std::stack<int> stackDataStructure;

	std::list<int> listWithData;

	listWithData.push_back(0);
	listWithData.push_back(1);
	listWithData.push_back(2);
	listWithData.push_back(3);
	listWithData.push_back(4);
	listWithData.push_back(5);
	listWithData.push_back(6);

	stackDataStructure = updateStack(stackDataStructure, listWithData);

	stackDataStructure = readFromStack(stackDataStructure);

	return 0;
}