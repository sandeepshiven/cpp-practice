#include<bits/stdc++.h>

using namespace std;


class A{

    private:
        int x = 983;
        string s = "class a";

    public:
        friend class B;
};

class B{

    public:
        void getdata(A obj){
            cout << "x = " << obj.x << endl;
            cout << "s = " << obj.s << endl; 
        }

};

int main(){

    A o1;
    B o2;

    o2.getdata(o1);

    return 0;
}





































