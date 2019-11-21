#include<iostream>
#include<string>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;


int main(){

	char typeOp;

	cout << "Bit Set Module "<< endl;

	bitset<4> bset1(9);
	bitset<4> bset2(8);

	while(1){

		cout << " Key in operation character ";
		cin >> typeOp;

		cout << "bset1 = " << bset1 << endl;
		cout << "bset2 = " << bset2 << endl;

		switch (typeOp){

			case 'a':
					cout << "OR bset3 = " << (bset1 | bset2) << endl;
					break;

			case 'b':
					cout << "AND bset3 = " << (bset1 & bset2) << endl;		
					break;

			case 'c':	
					cout << "NAND bset3 = " << ~(bset1 & bset2) << endl;
					break;
			
			case 'd':
					cout << "NOR bset3 = " << ~(bset1 | bset2) << endl;
					break;
			
			case 'e':
					cout << "XOR bset3 = " << (bset1 ^ bset2) << endl;				
					break;
			
			case 'f':
					cout << "XNOR bset3 = " << ~((bset1 & ~bset2) | (~bset1 & bset2)) << endl;
					break;

			case 'g':
					cout << "NOT Bset3 = " << ~bset1 << endl; 
					cout << "NOT Bset3 = " << ~bset2 << endl;
					break;

			default:
					cout << "Keyin proper character " << endl;
					exit(0);
					break;
		}

	}

	return 0;
}