#include <iostream>
#include <fstream>
using namespace std;

typedef string element ;  


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
        list = new element[maxsize];
    }
    ~MyCircularQueue(){
        delete[] list;
    }
    void print(double max);
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

void MyCircularQueue::print(double max){
    for(int i = front+1; i<front + count + 1; i++){
        int index = i;
        if(index > 9) index -= 10;
        cout << list[index] << " " << max << endl;
    }
    cout << endl;
}

int MyCircularQueue::size() const{
    return count;
}

int main(){
    double inputs;
    string inputn;
    double max = 0;
    ifstream file("DS053.txt");
    MyCircularQueue my(20);
    while(file >> inputs){
        file >> inputn;
        if(inputs > max){
            max = inputs;
            my.enqueue(inputn);
        }
    }

    cout << "Hightest GPA = " << max << endl;
    my.print(max);

    file.close();
    return 0;
}