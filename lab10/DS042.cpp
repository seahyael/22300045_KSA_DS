#include <iostream>
#include <fstream>
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
    int pop();
    void empty();
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

int MyLinkedStack::pop(){
    int a;
    if(stacktop!=NULL){
        Node* popn;
        popn = stacktop;
        a = popn->data;
        stacktop = stacktop->next;
    }
    return a;
}

void MyLinkedStack::empty(){
    while(!isEmpty()){
        pop();
    }
}

int MyLinkedStack::getNodeCnt() const {
    int count = 0;
    Node* currentn;
    currentn = stacktop;
    while (currentn != NULL) {
        count++;
        currentn = currentn->next;
    }
    return count;
}

int main(){
    MyLinkedStack my;
    ifstream file("DS042.txt");
    string input, output;
    int out;
    bool error = false;

    while(file >> input){
            if(input == "\n") continue;
            if(input[0] == '#'){
                string num;
                num = input.substr(1,input.length());
                my.push(stoi(num));
                output += input + " ";
            }
            else if(input == "+"){
                if(my.getNodeCnt() < 2) error = true;
                out = my.pop() + my.pop();
                my.push(out);
                output += input + " ";
            }
            else if(input == "-"){
                if(my.getNodeCnt() < 2) error = true;
                out = my.pop() - my.pop();
                my.push(out);
                output += input + " ";
            }
            else if(input == "*"){
                if(my.getNodeCnt() < 2) error = true;
                out = my.pop() * my.pop();
                my.push(out);
                output += input + " ";
            }
            else if(input == "/"){
                if(my.getNodeCnt() < 2) error = true;
                int front = my.pop();
                int back = my.pop();
                if(front != 0) {
                    out = back / front;
                }
                else {
                    output += "/\n=> Division by 0\n";
                    continue;
                }
                my.push(out);
                output += input + " ";
            }
            else if(input == "="){
                out = my.pop();
                if(error){
                    output += "=\n=> Expression error !!!\n";
                    error = false;
                }
                else if(my.isEmpty())
                    output += input + " " + to_string(out) + "\n";
                else{
                    output += "=\n=> Too many operands !!!\n";
                }
                
            }
            else {
                output += input + " ";
                error = true;
            }
            if(input == "=") {
                my.empty();
            }
        }
    file.close();
    cout << output;

    return 0;
}
