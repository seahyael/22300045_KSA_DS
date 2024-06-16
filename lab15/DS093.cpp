#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool lengthSame(int length, int compare){
    return length == compare;
}

int main(){
    vector <string> my, myout;
    string input;
    vector <string> :: iterator output;
    int size;
    int max = 0;

    cin >> size;
    for(int i = 0; i<size; i++){
        cin >> input;
        my.push_back(input);
        if(input.length() > max){
            max = input.length();
        }
    }

    cout << "=====output====="<< endl;
    for(int j = 0; j<max; j++){
        output = my.begin();
        while(output != my.end()){
            if(output->length() == j+1){
                myout.push_back(*output);
                my.erase(output);
            }
            else output++;
        }
        sort(myout.begin(), myout.end());
        for(int k = 0; k<myout.size(); k++){
            if(myout[k] != myout[k+1]){
                cout << myout[k] << endl;
            }
        }
        myout.clear();
    }
    

    return 0;
}