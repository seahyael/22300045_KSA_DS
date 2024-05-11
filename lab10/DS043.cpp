#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
};

class MyLinkedStack{
private:
    Node* stacktop;
public:
    bool isEmpty() const;
    void push(const char& x);
    char pop();
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

void MyLinkedStack::push(const char& x){
    Node* newn;
    newn = new Node;
    newn->data = x;
    newn->next = stacktop;
    stacktop = newn;
}

char MyLinkedStack::pop(){
    char a;
    if(stacktop!=NULL){
        Node* popn;
        popn = stacktop;
        a = popn->data;
        stacktop = stacktop->next;
    }
    return a;
}

string MyLinkedStack::printAll(){
    Node*printn;
    printn = stacktop;
    string out;
    int count = 0;
    while(printn != NULL){
        out += printn->data;
        printn = printn->next;
    }
    return out;
}

void MyLinkedStack::empty(){
    while(!isEmpty()){
        pop();
    }
}

MyLinkedStack change(string s){
    MyLinkedStack n;
    for(int i = 0; i<s.length(); i++){
        n.push(s[i]);
    }
    return n;
}

int main(){
    MyLinkedStack my;
    string input;
    getline(cin, input);
    string out;

    while(input != "q"){
        for(int i = 0; i<input.length(); i++){
            if(input[i]>= 'a' && input[i] <= 'z'){
                my.push(input[i]);
            }
            else if(input[i]>= 'A' && input[i] <= 'Z'){
                my.push(input[i]);
            }
            else if(input[i] == '<'){
                if(!my.isEmpty()){
                    out += my.pop();
                }
            }
        }
        my = change(my.printAll());
        MyLinkedStack outc;
        outc = change(out);
        cout << "=> " << my.printAll() << outc.printAll() << endl;
        my.empty();
        outc.empty();
        out = ""; 
        getline(cin, input);
    }

    

    return 0;
}
