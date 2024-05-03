#include <iostream>
#include <string>
using namespace std;

class MyStack{
private:
    int maxsize;
    int top;
    int *list;
public:
    void initalize();
    bool isEmpty() const;
    bool isFull() const;
    void push(const int &element);
    int* pop();
    MyStack(int size = 10){
        maxsize = size;
        top = -1;
        list = new int[maxsize];
    }
    ~MyStack(){
        delete[] list;
    }
    void print();
};

void MyStack::initalize(){
    top = -1;
}

bool MyStack::isEmpty() const{
    return top == -1;
}

bool MyStack::isFull() const{
    return top == maxsize - 1;
}

void MyStack::push(const int &element){
    top++;
    list[top] = element;
}

int* MyStack::pop(){
    return &list[top--];
}

void MyStack::print(){
    for(int i = 0; i<top+1; i++){
        cout << list[i] << "\n";
    }
}

int main(){
    int size;
    cin >> size;
    MyStack my(size);

    string input;
    cin >> input;

    while(input != "print"){
        if(input == "push"){
            int elem;
            cin >> elem;
            my.push(elem);
        }
        else {
            my.pop();
        }
        cin >> input;
    }

    my.print();

    return 0;
}