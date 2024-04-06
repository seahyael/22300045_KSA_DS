#include <iostream>
using namespace std;

int main(){
    int month, day;
    int day_count = 0;

    cin >> month >> day;
    for(int i = 1; i<month; i++){
        switch(i){
            case 1: case 3:  case 5: case 7: case 8: case 10: case 12:
                day_count += 31;
                break;
            case 2:
                day_count += 28;
                break;
            case 4: case 6: case 9: case 11:
                day_count += 30;
                break;
        }
    }

    day_count += day;

    cout << day_count;
    return 0;
}