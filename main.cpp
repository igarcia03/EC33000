#include <iostream>
#include "fun.h"

using namespace std;

int main(){
    int int1, int2;
    float number = 0;
    while (number != 100000){
        cout << "Please enter values" << endl;
    
        cin >> int1;
        cin >> int2;

        number = fun(int1, int2);
        if(number == 0){
            continue;
        }
        else{
            cout << "the result is " << number << endl;
        }
    }

    return 0;
}