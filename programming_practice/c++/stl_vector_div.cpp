#include<iostream>
#include<string.h>
#include<vector>
#include<math.h>

using namespace std;


class vectorDemoClass{

public:
	vectorDemoClass(){
		cout << "vectorDemoClass Initiated \n" << endl;
	}

	~vectorDemoClass(){
		cout << "regaining of the memory space initiated \n" << endl;
	}

	template <typename T>
	auto divVectors(std::vector<T>v1, std::vector<T>v2, std::vector<T>*v3){

		for(int i=0; i<v1.size(); i++){
			v3->push_back(v1[i] / v2[i]);
		}
	}

	template <typename T>
	void printVectorElements(std::vector<T> vec){
		
		for(int i=0; i<vec.size(); i++){
			cout << " Vector element " << "[ " << i << " ] = " << vec[i];
		}
	}	
};


int main(){

	vectorDemoClass *vectorClassObj = new vectorDemoClass();
	std::vector<int> v1; 
	std::vector<int> v2; 
	std::vector<int> v3;

	int size;

	size = 8;	

	for(int i=0; i<size; i++){
		v1.push_back(i);
	}
	for(int i=0; i<size; i++){	
		v2.push_back(size-i);	
	}
	
//division
	cout << "\nvector 1: \n";
	vectorClassObj->printVectorElements(v1);
	cout << "\nvector 2: \n";
	vectorClassObj->printVectorElements(v2);
	vectorClassObj->divVectors(v1, v2, &v3);
	cout << "\nvector 3: \n";
	vectorClassObj->printVectorElements(v3);	
	v3.clear();

}