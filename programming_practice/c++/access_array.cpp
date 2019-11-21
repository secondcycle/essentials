#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i,j;
    int n,q, l1,l2, listIndex1, listIndex2;
    int x, y;
    std::list<int> a0, inputList1;
    std::list<int> a1;
    std::list<int> inputList2;
    int size1, size2;

    cin >> n;
    cin >> q;

    cin >> l1;
    for(int x=0; x < l1; x++){
        cin >> y;
        a0.push_back(y);
    }
    
    cin >> l2;
    for(int x=0; x < l2; x++){
        cin >> y;
        a1.push_back(y);
    }

    cin >> listIndex1;
    cin >> i;

    cin >> listIndex2;
    cin >> j;

    if(i == 0){
        inputList1 = a1;
        inputList2 = a0;
        /*x = j;
        j = i;
        i = x;*/

        //cout << " IN Not swapped " << endl;
    }
    else{
        inputList1 = a1;
        inputList2 = a0;
        /*x = j;
        j = i;
        i = x; */ 
        cout << " IN swapped  i = " << i  << "j " << j << endl;
    }

    //cout << " i = " << i << endl;

    //cout << " j = " << j  << " size a1 " << inputList1.size() << endl;


    size1 = inputList1.size();
    size2 = inputList2.size();


    cout << " size1 = " << size1  << " size2 =  " << size2 << endl;

    for(x=0; x < size1; x++){
        //std::cout << "x = " << x << endl;
        //std::cout<< "Cond = " << (j == x) << std::endl;
        
        if(j == x){
            std::cout<< inputList1.back() << std::endl;
            //std::cout << "Inside x = " << x << endl;
            break;
        }
        inputList1.pop_back();

    }

    for(x=0; x < size2; x++){
        if(i == x){
            std::cout<< inputList2.back() << std::endl;
            //std::cout << "x2 = " << x << endl;
            break;
        }
        inputList2.pop_back();
        //std::cout << "x2 = " << x << endl;
    }

    return 0;
}
