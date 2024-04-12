#include <iostream>
using namespace std;

struct compaire {
    string name;
    int price;
    string made;
};

string lower(string *str){
    for(int i = 0 ; i<(*str).length(); i++){
        if((*str)[i]>='A' && (*str)[i]<='Z'){
            (*str)[i] = (*str)[i] - 'A' + 'a';
        }
    }
    return *str;
}

bool isEqual(compaire a, compaire b){
    if (lower(&a.name) == lower(&b.name)){
        if(a.price == b.price){
            return true;
        }
    }
    return false;
}

int main(){
    compaire a;
    compaire b;
    cin >> a.name >> a.price >> a.made;
    cin >> b.name >> b.price >> b.made;
    if(isEqual(a,b) == true) cout << a.name << " is equal";
    else cout << a.name << " and " << b.name << " is not equal.";
    return 0;
}