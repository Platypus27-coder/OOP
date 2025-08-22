#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include<cctype>

using namespace std;
using ll = long long;

class Hinh {
protected:
    int cao, rong;
public:
    void setValue(int a, int b) {
        cao = a;
        rong = b;
    }
    virtual int getArea() {
        return 0;
    }
};

class hcn : public Hinh {
public:
    int getArea() {
        return cao * rong;
    }
};

class tg : public Hinh {
public: 
    int getArea() {
        return cao * rong / 2;
    }
};

int main() {
    hcn a;
    tg b;
    Hinh *ptr1 = &a;
    Hinh *ptr2 = &b;
    ptr1->setValue(30, 20);
    ptr2->setValue(30, 20);
    cout << ptr1->getArea() << " " << ptr2->getArea() << endl;
    return 0;
}
