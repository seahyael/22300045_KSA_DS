#include <iostream>
#include <queue>
using namespace std;

int main(){
    int num;
    cin >> num;
    queue <int> my;

    for(int i = 0; i<num; i++){
        my.push(i+1);
    }

    while(my.size() != 1){
        my.pop();
        my.push(my.front());
        my.pop();
    }

    cout << my.front();
}