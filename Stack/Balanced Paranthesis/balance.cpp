#include<bits/stdc++.h>

using namespace std;



bool matching(char a, char b){
    return ((a=='(' && b == ')') ||
            (a=='[' && b == ']') ||
            (a=='{' && b == '}') );
}

int main(){

    cout << "Enter the string: ";
    string str;
    cin >>str;

    stack<int>s;

    for(auto i : str){
        if(i == '[' || i == '(' || i == '{'){
            s.push(i);
        }
        else{
            if(s.empty()){
                cout << "NO\n";
                return 0;
            }
            else if(!matching(s.top(), i)){
                cout << "NO\n";
                return 0;
            }
            else{
                s.pop();
            }
        }
    }
    if(s.empty())
        cout << "YES\n";
    else
    {
        cout << "NO\n";
    }
    


    return 0;
}



