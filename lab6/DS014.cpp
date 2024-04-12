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

int main(){
    string str;
    getline(cin, str);
    while(str[0] == ' ' || str[0] == '\t'){ltrim(str);}
    while(str[str.length()] == ' ' || str[str.length()] == '\t'){rtrim(str);}
    cout << str;
    return 0;
}