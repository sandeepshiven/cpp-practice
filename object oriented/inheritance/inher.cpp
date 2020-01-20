#include<bits/stdc++.h>

using namespace std;

class Person{

    public:
        string profession;
        int age;

        Person(string p="unemployed", int a=20){
            profession = p;
            age  = a;
        }
        void introduce(){
            cout << "My profession is: " << profession<<endl;
            cout << "And my age is: "<<age<<" years"<<endl;
        }
        void walk(){
            cout << "I can walk"<<endl;
        }

};

class MathTeacher: public Person{

    public:
        MathTeacher(int i){
            profession = "Math teacher";
            age = i;
            }
        void teach(){
            cout << "I can teach math"<<endl;
        }

};

class Footballer: public Person{

    public:
        // Footballer(){
        //     profession = "Footballer";
        // }
        void play(){
            cout << "I can play football"<<endl;
        }

};




int main(){

    Person p1, p2("Police", 30);
    p1.introduce();
    p2.introduce();
    MathTeacher m1(42);
    m1.introduce();
    Footballer f1("akdfjakj", 98);
    f1.introduce();




    return 0;
}























