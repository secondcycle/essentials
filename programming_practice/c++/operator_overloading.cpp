#include<iostream>
#include<math.h>
using namespace std;


class operatorOverloadingDemoClass {

public:
	double real;
	double complex;

	operatorOverloadingDemoClass(double r=0, double i=0){
		this->real    = r;
		this->complex = i;
		real    = this->real;
		complex = this->complex;
	}

	// complex numbers with two dimensions, addition
	operatorOverloadingDemoClass operator + (operatorOverloadingDemoClass const &obj){
		operatorOverloadingDemoClass result;
		result.real    = real    + obj.real;
		result.complex = complex + obj.complex;
		return result;
	}


	// complex numbers with two dimensions, subtraction
	operatorOverloadingDemoClass operator - (operatorOverloadingDemoClass const &obj){
		operatorOverloadingDemoClass result;
		result.real    = real    - obj.real;
		result.complex = complex - obj.complex;
		return result;
	}


	// complex numbers with two dimensions, multiplication
	operatorOverloadingDemoClass operator * (operatorOverloadingDemoClass const &obj){
		operatorOverloadingDemoClass result;
		result.real    = real    * obj.real;
		result.complex = complex * obj.complex;
		return result;
	}


	// complex numbers with two dimensions, division
	operatorOverloadingDemoClass operator / (operatorOverloadingDemoClass const &obj){
		operatorOverloadingDemoClass result;
		result.real    = real    / obj.real;
		result.complex = complex / obj.complex;
		return result;
	}


	// complex numbers with two dimensions, distance from origin
	operatorOverloadingDemoClass operator ! (){
		operatorOverloadingDemoClass result;
		result.real = this->real * this->real - this->complex * this->complex;
		result.real = std::pow(result.real, 0.5); 
		
		return result.real; 
	}

};



int main(){

	operatorOverloadingDemoClass testObj1, testObj2, testObj3;

	testObj1 = operatorOverloadingDemoClass(5, 4);

	testObj2 = operatorOverloadingDemoClass(20, 23);

	testObj3 = testObj1 + testObj2;
	cout << "\n Sum testObj3 = " << testObj3.real << " testObj3 = " << testObj3.complex << endl;

	testObj3 =  testObj2 - testObj1;
	cout << "\n Diff testObj3 = " << testObj3.real << " testObj3 = " << testObj3.complex << endl;

	testObj3 = testObj1 * testObj2;
	cout << "\n Prod testObj3 = " << testObj3.real << " testObj3 = " << testObj3.complex << endl;

	testObj3 = testObj1 / testObj2;
	cout << "\n Div testObj3 = " << testObj3.real << " testObj3 = " << testObj3.complex << endl;

	testObj3 = ! testObj1;
	cout << "\n Unary norm testObj3 = " << testObj3.real << endl;

	return 0;
}	