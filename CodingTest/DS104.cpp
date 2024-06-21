#include <iostream>
#include "DS104.h"
using namespace std;

int main()
{
    int choice;
    while(1)
    {   
        cont my;
        cout << endl << "How many numbers do you want to create (0:exit) ... ";
        cin >> choice;
        if(choice == 0) break;
        my.init(choice);
        my.selectionLinked();
        my.printLinked();
    }

}