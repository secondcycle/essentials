#include<iostream>
#include<string>
#include<thread>

using namespace std;

#define NUM_OF_THREADS 1

std::thread funcToRunOnThreads1(int *i){
	int j=0;

	while(j  < 10){
		std::cout << " \n funcToRunOnThreads [ " << *i << "] " << std::endl;
		j++;	
	}
}

std::thread funcToRunOnThreads2(int *i){
	int j=0;

	while(j  < 10){
		std::cout << " \n funcToRunOnThreads [ " << *i << "] " << std::endl;
		j++;	
	}
}

int main(){

	int i=0, j=1;

	//std::thread threadArray1, threadArray2;
	std::cout << "Start threads " << std::endl;

	std::thread threadArray1 (funcToRunOnThreads1(&i));
	std::cout << " Started thread with index = " << i << endl;

	std::thread threadArray2 (funcToRunOnThreads2(&j));
	std::cout << " Started thread with index = " << j << endl;

	threadArray1.join();
	threadArray2.join();

	return 0;
}