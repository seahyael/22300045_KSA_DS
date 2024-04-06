#include <iostream>
using namespace std;

struct st_score
{
    int kor, eng, math;
    int total;
    double average;
};

int main(){
    st_score a;
    cin >> a.kor >> a.eng >> a.math;

    a.total = a.kor + a.eng + a.math;

    a.average = a.total/3.0;

    cout << a.total << " " << a.average << "\n";

    if(a.kor>=70) cout << "Korean - Pass\n";
    else cout << "Korean - Fail\n";
    if(a.eng>=70) cout << "English - Pass\n";
    else cout << "English - Fail\n";
    if(a.math>=70) cout << "Math - Pass\n";
    else cout << "Math - Fail\n";
    return 0;
}
