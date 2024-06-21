#include <iostream>
using namespace std;

struct Node{
    int data;
    string name;
    Node *next;
};

class cont{
public:
    Node *start;
    Node *last;
    void addLast(int y);
    void addLast(int y, string x);
    void print();
    void printLinked();
    void printAll();
    void clearLinked();
    void init(int size);
    void selectionLinked();
    void insertionLinked();
    cont(){
        start = NULL;
        last = NULL;
    }~cont(){
    }
};

void swapNode(Node *x, Node *y)
{
    int temp = x->data;
    x->data = y->data;
    y->data = temp;
    string a = x->name;
    x->name = y->name;
    y->name = a;
}

void cont::addLast(int y)
{
    Node* newNode = new Node();
    newNode->data = y;
    if( start == NULL)
    {
        start = newNode;
        last = newNode;
    }
    else
    {
        last->next = newNode;
        last = newNode;
    }
}

void cont::addLast(int y, string x)
{
    Node* newNode = new Node();
    newNode->data = y;
    newNode->name = x;
    if( start == NULL)
    {
        start = newNode;
        last = newNode;
    }
    else
    {
        last->next = newNode;
        last = newNode;
    }
}

void cont::print()
{
    Node* temp = start;
    while(temp->next != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data <<endl;
}

void cont::printLinked()
{
    Node* temp = start;
    while(temp->next != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << temp->data <<endl;
}

void cont::printAll()
{
    Node* temp = start;
    int count = 0;
    while(temp->next != NULL)
    {
        count ++;
        cout << count << "> " << temp->data << " " << temp->name << endl;
        temp = temp->next;
    }
    count ++;
    cout << count << "> " << temp->data << " " << temp->name << endl;
}

void cont::clearLinked(){   
    Node* temp;
    while(start != NULL) {
        temp = start;
        start = start->next;
        free(temp);
    }
    start = NULL; last = NULL;
}

void cont::init(int size)
{
    int number;
    clearLinked();
    cout << "Enter numbers... ";
    for(int i = 0; i < size; i++ )
    {
        cin >> number;
        addLast(number);
    }
}

void cont::selectionLinked()
{
    Node* key;
    Node* temp;
    
    key = start;
    while(key != NULL)
    {
        temp = key->next;
        while(temp != NULL)
        {
            if(key->data > temp->data) swapNode(key, temp);           
            temp = temp->next;
        }
        key = key->next;
    }
}

void cont::insertionLinked()
{
    Node* key;
    Node* temp;
    
    key = start;
    while(key != NULL)
    {
        temp = start;
        while(temp != key->next)
        {
            if(key->data > temp->data) swapNode(key, temp);           
            temp = temp->next;
        }
        key = key->next;
    }
}