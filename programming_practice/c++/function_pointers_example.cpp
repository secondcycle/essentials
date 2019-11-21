#include<iostream>
#include<string>
using namespace std;

class functionPointersClass{
	public:
		int gNumberOfMemberFuncs = 4;
		int globalCount = 0;

		functionPointersClass(){
			cout << "\n functionPointersClass new Object created !\n";
		}

		~functionPointersClass(){
			cout << "\n functionPointerClass Object destructed !\n";
		}

		void* baseNameFunc0(int *a){
			cout << "\n BaseNameFunc0:" ;
			//*localCount +=1;
		}
		
		void* baseNameFunc1(float *localCount){
			cout << "\n BaseNameFunc1:" ; 
			*localCount +=1.1;
		}

		void* baseNameFunc2(double *localCount){
			cout << "\n BaseNameFunc2:" ;
			*localCount +=1.2;
		}

		void* baseNameFunc3(int *localCount){
			cout << "\n BaseNameFunc3:" ;
			*localCount += 2;
		}

		void* getMemberFuncPointers(int memberFuncNameIndex, void *inputArgs[]){
			
			switch(memberFuncNameIndex) {
				case 0:						
						int a;
						int *p = (int*)inputArgs[0];

						for(int i=0; i < 10; i++){
							cout << "\n P = " << i << " IN array inputArgs = " << p[i] << "\n";
						}

						int *q = (int*) inputArgs[1];
						for(int i=0; i < 10; i++){
							cout << "\n Q = " << i << " IN array inputArgs = " << q[i] << "\n";
						}

						char *r = (char*) inputArgs[2];
						for(int i=0; i < 10; i++){
							cout << "\n R = " << i << "  " <<   &r[i] << "  IN array inputArgs = " << r[i] << "\n";
						}

						return this->baseNameFunc0(&a);
						break;
				
				case 1:
						float b;
						return this->baseNameFunc1(&b);
						break;
				case 2:
						double c;
						return this->baseNameFunc2(&c);
						break;
				case 3:
						int d;
						return this->baseNameFunc3(&d);
						break;
				default:
						cout << "Error in name of the member function \n" ;
						return NULL;
			}
			
			return NULL;
		}


};


int main(){

	functionPointersClass *fp = new functionPointersClass();
	int i;
	int memberFuncNameIntArr[4] = {0, 1, 2, 3};
	void *inputArgs[10];
	int *p,*q;
	char *c;

	
	inputArgs[0] = (int *)new int(10);
	inputArgs[1] = (int *)new int(10);
 	inputArgs[2] = (char *)new char(100);
 	inputArgs[3] = NULL;

	p = (int *)inputArgs[0]; 
	q = (int *)inputArgs[1];
	c = (char *)inputArgs[2];

	for(i=0; i < 10; i++){
		p[i] = (int)100  + i;
		q[i] = (int)1000 + i;
		c[i] = 'z';
		cout << "\n  " << &c[i] <<  " Char  " << c[i];
	}

	fp->getMemberFuncPointers(0, (void *)inputArgs);

	return 1;

	for(i=0; i < fp->gNumberOfMemberFuncs; i++){
		cout << " Global Count =  " << fp->globalCount;
		break; 
	} 

	delete fp;

	return 0;
}