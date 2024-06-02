#include <iostream>
using namespace std;

void print(int *arr, int n){
    for(int i = 0; i < n ; i++)
        cout << "[" << arr[i] << "] " ;
    cout << endl;
}

void insertionSort(int *arr, int n){
    int k;
    for(int i = 1; i < n; i++){
        k = i-1;
        while(k >= 0 && arr[k] > arr[k+1]){
            swap(arr[k], arr[k+1]);
            k--;
        }
#ifdef DEBUGMODE
    print(arr, n);
#endif
    }
}

int main(){
    int size;
    cin >> size;
    int *arr = new int(size);
    for(int i = 0; i<size; i++){
        cin >> arr[i];
    }
    print(arr, size);
    insertionSort(arr, size);
    return 0;
}