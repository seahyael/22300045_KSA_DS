#include <iostream>
#include <string>
using namespace std;

int strNum = 3;
int num = 1;
string* str = new string[strNum];

string findPrefix(string str1, string str2){
    int size = 0;
    for(int i = 0; i<str1.length(); i++){
        if(str1[i] == str2[i]) size++;
        else break;
    }
    if(size == 0) return "?";
    num++;
    if(strNum == num) return str1.substr(0,size);
    return findPrefix(str[num],str1.substr(0,size));
}

int main(){
    string prefix;

    for(int i = 0; i<strNum; i++){
        cin >> str[i];
    }
    prefix = findPrefix(str[0],str[1]);
    cout << prefix;
    return 0;
}
