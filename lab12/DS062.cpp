#include <iostream>
using namespace std;
#include "Class.h"


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
                fibonacci = my.showfront();
                my.dequeue();
                fibonacci += my.showfront();
                my.enqueue(fibonacci);
                my.displayQueue(i+1);
                break;
        }
    }

    cout << "=> fibonacci(" << n << ") : " << my.showrear();

    return 0;
}