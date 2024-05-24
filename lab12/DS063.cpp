#include <iostream>
using namespace std;
#include "Class.h"

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
        
        battlenum1 = d1.showfront();
        battlenum2 = d2.showfront();
        d1.dequeue();
        d2.dequeue();
    }
    else{
        if(winner == 1){
            battlenum1 = (battlenum1 - battlenum2 - 1) + d1.showfront();
            battlenum2 = d2.showfront();
            d1.dequeue();
            d2.dequeue();
        }
        else if(winner == 2){
            battlenum2 = (battlenum2 - battlenum1 - 1) + d2.showfront();
            battlenum1 = d1.showfront();
            d1.dequeue();
            d2.dequeue();
        }
        else{
            battlenum1 = d1.showfront();
            battlenum2 = d2.showfront();
            d1.dequeue();
            d2.dequeue();
        }
    }
    if(battlenum1 > battlenum2) {
            winner = 1;
            player1++;}
    else if(battlenum1 < battlenum2) {
            winner = 2;
            player2++;}
    else winner = 0;
    
    d1.displayQueue(i+1, winner);
 }
 
 cout << "Final - ";
 if(player1 > player2) cout << "P1 win!" << endl;
 else if(player1 < player2) cout << "P2 win!" << endl;
 else cout << "Draw!" << endl;

 return 0;
}