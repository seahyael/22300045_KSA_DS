#include <iostream>
#include "DS104.h"
using namespace std;

int main()
{
    cont mya;
    cont myb;
    int numa, numb;
    cin >> numa >> numb;

    int *scorea = new int[numa];
    int *scoreb = new int[numb];
    for(int i = 0; i<numa; i++){
        cin >> scorea[i];
        mya.addLast(scorea[i]);
    }
    for(int i = 0; i<numb; i++){
        cin >> scoreb[i];
        myb.addLast(scoreb[i]);
    }
    mya.insertionLinked();
    myb.insertionLinked();

    cont my;
    Node* a = mya.start;
    Node* b = myb.start;
    while(a != NULL && b != NULL){
        if(a->data > b->data){
            my.addLast(a->data);
            a = a->next;
        }
        else if(a->data < b->data){
            my.addLast(b->data);
            b = b->next;
        }
    }
    
    while(b != NULL){
        my.addLast(b->data);
        b = b->next;
    }        
        
    while(a != NULL){
        my.addLast(a->data);
        a = a->next;
    }
        
    my.print();

    return 0;
}