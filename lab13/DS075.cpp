#include <iostream>
using namespace std;

void print(int *arr, int n){
    for(int i = 0; i < n ; i++)
        cout << "[" << arr[i] << "] " ;
    cout << endl;
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
            b[k+t-i] = a[t];
}

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

int main(){
    int size;
    cin >> size;
    int *arr = new int(size);
    for(int i = 0; i<size; i++){
        cin >> arr[i];
    }
    print(arr, size);
    mergeSort(arr, size);
    return 0;
}