#include <iostream>
#include <fstream>
using namespace std;

class MyStack{
private:
    int maxsize;
    int top;
    string *list;
public:
    void initalize();
    bool isEmpty() const;
    bool isFull() const;
    void push(const string &element);
    string* pop();
    MyStack(int size = 10){
        maxsize = size;
        top = -1;
        list = new string[maxsize];
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

void MyStack::push(const string &element){
    top++;
    list[top] = element;
}

string* MyStack::pop(){
    return &list[top--];
}

void MyStack::print(){
    for(int i = 0; i<top+1; i++){
        cout << list[i] << "\n";
    }
}

int main(){
    ifstream readFile("input.txt");
    double gpa, maxGpa = 0;
    string name;
    MyStack my(100);

    while(readFile >> gpa >> name){
        if(gpa > maxGpa){
            my.initalize();
            my.push(name);
            maxGpa = gpa;
        }
        else if(gpa == maxGpa){
            my.push(name);
        }
    }

    readFile.close();
    cout << "Top GPA: " << maxGpa << endl;
    my.print();
    return 0;
}