#include <iostream>
using namespace std;

class Student{
    private:
        double getAvg() const;
    public:
        string name;
        string sid;
        int *score;
        void print() const;
};

double Student::getAvg() const{
    double avg = 0;
    for(int i = 0; i<3; i++){
        avg += score[i];
    }
    avg = avg/3.0;
    return avg;
}

void Student::print() const{
    cout << "[" << sid << "]" << name << "\n"; 
    cout.precision(1);
    cout << "The Average score is " << fixed << getAvg();
}

int main(){
    Student s;
    s.score = new int[3];
    cin >> s.sid >> s.score[0] >> s.score[1] >> s.score[2];
    cin.ignore();
    getline(cin,s.name);

    s.print();
    delete[] s.score;
    return 0;
}