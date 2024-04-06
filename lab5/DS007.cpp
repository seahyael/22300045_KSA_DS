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
            output += 1;
            break;
        case 'V':
            output += 5;
            break;
        case 'X':
            output += 10;
            break;
        case 'L':
            output += 50;
            break;
        case 'C':
            output += 100;
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