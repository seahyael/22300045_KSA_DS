#include <iostream>
using namespace std;

void print(int *arr, int n){
    for(int i = 0; i < n ; i++)
        cout << "[" << arr[i] << "] " ;
    cout << endl;
}

void quickSort(int *arr, int s, int n, int size){
    if(s+1>=n) return;
    int i = s;
    int j = n-1;
    int pivot = arr[j];

    do{
        while(arr[i] <= pivot && i < n-1) {
            i++;
        }
        while(arr[j] >= pivot){
            j--;
        }
        if(i<j)
        swap(arr[i],arr[j]);
    }while(i<j);

    swap(arr[i], arr[n-1]);
    
#ifdef DEBUGMODE
    print(arr, size);
#endif
    
    quickSort(arr, s, i,size);
    quickSort(arr, i+1, n,size);
}

int main(){
    int size;
    cin >> size;
    int *arr = new int(size);
    for(int i = 0; i<size; i++){
        cin >> arr[i];
    }
    print(arr, size);
    quickSort(arr, 0, size, size);
    return 0;
}