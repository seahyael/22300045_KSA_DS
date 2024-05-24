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
    void display(int round, int winner);
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
void Queue::display(int round, int winner)
{
 cout<<"Round"<<round<<" - ";
 if(winner == 0) cout << "Draw!" <<endl;
 else cout << "P"<<winner<<" win!"<<endl;
}

//Main Function
int main()
{
 int count, num, winner;
 int player1 = 0, player2 = 0;
 int battlenum1, battlenum2;
 Queue d1, d2;
 cin >> count;
 for(int i = 0; i<count; i++){
    cin >> num;
    d1.enqueue(num);
 }
 for(int i = 0; i<count; i++){
    cin >> num;
    d2.enqueue(num);
 }

 for(int i = 0; i<count; i++){
    if(i == 0){
        battlenum1 = d1.dequeue();
        battlenum2 = d2.dequeue();
    }
    else{
        if(winner == 1){
            battlenum1 = (battlenum1 - battlenum2 - 1) + d1.dequeue();
            battlenum2 = d2.dequeue();
        }
        else if(winner == 2){
            battlenum2 = (battlenum2 - battlenum1 - 1) + d2.dequeue();
            battlenum1 = d1.dequeue();
        }
        else{
            battlenum1 = d1.dequeue();
            battlenum2 = d2.dequeue();
        }
    }
    if(battlenum1 > battlenum2) {
            winner = 1;
            player1++;}
    else if(battlenum1 < battlenum2) {
            winner = 2;
            player2++;}
    else winner = 0;
    
    d1.display(i+1, winner);
 }
 
 cout << "Final - ";
 if(player1 > player2) cout << "P1 win!" << endl;
 else if(player1 < player2) cout << "P2 win!" << endl;
 else cout << "Draw!" << endl;

 return 0;
}