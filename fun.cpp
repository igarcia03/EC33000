//#include "fun.h"
#include <iostream>
/* your includes here */

using namespace std;
int memory[100][100] = {0};
int result;

unsigned int fun(unsigned int x, unsigned int y) {
    
    
    if(memory[x][y] != 0){

        //cout << "This function has already been called, try again!" << endl;

        return memory[x][y];
    }

	if (x == 0){

        if(y == 0){
            if(memory[x][y] != 0){

                //cout << "This function has already been called, try again!" << endl;

                return memory[x][y];
            }
            result = 1;
            //cout << "Calculated value of x =" << x << " and y = " << y << " is: " << result << endl;
            memory[x][y] = result;

            return result; 
        }

        else {
            
            result = fun(1, y-1);
            //cout << "Calculated value of x =" << x << " and y = " << y << " is: " << result << endl;
            memory[x][y] = result;

            return result;
        }

    }

    else if(y == 0){
      
        result = x + 1;
        //cout << "Calculated value of x = " << x << " and y = " << y << " is: " << result << endl;
        memory[x][y] = result;

        return result;
    }

    else{
       
        result = fun(x-1, fun(x-1,y-1));
        //cout << "Calculated value of x = " << x << " and y = " << y << " is: " << result << endl;

        memory[x][y] = result;

        return result;
    }
    
     /* don't forget to change the return value */
}

/* your helper function here if you have any */
