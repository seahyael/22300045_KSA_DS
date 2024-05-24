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
    void showfront();
    void showrear();
    Queue(){
        front = NULL;
        rear = NULL;
    }
    ~Queue(){
    }
    void displayQueue();
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
void Queue::showfront( )
{
 if( isempty())
 cout<<"Queue is empty\n";
 else
 cout<<"element at front: "<<front->data<<endl;
}

//function to show the element at rear
void Queue::showrear( )
{
 if( isempty())
 cout<<"Queue is empty\n";
 else
 cout<<"element at rear: "<<rear->data<<endl;
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

//Main Function
int main()
{
 int choice, flag=1, value;
 Queue my;
 while( flag == 1)
 {
  cout<<"\n1.enqueue 2.dequeue 3.showfront 4.showrear 5.displayQueue 6.exit > ";
  cin>>choice;
  switch (choice)
  {
  case 1: cout<<"Enter Value: ";
          cin>>value;
          my.enqueue(value);
          break;
  case 2: my.dequeue();
          break;
  case 3: my.showfront();
          break;
  case 4: my.showrear();
          break;
  case 5: my.displayQueue();
          break;
  case 6: flag = 0;
          cout << "bye!";
          break;
  }
 }

 return 0;
}