#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    vector <int> my;
    int size, k, input, output;
    cin >> size;
    cin >> k;
    for(int i =0; i<size; i++){
        cin >> input;
        my.push_back(input);
    }

    make_heap(my.begin(), my.end());

    for(int j= 0; j<k; j++){
        pop_heap(my.begin(), my.end());
        output = my.back();
        my.pop_back();
    }

    cout << output;
    
    return 0;
}