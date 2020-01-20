#include<bits/stdc++.h>

using namespace std;

class A{
    public:
        void print(){
            cout << "This is coming from base class"<< endl;
        }
};

class B: public A{};

class C: public B{};

int main(){

    C obj;

    obj.print();

    return 0 ;
}

















