#include<bits/stdc++.h>

using namespace std;

class Base{
    public:
        void print(){
            cout << "This is coming from base class"<< endl;
        }
};

class Over: public Base{
    public:
        void print(){
            cout << "This is coming from the derived class Over" << endl; 
        }
};

class OverAcess: public Base{
    public:
        void print(){
            Base::print();
            cout << "This is coming from the derived class OverAcess" << endl;
        }

};

int main(){

    Base b;
    b.print();

    Over o;
    o.print();

    OverAcess o2;
    o2.print();

    return 0;
}


















