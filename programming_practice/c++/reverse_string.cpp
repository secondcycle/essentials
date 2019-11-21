#include <iostream>
#include <string>

using namespace std;

int reverseString(string inputString){
    
    int length = inputString.length();
    
    int halfLength = length/2;
    
    char temp;
    
    for(int i=0; i < halfLength; i++ ){
        temp = inputString[i];
        inputString[i] = inputString[length-i-1];
        inputString[length-i-1] = temp;
    }
    
    cout << "\n inputString reversed = " << inputString;
    
    return 1;
}


int main()
{
    cout<<"Hello World";

    string s1 = "olleh";
    string s2 = "dlrow";
    
    if(1 == reverseString(s1)){
        cout << "\n Success !";
    }

    if(1 == reverseString(s2)){
        cout << "\n Success !";
    }
    
    return 0;
}
