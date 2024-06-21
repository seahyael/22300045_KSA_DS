#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack <char> my;
    string input;
    cin >> input;

    for(int i = 0; i<input.length(); i++){
        if(!my.empty() && my.top() == input[i]){
            my.pop();
        }
        else{
            my.push(input[i]);
        }
    }

    string output;
    while (!my.empty()) {
        output = my.top() + output;
        my.pop();
    }

    cout << output << endl;
    return 0;
}