#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#include<stack>
#include<list>

template < typename T1, typename T2 >
std::map<T1, T2> printTheCreatedMap(std::map<T1, T2> inputMapDataStructure){

	for(int i = 0 ; i < inputMapDataStructure.size(); i++){
		std::cout << " Map [ " << i << " ] = " <<  inputMapDataStructure[i] << std::endl;
	}

	return inputMapDataStructure;
}


int main(){

	std::map<int, char> map1;
	std::map<char, int> map2;
/*
	map1[0] = 'a';
	map1[1] = 'b';
	map1[2] = 'c';
	map1 = printTheCreatedMap(map1);
*/

	map2.insert(std::pair<int, int>(1, 100));
	map2.insert(std::pair<int, int>(2, 101));
	map2.insert(std::pair<int, int>(3, 102));
	map2.insert(std::pair<int, int>(5, 105));
	
	map2 = printTheCreatedMap(map2);

	return 0;
}