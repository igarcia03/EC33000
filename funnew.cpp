#include "fun.h"
#include <iostream>
/* your includes here */

using namespace std;
int memory[100][100] = {0};
int result;
unsigned int fun(unsigned int x, unsigned int y) {

    for(int i = 0 ; i < 100; i++){
        for(int j = 0; j < 100; j++){
            int value = memory[j][i];
            cout << value << endl;
        }
    }
    
    if(memory[x][y] != 0){

        cout << "This function has already been called, try again!" << endl;

        return 0;

    }
    
    
    /*if(memory[x][y] == 2){

        cout << "This function has already been called, try again!" << endl;

        return 0;
    }*/

	if (x == 0){
        if(y == 0){
            cout << "1" << endl;
            result = 1;
            return result; 
        }
        else {
            cout << "2" << endl;
            result = fun(1, y-1);
            return result;
        }
    }
    else if(y == 0){
        result = x + 1;
        return result;
    }

    else{
        result = fun(x-1, fun(x-1,y-1));
        return result;   
    }
    
    memory[x][y] = result;

    return memory[x][y];

     /* don't forget to change the return value */
}