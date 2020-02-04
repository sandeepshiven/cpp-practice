#include<bits/stdc++.h>


using namespace std;

class A{

    private:
        int x = 10;
        string s = "String";

    public:
        friend void print(A obj);

};


void print(A obj){
    cout << "x = " << obj.x << endl;
    cout << "s = " << obj.s << endl;
}


int main(){
    
    A obj;
    print(obj);

    return 0;
}

































