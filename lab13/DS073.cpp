#include <iostream>
using namespace std;

void print(int *arr, int n){
    for(int i = 0; i < n ; i++)
        cout << "[" << arr[i] << "] " ;
    cout << endl;
}

void ascendingOrderSort(int *arr, int n){
    int index;
    for(int j = n-1; j>0; j--){
        for(int i = 0; i < j; i++){
            if(arr[i] >= arr[i+1]) {
                index = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = index;
            }
        }
#ifdef DEBUGMODE
    print(arr, n);
#endif
    }
}

void descendingOrderSort(int *arr, int n){
    int index;
    for(int j = n-1; j>0; j--){
        for(int i = 0; i < j; i++){
            if(arr[i] <= arr[i+1]) {
                index = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = index;
            }
        }
#ifdef DEBUGMODE
    print(arr, n);
#endif
    }
}

int main(){
    int size;
    cin >> size;
    int *arr1 = new int(size);
    int *arr2 = new int(size);
    for(int i = 0; i<size; i++){
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }
    cout << "=== asending order ===" << endl;
    print(arr1, size);
    ascendingOrderSort(arr1, size);
    cout << "=== desending order ===" << endl;
    print(arr2, size);
    descendingOrderSort(arr2, size);
    return 0;
}