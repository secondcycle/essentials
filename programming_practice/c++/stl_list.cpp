#include<iostream>
#include<math.h>
#include<list>

using namespace std;


list<int> listPrintElements(list<int> myListForTest){

	for(std::list<int>::iterator it = myListForTest.begin(); it != myListForTest.end(); it++){
    	std::cout << *it << ' ';
	}

	std::cout << endl;

	return myListForTest;
}



int main(){

	list<int> myListForTest;

	cout << " List Append \n";

	myListForTest = {1,2,3,4,5,6};


	for(std::list<int>::iterator it = myListForTest.begin(); it != myListForTest.end(); it++){
    	std::cout << *it << ' ';
	}

	std::cout << endl;
	
	myListForTest = listPrintElements(myListForTest);
	
	myListForTest.reverse();
	
	for(std::list<int>::iterator it = myListForTest.begin(); it != myListForTest.end(); it++){
    	std::cout << *it << ' ';
	}	
	
	std::cout << "\n";
	
	return 0;
}