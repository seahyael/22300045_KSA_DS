#include <iostream>
using namespace std;

class Product{
private:
    string name;
    int price;
    int discount;
    string brand;
    string amount;
    int calculPrice(struct Product* pl[],int size);
public:
    void input(struct Product* pl[],int size);
    void output(struct Product* pl[],int size);
};


void Product::input(struct Product* pl[], int size) {
    pl[size] = new Product();
    cin.ignore();
    getline(cin, pl[size]->name);
    cin >> pl[size]->price >> pl[size]->discount >> pl[size]->amount;
    cin.ignore();
    getline(cin, pl[size]->brand);
}


int Product::calculPrice(struct Product* pl[],int size){
    int newPrice;
    newPrice = pl[size]->price * (100-pl[size]->discount)/100;
    return newPrice;
}

void Product::output(struct Product* pl[],int size){
    for(int i = 0; i<size; i++){
        cout << calculPrice(pl, i) << " (-" << pl[i]->discount << "%) ";
        cout << pl[i]->name << " " << pl[i]->amount << " " << pl[i]->brand << endl;
    }
}

int main(){
    struct Product* plist[100];
    Product p;
    int input;
    int size = 0;
    cout << "1. Add 2.List 3.Quit > ";
    cin >> input;
    while(input != 3){
        if(input == 1){
            p.input(plist,size);
            size ++;
        }
        else if(input == 2)
            p.output(plist, size);
        cout << "1. Add 2.List 3.Quit > ";
        cin >> input;
    }
    return 0;
}