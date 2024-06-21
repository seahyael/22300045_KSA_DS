#include <iostream>
using namespace std;

void print(int *arr, int n){
    for(int i = 0; i < n ; i++)
        cout << "[" << arr[i] << "] " ;
    cout << endl;
}

void selectionSort(int *arr, int n){
    int min_i = 0;

    for(int i = 0; i < n-1; i++){
        min_i = i;
        for(int j = i+1; j < n; j++){
            if(arr[min_i] > arr[j]) min_i = j;
        }
        if(i != min_i) swap(arr[i], arr[min_i]);
#ifdef DEBUGMODE
    print(arr, n);
#endif
    }
}

void insertionSort(int *arr, int n){
    int k;
    for(int i = 1; i < n; i++){
        k = i-1;
        while(k >= 0 && arr[k] < arr[k+1]){
            swap(arr[k], arr[k+1]);
            k--;
        }
#ifdef DEBUGMODE
    print(arr, n);
#endif
    }
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

void merge(int *a, int *b, int n1, int n2, int n3, int n4){
    int i, j, k, t;
    i = n1;
    j = n3;
    k = n1;
    while ((i <= n2) && (j <= n4)){
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    if (i > n2)
        for (t = j; t <= n4; t++)
            b[t] = a[t];
    else
        for (t = i; t <= n2; t++)
            b[k+t-i] = a[t];}

void merge_pass(int *a, int* b, int n, int s){
    int i, j;
    for (i = 0; i < (n - 2 * s + 1); i += 2 * s)
        merge(a, b, i, i + s - 1, i + s, i + 2 * s - 1);
    if (i + s  <= n)
        merge(a, b, i, i + s - 1, i + s, n);
    else
        for (j=i; j<= n; j++)
            b[j] = a[j];
}

void mergeSort(int *arr, int n){
    int s = 1;
    int b[n];
        while (s < n) {
        merge_pass(arr, b, n-1, s);
#ifdef DEBUGMODE
    print(b, n);
#endif
        s *= 2;

        merge_pass(b, arr, n-1, s);
#ifdef DEBUGMODE
    print(arr, n);
#endif
        s *= 2;

}
}