#include <iostream>
#include <string>
using namespace std;

void ltrim(string &str){
    int space = str.find_first_not_of(" \t");
    str.erase(0, space);
}

void rtrim(string &str){
    int space = str.find_last_not_of(" \t");
    str.erase(space+1);
}

int count(string str){
    int lastWord = str.find_last_of(" ");
    return str.length() - lastWord -1;
}

int main(){
    string str;
    getline(cin, str);
    ltrim(str);
    rtrim(str);
    int out = count(str);
    cout << out;
    return 0;
}