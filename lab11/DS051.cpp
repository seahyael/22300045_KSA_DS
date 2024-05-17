#include <iostream>
using namespace std;

typedef int element ;  


class MyCircularQueue{
public:
    int count;
    int maxsize;
    int front;
    int rear;
    element *list;
    void initialize();
    bool isempty() const;
    bool isfull() const;
    void enqueue(const element x);
    void dequeue();
    element Front();
    element Rear();
    MyCircularQueue(int size = 10){
        maxsize = size;
        front = 0;
        rear = 0;
        count = 0;
        list = new element(maxsize);
    }
    ~MyCircularQueue(){
        delete[] list;
    }
    void print();
    int size() const;
    void printDetail(MyCircularQueue m) const;
};

void MyCircularQueue::initialize(){
    front = 0;
    rear = 0;
    count = 0;
}

bool MyCircularQueue::isempty() const{
    return count == 0;
}

bool MyCircularQueue::isfull() const{
    return count == maxsize - 1;
}

void MyCircularQueue::enqueue(const element x){
    if(isfull()){
        cout << "=> Queue is full !" << endl;
    }
    else{
        rear ++;
        if(rear > 9) rear -= 10;
        list[rear] = x;
        count ++;
    }
}

void MyCircularQueue::dequeue(){
    if(!isempty()){
        front ++;
        if(front > 9) front -= 10;
        count --;
    }
    else {
        cout << "=> Queue is empty !" << endl;
    }
}

element MyCircularQueue::Front(){
    return front;
}

element MyCircularQueue::Rear(){
    return rear;
}

void MyCircularQueue::print(){
    for(int i = front+1; i<front + count + 1; i++){
        int index = i;
        if(index > 9) index -= 10;
        cout << "[" << list[index] << "]";
    }
}

int MyCircularQueue::size() const{
    return count;
}

void MyCircularQueue::printDetail(MyCircularQueue m) const{
    cout << "Size : " << m.size() << endl;
    cout << "Queue : ";
    m.print();
    cout << "\nindex : ";
    for(int i = front+1; i<front + count + 1; i++){
        int index = i;
        if(index > 9) index -= 10;
        cout << index << " ";
    }
    cout << "\nfront : " << m.Front() << ", rear : " << m.Rear() << endl; 
}

int main(){
    MyCircularQueue my;
    my.initialize();
    cout << "===== Dequeue x 1 =====" << endl;
    my.dequeue();
    my.printDetail(my);
    cout << "===== Enqueue x 7 (10 ~ 70) =====" << endl;
    for(int i = 0; i<7; i++){
        my.enqueue((i+1)*10);
    }
    my.printDetail(my);
    cout << "===== Dequeue x 3 =====" << endl;
    for(int i = 0; i<3; i++){
        my.dequeue();
    }
    my.printDetail(my);
    cout << "===== Enqueue x 6 (10 ~ 60) =====" << endl;
    for(int i = 0; i<6; i++){
        my.enqueue((i+1)*10);
    }
    my.printDetail(my);
    return 0;
}