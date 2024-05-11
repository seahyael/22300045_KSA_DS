#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class MyLinkedStack{
private:
    Node* stacktop;
public:
    void initialize();
    bool isEmpty() const;
    void push(const int& x);
    void pop();
    int peek() const;
    int getNodeCnt() const;
    MyLinkedStack(){
        stacktop = NULL;
    }
    ~MyLinkedStack(){
    }
    string printAll();
};

bool MyLinkedStack::isEmpty() const{
    return stacktop == NULL;
}

void MyLinkedStack::push(const int& x){
    Node* newn;
    newn = new Node;
    newn->data = x;
    newn->next = stacktop;
    stacktop = newn;
}

void MyLinkedStack::pop(){
    if(stacktop!=NULL){
        Node* popn;
        popn = stacktop;
        stacktop = stacktop->next;
    }
}

int MyLinkedStack::peek() const{
    if(stacktop!=NULL){
        return stacktop->data;
    }
    return -1;
}

string MyLinkedStack::printAll(){
    Node*printn;
    printn = stacktop;
    string out;
    int count = 0;
    while(printn != NULL){
        if(count > 0)
            out += " -> ";
        out += to_string(printn->data);
        count++;
        printn = printn->next;
    }
    out += " (";
    out += to_string(count);
    out += " nodes)\n";
    return out;
}

int main(){
    MyLinkedStack my;
    string input,output;
    cin >> input;

    while(input != "q"){
        if(input == "push"){
            int num;
            cin >> num;
            my.push(num);
            fflush(stdin);
        }
        else if(input == "clear"){
            while(!my.isEmpty()){
                my.pop();
            }
            fflush(stdin);
        }
        else if(input == "pop"){
            my.pop();
            fflush(stdin);
        }
        else if(input == "peek"){
            output += to_string(my.peek()) + "\n";
            fflush(stdin);
        }
        else if(input == "print"){
            if(my.isEmpty())
                output += "Stack is empty\n";
            else {
                output += my.printAll();
            }
            fflush(stdin);
        }
        cin >> input;
    }

    cout << output << "Bye!";

    return 0;
}
