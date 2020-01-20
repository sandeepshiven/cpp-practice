#include<bits/stdc++.h>

using namespace std;

class Rectangle{

    private:
        int length, breadth;

    public:
        Rectangle(){
            length = 5;
            breadth = 4;
        }
        Rectangle(int l, int b){ // overloaded constructor for taking parameter
            length = l;
            breadth = b;
        }

        void Getlength(){
            cout << "Enter length and breadth: ";
            cin >> length >> breadth;
        }
        int area(){
            return (length*breadth);
        }


};

int main(){

    Rectangle r1, r2(2,3);
    cout << "Area of r1 is: " << r1.area()<<endl;
    r1.Getlength();
    cout << "New area of r1 is: " << r1.area()<<endl;
    cout << "Area of r2 is: " << r2.area()<<endl;
    r2.Getlength();
    cout << "New area of r2 is: " << r2.area()<<endl;

    return 0;
}

















