#include <stack>
#include <iostream>
using namespace std;

string printAll(stack <char> my){
    string out;
    int count = 0;
    while(my.size() != 0){
        out += my.top();
        my.pop();
    }
    return out;
}

stack <char> empty(stack <char> my){
    while(my.size()!=0){
        my.pop();
    }
    return my;
}

stack <char> change(string s){
    stack <char> n;
    for(int i = 0; i<s.length(); i++){
        n.push(s[i]);
    }
    return n;
}

int main(){
    stack <char> my;
    string input;
    getline(cin, input);
    string out;

    while(input != "q"){
        for(int i = 0; i<input.length(); i++){
            if(input[i]>= 'a' && input[i] <= 'z'){
                my.push(input[i]);
            }
            else if(input[i]>= 'A' && input[i] <= 'Z'){
                my.push(input[i]);
            }
            else if(input[i] == '<'){
                if(my.size() != 0){
                    out += my.top();
                    my.pop();
                }
            }
        }
        my = change(printAll(my));
        stack <char> outc;
        outc = change(out);
        cout << "=> " << printAll(my) << printAll(outc) << endl;
        my = empty(my);
        outc = empty(outc);
        out = ""; 
        getline(cin, input);
    }

    return 0;
}
