#include<bits/stdc++.h>

using namespace std;

class Base{

    public:
        int x;
    
    private:
        int y;
    
    protected:
        int z;
};

class pubD: public Base{

    public:
        pubD(){
            x = 2; // allowed public
        //  y = 2; // not allowed private
            z = 2; // allowed protected
        }

};

class privD: private Base{

    public:
        privD(){
            x = 2; // allowed public
            //y = 2; // not allowed private
            z = 2; // allowed protected
        }


};

class proD: protected Base{

    public:
        proD(){
            x = 2; // allowed public
            //y = 2; // not allowed private
            z = 2; // allowed protected
        }

};


int main(){

    Base b1;
    b1.x = 1; // allowed public
    // b1.y = 2; // not allowed private
    // b1.z = 3; // not allowed protected

    pubD p1;
    p1.x = 1;
    // p1.y = 2; // not allowed private
    // p1.z = 3; // not allowed protected

    privD p2;
    // p2.x = 1; // not allowed private
    // p2.y = 2;  // not allowed private
    // p2.z = 3; // not allowed private

    proD p3;
    // p3.x = 1; // not allowed protected
    // p3.y = 2;  // not allowed protected
    // p3.z = 3; // not allowed protected


    return 0;
}





















