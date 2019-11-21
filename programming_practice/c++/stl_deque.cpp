#include<iostream>
#include<bits/stdc++.h>
#include<string.h>


using namespace std;


int main(){

	cout << " Main function " << endl;

	std::deque<int> dequeData;
	int size;

	dequeData.push_back(0);
	dequeData.push_back(1);
	dequeData.push_back(2);
	dequeData.push_back(3);
	dequeData.push_back(4);
	dequeData.push_back(5);
	dequeData.push_back(6);
	dequeData.push_back(7);

	for(std::deque<int>::iterator it=dequeData.begin(); it != dequeData.end(); it++){
		cout << " Deque  :" << *it << endl;
	}

	size = dequeData.size();

	for(int i=0; i < size; i++){
		
		// current ends
		cout << "\n Current left end " <<  dequeData.at(0) << "\n Current right end " <<  dequeData.at(dequeData.size()-1) << endl;
		
		if(i & 1){
			dequeData.pop_front();
		}
		else{
			dequeData.pop_back();
		}
		
	}

	return 0;
}