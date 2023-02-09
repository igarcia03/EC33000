#include "balancedGroups.h"
#include <iostream>


// your includes here
void sortOrder(std::vector<int> &birthdays, int sizemin, int sizemax);

using namespace std;
int main(){
    vector<int> birthdays;
    int input;
    cout << "enter as many birthdays as you wish, input 0 or greater than 31 to stop inputs" << endl;
    cin >> input;
    while(input > 0 && input <= 31){
        birthdays.push_back(input);
        cout << "enter as many birthdays as you wish, input 0 or greater than 31 to stop inputs" << endl;
        cin >> input;   
    }

    for(int i = 0; i < birthdays.size(); i++){
        cout << birthdays[i] << " ";
    }
    cout << endl;
    int sizemin = 0;
    int sizemax = birthdays.size();
    sortOrder(birthdays, sizemin, sizemax);

    for(int i = 0; i < birthdays.size(); i++){
        cout << birthdays[i] << " ";
    }

    balancedGroups(birthdays);
}

Assignment balancedGroups(std::vector<int> const &birthdays) {
    vector<int> GroupA;
    vector<int> GroupB;

    int sumA = 0;
    int sumB = 0;

    GroupA.push_back(birthdays[0]);
    //GroupA[0] = birthdays[0];
    sumA = sumA + GroupA[0];
    GroupB.push_back(birthdays[1]);
    sumB = sumB + GroupA[0];
    //cout << "THIS WORKS" << endl;
    for(int i = 1; i < birthdays.size(); i++){
        if(GroupA[i] > GroupB[i]){
            GroupB.push_back(birthdays[i+1]);
            //GroupB[i] = birthdays[i];
            sumB = sumB + GroupB[i];
        }
        else if(GroupA[i] < GroupB[i]){
            GroupA.push_back(birthdays[i+1]);
            //GroupA[i] = birthdays[i];
            sumA = sumA + GroupA[i];
        }
        
    }

	return Assignment(0, {}, {}); // Don't forget to change this
}

void sortOrder(std::vector<int> &birthdays, int sizemin, int sizemax){
    for(int i = sizemin; i < sizemax; i++){
        for(int j = sizemin; j < sizemax-i-1; j++){
            if(birthdays[j] < birthdays[j+1]){
                int variable = birthdays[j];    
                birthdays[j] = birthdays[j+1];
                birthdays[j+1] = variable;
            }
        }
    }
    return;
}

/* your helper function here if you have any */

//divide and conquer algorithm