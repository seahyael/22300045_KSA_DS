#include <iostream>
using namespace std;
#define _DEBUG

int size = 0;

void printHeap(int arr[], int now){
    int parent = (now - 1) / 2;
    while (now > 0 && arr[parent] < arr[now])
    {
        swap(arr[now], arr[parent]);
        now = parent;
        parent = (now - 1) / 2;
    }
}


void maxHeapify(int arr[], int rooti)
{   

    int leftChild = rooti * 2 + 1;
	int rightChild = rooti * 2 + 2;
	int updateIndex = rooti;

	if (leftChild < size && arr[updateIndex] < arr[leftChild]) {
		updateIndex = leftChild;
	}
	
	if (rightChild < size && arr[updateIndex] < arr[rightChild]) {
		updateIndex = rightChild;
	} 

	if (rooti != updateIndex) {
		swap(arr[rooti], arr[updateIndex]);
        maxHeapify(arr, updateIndex);
	}
}
void printArray(int* arr, int size)
{
    printHeap(arr,size-1);
    cout << "==> Heap : ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void insertKey(int arr[], int N, int value)
{
    if (size == N - 1)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    arr[size] = value;
    size++;

#ifdef _DEBUG
    printArray(arr, size);
#endif  
}

void deleteKey(int arr[], int N){
    if (size == 0)
    {
        cout << "\nCould not deleteKey\n";
        return;
    }
#ifdef _DEBUG
    cout << "=> Delete " << arr[0] << endl;
#endif    
    

    for(int i = 0; i<size; i++){
        arr[i] = arr[i+1];
    }

    size--;

    maxHeapify(arr,0);

    
#ifdef _DEBUG
    printArray(arr, size);
#endif     
}

int main()
{
    int arr[20];
    int menu;
    while(1){        
        cout << "1. insert 2.delete 3.print 4.quit > " ;
        cin >> menu;
        if(menu == 1){
            int value;
            cout << "new value? ";
            cin >> value;
            insertKey(arr, 20, value);
        }
        else if(menu == 2){            
            deleteKey(arr, 20);
        }
        else if(menu == 3){
            printArray(arr, size);
        }
        else break;
    }
    cout << "Bye!" << endl;
    
    return 0;
}