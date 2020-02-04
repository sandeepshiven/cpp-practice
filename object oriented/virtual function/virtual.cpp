#include<bits/stdc++.h>

using namespace std;

class Weapon{

    public:
        virtual void loadfeature(){
            cout << "Loading weapons feature.....\n";
        }

};

class Bomb: public Weapon{

    public:
        void loadfeature(){
            cout << "Loading bomb weapon feature.....\n";
        }
};

class Uzi: public Weapon{

    public:
        void loadfeature(){
            cout << "Loading Uzi weapon feature.....\n";
        }

};


int main(){

    /*
    Weapon *w = new Weapon;
    Bomb *b = new Bomb;
    Uzi *u = new Uzi;

    w->loadfeature();
    b->loadfeature();
    u->loadfeature();

    output:
    Loading weapons feature.....
    Loading bomb weapon feature.....
    Loading Uzi weapon feature.....

    when not using virtual function and loader class not created

    */

   /*
   Weapon *w;
   Bomb b;
   Uzi u;

   w = &b;
   w->loadfeature();

    output:
    Loading weapons feature.....

    this is due to early binding
    */
   Weapon *w;
   Bomb b;
   Uzi u;

   w = &b;
   w->loadfeature();


    return 0;
}







































