#include <iostream>
#include "DS076.h"
using namespace std;

int main(){
    int num, count;
    cout << "1.selection 2.insertion 3.bubble 4.quick 5.merge 6.exit > ";
    cin >> num;
    while(num!=6){
        cout <<"Enter count: ";
        cin >> count;
        int *arr = new int(count);
        cout << "Enter numbers : ";
        for(int i = 0; i<count; i++){
            cin >> arr[i];
        }
        switch (num)
        {
        case 1:
            cout << "==== selction sort ====" << endl;
            print(arr, count);
            selectionSort(arr, count);
            break;
        case 2:
            cout << "==== insertion sort ====" << endl;
            print(arr, count);
            insertionSort(arr,count);
            break;
        case 4:
            cout << "==== quick sort ====" << endl;
            print(arr, count);
            quickSort(arr, 0, count, count);
            break;
        case 5:
            cout << "==== merge sort ====" << endl;
            print(arr, count);
            mergeSort(arr, count);
            break;
        case 3:
            int *arr2 = new int[count];
            for(int i = 0; i<count; i++){
            arr2[i] = arr[i];
            }
            cout << "==== asending order ====" << endl;
            print(arr, count);
            ascendingOrderSort(arr, count);
            cout << "==== desending order ====" << endl;
            print(arr2, count);
            descendingOrderSort(arr2, count);
            break;
        }
        cout << "1.selection 2.insertion 3.bubble 4.quick 5.merge 6.exit > ";
        cin >> num;
    }
    cout << "bye!" << endl;
    return 0;
}
