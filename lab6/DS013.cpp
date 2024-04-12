#include <iostream>
using namespace std;

struct Menu{
    string name;
    int price;
};

struct Cafe{
    string name;
    int num;
    Menu* menuList;
};

void addCafe(Cafe &r1){
    getline(cin, r1.name);//공백포함
    cin >> r1.num;
    r1.menuList = new Menu[r1.num];
}

void addMenu(Menu &m1){
    cin >> m1.name >> m1.price;
}

void displayMenus(Cafe &r1){
    cout << "===== " << r1.name << " =====\n";
    for(int i = 0; i<r1.num; i++){
        cout << r1.menuList[i].name << " " << r1.menuList[i].price << endl;
    }
    cout << "=================";
}

int main(){
    Cafe c;
    addCafe(c);
    for(int i = 0; i<c.num; i++){
        addMenu(c.menuList[i]);
    }
    displayMenus(c);
    delete[] c.menuList;
    return 0;
}