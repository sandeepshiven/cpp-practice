#include<bits/stdc++.h>

using namespace std;

class Mammal{

    public:
        Mammal(){
            cout << "Mammals can give direct birth." << endl;
        }

};

class WingedAnimal{

  public:
    WingedAnimal(){
        cout << "Winged Animals can flap wings."<<endl;
    }  

};


class Bat:  public WingedAnimal, public Mammal{};


int main(){

    Bat b1;

    return 0;
}

























