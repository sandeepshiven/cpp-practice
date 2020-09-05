#include<bits/stdc++.h>

using namespace std;

void fillLPS(string pat, vector<int>&lps);

int main(){

    cout << "Enter string: ";
    string txt, pat;
    getline(cin, txt);
    cout << "Enter pattern: ";
    getline(cin, pat);

    int n = txt.length();
    int m = pat.length();

    vector<int>lps(m);
    fillLPS(pat, lps);

    bool flag=true;

    int i=0, j=0;
    while(i<n){
        if(pat[j] == txt[i]){
            i++;
            j++;
        }
        if(j==m){
            cout << i-j <<'\n';
            flag = false;
            j = lps[j-1];
        }
        else if(i<n && pat[j] != txt[i]){
            if(j==0){
                i++;
            }
            else{
                j = lps[j-1];
            }
        }
    }
    if(flag){
        cout << "No match found\n";
    }
    

    return 0;
}

void fillLPS(string pat, vector<int>&lps){
    int n = pat.length();

    lps[0] =0;
    int len=0, i=1;
    while(i<n){
        if(pat[len] == pat[i]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len == 0){
                lps[i] = 0;
                i++;
            }
            else{
                len = lps[len-1];
            }
        }
    }
}









