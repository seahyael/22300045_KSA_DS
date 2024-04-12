#include <iostream>
using namespace std;

void output(int count, int *total,int *max){
    int *numbers = new int[count];
    for(int i = 0; i<count; i++){
        cin >> numbers[i];
        if(*max<numbers[i]) *max = numbers[i];
        *total += numbers[i];
    }
    delete[] numbers;
}

int main(){
    int count;
    int total = 0;
    int max = 0;

    cin >> count;
    output(count, &total, &max);

    cout << total << " " << max;
    return 0;
}

