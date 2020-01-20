#include<bits/stdc++.h>

using namespace std;

class Test{

    public:
        int data1;
        float data2;

    public:
        void insertdata1(int d) {
            data1 = d;
            cout << data1 << '\n';
        }
        
        float insertdata2(){
            cout << "Enter data2: ";
            cin >> data2;
            return data2;
        }


};

int main(){

    Test o1, o2;
    o1.insertdata1(5);
    float t = o1.insertdata2();
    cout << t << '\n';
    cout << o1.data1 << '\n';
    cout << o1.data2 << '\n';
    cout << o2.data1 << '\n';
    
        
    return 0; 
}

























