#include <iostream>
using namespace std;

int main(){
    string input;
    int output = 0;

    cin >> input;

    for(int i = 0; i<input.length(); i++){
        switch (input[i])
        {
        case 'I':
            if(input[i+1] == 'V' || input[i+1] == 'X') output -= 1;
            else output += 1;
            break;
        case 'V':
            output += 5;
            break;
        case 'X':
            if(input[i+1] == 'L' || input[i+1] == 'C') output -= 10;
            else output += 10;
            break;
        case 'L':
            output += 50;
            break;
        case 'C':
            if(input[i+1] == 'D' || input[i+1] == 'M') output -= 100;
            else output += 100;
            break;
        case 'D':
            output += 500;
            break;
        case 'M':
            output += 1000;
            break;
        }
    }

    cout << output;
}