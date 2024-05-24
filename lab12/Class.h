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
    void dequeue();
    int showfront();
    int showrear();
    Queue(){
        front = NULL;
        rear = NULL;
    }
    ~Queue(){
    }
    void displayQueue();
    void displayQueue(int count);
    void displayQueue(int round, int winner);
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
void Queue::dequeue ( )
{
 if( isempty() )
 cout<<"Queue is empty\n";
 else
 //only one element/node in queue.
 if( front == rear)
 {
  free(front);
  front = rear = NULL;
 }
 else
 {
  Node *ptr = front;
  front = front->link;
  free(ptr);
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
void Queue::displayQueue()
{
 if (isempty())
  cout<<"Queue is empty\n";
 else
 {
  Node *ptr = front;
  while( ptr !=NULL)
  {
   cout<<ptr->data;
   if(ptr->link != NULL ) cout<<" -> ";
   else cout << endl;
   ptr= ptr->link;
  }
 }
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

//function to display queue
void Queue::displayQueue(int round, int winner)
{
 cout<<"Round"<<round<<" - ";
 if(winner == 0) cout << "Draw!" <<endl;
 else cout << "P"<<winner<<" win!"<<endl;
}