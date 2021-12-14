#include<bits/stdc++.h>

using namespace std;

class Rectangle{

    public:
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
        Rectangle(const Rectangle& rec){
            length = rec.length;
            breadth = rec.breadth;
        }

        void Getlength(){
            cout << "Enter length and breadth: ";
            cin >> length >> breadth;
        }
        int area(){
            return (length*breadth);
        }
        void change(){
            length = 5;
        }
        


};

int main(){

    Rectangle r1, r2;
    r1.Getlength();
    cout << r1.area()<<endl;
    r2 = r1;
    cout << r2.area() << endl;
    r1.change();
    cout << (r1.length)<<endl;
    cout << (r2.length) << endl;
    return 0;
}

















