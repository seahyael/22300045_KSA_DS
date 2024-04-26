#include <iostream>
using namespace std;

class Score{
private:
    string name;
    int lcScore, rcScore;
public:
    void input();
    void output();
};

void Score::input(){
    getline(cin,name);
    cout << "LC> ";
    cin >> lcScore;
    while(lcScore < 0 || lcScore > 495){
        cout << "LC> ";
        cin >> lcScore;
    }

    cout << "RC> ";
    cin >> rcScore;
    while(rcScore < 0 || rcScore > 495){
        cout << "RC> ";
        cin >> rcScore;
    }
}

void Score::output(){
    int total = lcScore + rcScore;
    cout << "[" << name << "]" << endl;
    cout << "LC - " << lcScore << " ";
    if(lcScore >= 350) cout << "Pass" << endl;
    else cout << "Fail" << endl;
    cout << "RC - " << rcScore << " ";
    if(rcScore >= 350) cout << "Pass" << endl;
    else cout << "Fail" << endl;
    cout << "Total - " << total << endl;
}

int main(){
    Score s;
    s.input();
    s.output();
    return 0;
}