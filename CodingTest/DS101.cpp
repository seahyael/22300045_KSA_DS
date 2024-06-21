#include <iostream>
#include "DS101.h"
using namespace std;

int main(){
    int num;
    cin >> num;
    while(num < 1 || num>500){
        cout << "Wrong number";
        cin >> num;}
    int* a = new int(num);
    for(int i = 0; i<num; i++){
        cin >> a[i];
        while(a[i] < 1 || a[i] > 100000){
            cout << "Wrong number";
            cin >> a[i];
        }
    }

    insertionSort(a, num);

    for(int i = 0; i<num; i++){
        cout << a[i] << " ";
    }
}