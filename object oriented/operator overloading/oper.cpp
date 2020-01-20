#include<bits/stdc++.h>

using namespace std;

class Complex{
    
    private:
        int real, img;

    public:
        Complex(){
            real = 0;
            img = 0;
        }

        void readData(){
            cout << "Enter the values of real and imaginary parts: ";
            cin >> real >> img;
        }

        Complex operator+(Complex &c1){
            Complex test;
            test.real = c1.real + real;
            test.img = c1.img + img;
            return test;
        }

        void displaySum(){
            cout << real << " + " << img << 'i' << endl;
        }
};


int main(){
    
    Complex o1,o2,o3;
    o1.readData();
    o1.displaySum();
    o2.readData();
    o2.displaySum();
    o3 = o1 + o2;
    o3.displaySum();

    return 0;

}

















