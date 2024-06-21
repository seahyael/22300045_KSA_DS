#include <iostream>
#include "DS104.h"
using namespace std;

int main()
{
    cont my;
    int num;
    cin >> num;

    int *score = new int[num];
    string *name = new string[num];
    for(int i = 0; i<num; i++){
        cin >> score[i] >> name[i];
        my.addLast(score[i],name[i]);
    }

    my.insertionLinked();
    my.printAll();
}
