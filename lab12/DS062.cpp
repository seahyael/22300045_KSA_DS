#include <iostream>
using namespace std;

// Structure of Node.
struct Node{
int data;
Node *link;
};

class Queue{
public:
    Node *front;
    Node *rear;
    bool isempty();
    void enqueue(int x);
    int dequeue();
    int showfront();
    int showrear();
    Queue(){
        front = NULL;
        rear = NULL;
    }
    ~Queue(){
    }
    void displayQueue(int count);
};

//Function to check if queue is empty or not
bool Queue::isempty() 
{
 if(front == NULL && rear == NULL)
 return true;
 else
 return false;
}

//function to enter elements in queue
void Queue::enqueue ( int value )
{
 Node *ptr = new Node();
 ptr->data= value;
 ptr->link = NULL;

 //If inserting the first element/node
 if( front == NULL )
 {
  front = ptr;
  rear = ptr;
 }
 else
 {
  rear ->link = ptr;
  rear = ptr;
 }
}

//function to delete/remove element from queue
int Queue::dequeue ( )
{
 int out;
 if( isempty() ){
 cout<<"Queue is empty\n";
 return -1;}
 else
 //only one element/node in queue.
 if( front == rear)
 {
    out = showfront();
  free(front);
  front = rear = NULL;
  return out;
 }
 else
 {
    out = showfront();
  Node *ptr = front;
  front = front->link;
  free(ptr);
  return out;
 }
}

//function to show the element at front
int Queue::showfront( )
{
 if( isempty()){
 cout<<"Queue is empty\n";
 return -1;}
 else
 return front->data;
}

//function to show the element at rear
int Queue::showrear( )
{
 if( isempty()){
 cout<<"Queue is empty\n";
 return -1;}
 else
 return rear->data;
}

//function to display queue
void Queue::displayQueue(int count)
{
 cout << count;
 switch(count){
    case 1: 
        cout<<"st";
        break;
    case 2:
        cout<<"nd";
        break;
    case 3:
        cout<<"rd";
        break;
    default:
        cout<<"th";
        break;
 }
 cout << " : " << showrear() << endl;
}

//Main Function
int main()
{
    Queue my;
    int n, fibonacci;
    cin>>n;

    for(int i = 0; i<n; i++){
        switch(i+1){
            case 1:
                my.enqueue(1);
                my.displayQueue(i+1);
                break;
            case 2:
                my.enqueue(1);
                my.displayQueue(i+1);
                break;
            default:
                fibonacci = my.dequeue() + my.showfront();
                my.enqueue(fibonacci);
                my.displayQueue(i+1);
                break;
        }
    }

    cout << "=> fibonacci(" << n << ") : " << my.showrear();

    return 0;
}