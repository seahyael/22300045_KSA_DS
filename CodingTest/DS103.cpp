#include <iostream>
#include "DS101.h"
using namespace std;

int main(){
    int n,k,i;

    cin >> n;
    cin >> k;
    while(k < 1 || k>n){
        cout << "Wrong number";
        cin >> k;}

    int* a = new int[n];
    for(i = 0; i<n; i++){
        cin >> a[i];
    }

    insertionSort(a, n);
    
    cout << a[k-1] << endl;
}