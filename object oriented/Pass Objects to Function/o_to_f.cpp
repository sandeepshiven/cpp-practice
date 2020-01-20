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

        void addComplex(Complex &c1, Complex &c2){
            real = c1.real + c2.real;
            img = c1.img + c2.img;
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
    o3.addComplex(o1, o2);
    o3.displaySum();

    return 0;

}

















