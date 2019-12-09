 
#include <bits/stdc++.h>
using namespace std;
long long function_add(long long ,long long ,long long);
int main()
{
    long long test,i,two=0,num_a=0,num_b=0,ans;
    cin >>test;
    cin.ignore();
    while(test--){
        string a;
        string b;
        num_a=0;num_b=0;two=0;
        getline(cin,a);
        getline(cin,b);        
        for(i = a.length()-1;i>=0;i--){
            if(a[i]=='1'){
                num_a += pow(2,two);
            }
            two++;
        }
        two=0;
        for(i = b.length()-1;i>=0;i--){
            if(b[i]=='1'){
                num_b += pow(2,two);
            }
            two++;
        }
        //cout<<num_a<<' '<<num_b<<'\n';
        ans=function_add(num_a,num_b,0);
        cout<<ans<<'\n';
        
    }
    return 0;
} 

long long function_add(long long a,long long b, long long n){

    if(b<=0)
        return n;
    return function_add(a^b,(a&b)*2,n+1);
    
}