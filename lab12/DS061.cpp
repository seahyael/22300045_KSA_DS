#include <iostream>
using namespace std;
#include "Class.h"

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
  case 3: cout << "element at front: " << my.showfront() << endl;
          break;
  case 4: cout << "element at rear: " << my.showrear() << endl;
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