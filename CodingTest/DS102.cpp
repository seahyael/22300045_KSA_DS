#include <iostream>
#include "DS101.h"
using namespace std;

int main(){
    int n,k,i;
    cin >> n;
    while(n < 1 || n>500){
        cout << "Wrong number";
        cin >> n;}

    cin >> k;
    while(k < 1 || k>n){
        cout << "Wrong number";
        cin >> k;}

    int* a = new int[n];
    int* b = new int[n];
    for(i = 0; i<n; i++){
        cin >> a[i];
        while(a[i] < 1 || a[i] > 100000){
            cout << "Wrong number";
            cin >> a[i];
        }
    }
    for(i = 0; i<n; i++){
        cin >> b[i];
        while(b[i] < 1 || b[i] > 100000){
            cout << "Wrong number";
            cin >> b[i];
        }
    }

    insertionSort(b, n);
    selectionSort(a, n);

    int count = 0;
    for(i = 0; i<k; i++){
        if(a[i] < b[i]){
            a[i] = b[i];
            count ++;
        }
    }

    int total = 0;
    for(i = 0; i<n; i++){
        total += a[i];
    }
    
    cout << count << " " << total << endl;
}