#include<bits/stdc++.h>

using namespace std;
bool findRotation(string str, string rot);

int main(){

    cout << "Enter string: ";
    string txt, rot;
    getline(cin, txt);
    cout << "Enter rotation: ";
    getline(cin, rot);
    
    if(findRotation(txt, rot)){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    } 
    

    return 0;
}

bool findRotation(string str, string rot){
    if(str.length() != rot.length()){
        return false;
    }

    return ((str + str).find(rot) != string::npos);
}











