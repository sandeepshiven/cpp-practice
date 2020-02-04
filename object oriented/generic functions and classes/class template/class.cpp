#include<bits/stdc++.h>

using namespace std;

template <class T>
class Calculator{

    private:
        T a, b;

    public:
        Calculator(T num1, T num2){
            a = num1;
            b = num2;
        }

        T addition(){
            return a+b;
        }

        T subtraction(){
            return a-b;
        }

        T multiplication(){
            return a*b;
        }

        T division(){
            return a/b;
        }

        void display(){
            cout << "The numbers are: "<<a<<" and "<<b<<endl;
            cout << "Addition: "<< addition()<<endl;
            cout << "Subtraction: "<< subtraction() << endl;
            cout << "Multiplication: "<< multiplication() << endl;
            cout << "Division: "<< division()<<endl;
        }


};

int main(){
    Calculator<int> Intcal(8, 4);
    Calculator<float> Floatcal(0.5, 0.5);

    Intcal.display();
    Floatcal.display();

    return 0;
}





























