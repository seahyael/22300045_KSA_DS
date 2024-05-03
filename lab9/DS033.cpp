#include <iostream>
#include <string>
using namespace std;

struct Coupon{
    int level;
    string name;
};

class CouponStack {
private:
    int maxsize;
    int top;
    Coupon *list;

public:
    void initialize();
    bool isEmpty() const;
    bool isFull() const;
    void push(const Coupon &item);
    Coupon* pop();
    CouponStack(int size = 10){
        maxsize = size;
        top = -1;
        list = new Coupon[maxsize];
    }
    ~CouponStack() {
        delete[] list;
    }
    void print();
    void rprint();
};

void CouponStack::initialize() {
    top = -1;
}

bool CouponStack::isEmpty() const {
    return top == -1;
}

bool CouponStack::isFull() const {
    return top == maxsize - 1;
}

void CouponStack::push(const Coupon &item) {
    list[++top] = item;
}

Coupon* CouponStack::pop() {
    return &list[top--];
}

void CouponStack::print(){
    for (int i = 0; i <= top; ++i) {
        cout << list[i].level << "µî - " << list[i].name << endl;
    }
}

void CouponStack::rprint() {
    while (!isEmpty()) {
        Coupon *coupon = pop();
        cout << coupon->level << "µî - " << coupon->name << endl;
    }
}

int main(){
    int size;
    cin >> size;
    CouponStack my(size);

    char input;
    cin >> input;
    while(input != 'q'){
        if(input == '+'){
            int level;
            string name;
            cin >> level;
            getline(cin,name);
            Coupon co;
            co.level = level;
            co.name = name;
            my.push(co);
        }
        else if(input == '-'){
            Coupon *output = my.pop();
            cout <<  output->level << "µî - " << output->name << endl;
 
        }
        cin >> input;
    }
    return 0;
}