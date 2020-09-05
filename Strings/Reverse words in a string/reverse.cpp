#include<bits/stdc++.h>

using namespace std;

int main(){

    cout << "Enter the string: ";
    string str, word="";
    getline(cin, str);
    
    vector<string>vec;

    for(int i=0; i<str.length(); i++){
        if(str[i] != ' '){
            word += str[i];
        }
        else{
            vec.push_back(word);
            word = "";
        }
    }
    vec.push_back(word);
    string new_str = "";

    for(int i=vec.size()-1; i>=0; i--){
        new_str += vec[i] + " ";
    }

    cout << new_str; 

    return 0;
}