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
        // Rectangle(Rectangle& rec){
        //     length = rec.length;
        //     breadth = rec.breadth;
        // }

        void Getlength(){
            cout << "Enter length and breadth: ";
            cin >> length >> breadth;
        }
        int area(){
            return (length*breadth);
        }
        


};

int main(){

    Rectangle r1(7,8);
    cout << r1.area()<<endl;
    Rectangle r2 = r1;
    cout << r2.area() << endl;
    r2.Getlength();
    cout << r1.area()<<endl;
    cout << r2.area() << endl;
    return 0;
}

















