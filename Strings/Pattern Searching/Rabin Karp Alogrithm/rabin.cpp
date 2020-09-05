#include<bits/stdc++.h>

using namespace std;

void RBSearch(string txt, string pat, int M, int N);


int main(){

    cout << "Enter the string: ";
    string txt, pat;
    getline(cin, txt);
    cout << "Enter the pattern: ";
    getline(cin, pat);

    int N = txt.length();
    int M = pat.length();

    RBSearch(pat, txt, M, N);


    return 0;
}

void RBSearch(string pat, string txt, int M, int N){

    long long int h=1;

    int d = 5;
    int q = 101;

    for(int i=0; i<M-1; i++){
        h = (h*d);//%q;             // computing (d^(m-1))%q
    }

    long long int p=0, t=0;
    for(int i=0; i<M; i++){
        p = (p*d + (pat[i]-'a'+1));//%q;
        t = (t*d + (txt[i]-'a'+1));//%q;       // computing p and t0
    }

    for(int i=0; i<=N-M; i++){
        if(p==t){
            bool flag = true;
            for(int j=0; j<M; j++){
                if(txt[i+j] != pat[j]){         // check for spurious hits
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                cout << i << "\n";
            } 
        }
        if(i < N-M){
            t = (d*(t - (txt[i]-'a'+1)*h) + (txt[i+M]-'a'+1));//%q;            // compute t(i+1) using t(i)
            if(t<0){
                t = t+q;
            }
        }
    }


}