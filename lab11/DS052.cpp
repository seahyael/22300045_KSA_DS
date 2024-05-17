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
        cout << "=> -1" << endl;
    }
}

element MyCircularQueue::Front(){
    return list[front+1];
}

element MyCircularQueue::Rear(){
    return list[rear];
}

void MyCircularQueue::print(){
    for(int i = front+1; i<front + count + 1; i++){
        int index = i;
        if(index > 9) index -= 10;
        cout << list[index];
        if(i!=front + count) cout << " => ";
    }
    cout << endl;
}

int MyCircularQueue::size() const{
    return count;
}

int main(){
    string input;
    int size;
    cin >> size;
    MyCircularQueue my(size);

    cin >> input;
    while(input != "q"){
        if(input == "en"){
            int num;
            cin >> num;
            my.enqueue(num);
        }
        else if(input == "front"){
            cout << "=> " << my.Front() << endl;
        }
        else if(input == "rear"){
            cout << "=> " << my.Rear() << endl;
        }
        else if(input == "size"){
            cout << "=> " << my.size() << endl;
        }
        else if(input == "de"){
            my.dequeue();
        }
        else if(input == "empty"){
            if(my.isempty()) cout << "=> 1" << endl;
            else cout << "=> 0" << endl;
        }
        else if(input == "print"){
            my.print();
        }
        cin >> input;
    }
    return 0;
}