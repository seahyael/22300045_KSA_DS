#include <iostream>
using namespace std;

int main(){
    int height, weight;
    double bmi;

    cin >> height >> weight;

    bmi = weight / (height*0.01*height*0.01);

    if(bmi >= 25){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}