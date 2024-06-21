#include <iostream>
using namespace std;

class MinHeap {
public:
    int arr[30];
    int length;
    MinHeap(){
        length = 0;
    }
    ~MinHeap(){
    }
    void insertKey(int value);
    int deleteKey();
    int peek();
    int size();
    bool isEmpty();
    void minHeapifyUp(int index);
    void minHeapifyDown(int root = 0);
    void printHeap();
};

void MinHeap::insertKey(int value){
    arr[length] = value;
    minHeapifyUp(size());
    length ++;
}

int MinHeap::deleteKey(){
    if(isEmpty()) return -1;
    int min = peek();
    arr[0] = arr[length-1];
    length--;
    minHeapifyDown();
    return min;
}

int MinHeap::peek(){
    return arr[0];
}

int MinHeap::size(){
    return length;
}

bool MinHeap::isEmpty(){
    return size() == 0;
}

void MinHeap::minHeapifyUp(int index){
    int parent = (index - 1) / 2;
    if (index > 0 && arr[index] < arr[parent]) {
        swap(arr[index], arr[parent]);
        minHeapifyUp(parent);
    }
}

void MinHeap::minHeapifyDown(int root){
    int leftChild = root * 2 + 1;
	int rightChild = root * 2 + 2;
	int updateIndex = root;

	if (leftChild < size() && arr[updateIndex] > arr[leftChild]) {
		updateIndex = leftChild;
	}
	
	if (rightChild < size() && arr[updateIndex] > arr[rightChild]) {
		updateIndex = rightChild;
	} 

	if (root != updateIndex) {
		swap(arr[root], arr[updateIndex]);
        minHeapifyDown(updateIndex);
	}
}

void MinHeap::printHeap(){
    cout << "minheap => ";
    for(int i = 0; i<size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    MinHeap my;
    int num;
    int size;
    cout << "1. Array to minHeap 2. insert 3. delete 4. print 0. quit > ";
    cin >> num;

    while(num != 0){
        switch (num)
        {
        case 1:
            cin >> size;
            for(int i = 0; i<size; i++){
                cin >> my.arr[i];
                my.length++;
                my.minHeapifyUp(i);
            }
            my.printHeap();
            break;
        case 2:
            cin >> size;
            my.insertKey(size);
            my.printHeap();
            break;
        case 3:
            cout << "min value : " << my.deleteKey() << endl;
            my.printHeap();
            break;
        case 4:
            for(int i = 0; i<my.size(); i++){
                cout << my.arr[i] << " ";
            }
            cout << endl;
            break;
        }
        cout << "1. Array to minHeap 2. insert 3. delete 4. print 0. quit > ";
        cin >> num;
    }
    cout << "bye!" << endl;
}