

#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define null NULL


typedef long double ld;

#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

#define vc vector
#define pb push_back
#define um unordered_map
#define us unordered_set
#define Pinf LONG_LONG_MAX
#define Ninf LONG_LONG_MIN
#define MOD (int)((1e9)+7)

vc<int>primes;
vc<int>spf;

void generatePrimes(int n){

    vc<bool>isPrime(n+1, true);
    isPrime[1] = false;     
    isPrime[0] = false;

    for(int i = 2; i<= n; i++){
        if(isPrime[i]){
            primes.push_back(i);
            spf[i] = i;
        }
        for(int j = 0; j<primes.size() &&
                        i*primes[j]<n && primes[j]<=spf[i];
                        j++){

            isPrime[i*primes[j]] = false;
            spf[i*primes[j]] = primes[j];

        }
    }
    
}



bool myComp(pair<string, int>a, pair<string, int>b){
    return a.second < b.second;    
}

int gcd(int a, int b){
    if(a==0){
        return b;
    }
    return gcd(b%a, a);
}

int mod(int a, int m){
    return (a%m + m) % m;
}

int power(int x, int n, int m){

    int res = 1;

    x = x%m;
    if(x==0){
        return 0;
    }

    while(n){
        if(n&1){
            res = (res*x)%m;
        }
        x = (x*x)%m;
        n = n >> 1;
    }
    return res;

}
int nCr(int n, int r){

    int p=1, k=1;

    if(n-r < r){
        r = n-r;
    }

    if(r != 0){

        while(r){
            
            p *= n;
            k *= r;

            int m = gcd(p, k);

            p /= m;
            k /= m;
            n--;
            r--;

        }

    }
    else{
        p=1;
    }
    return p;

}

int LOG;
vector<int>depth;
vector<vector<int>>children;
vector<vector<int>>up;

void dfs(int u){

    for(auto v: children[u]){

        depth[v] = depth[u]+1;
        up[v][0] = u;
        for(int i=1; i<LOG; i++){
            up[v][i] = up[ up[v][i-1] ][i-1];
        }
        dfs(v);
    }

}

int getLCA(int u, int v){

    if(depth[u] < depth[v]){
        swap(u, v);
    }

    while(depth[u] > depth[v]){
        u = up[u][0];
    }
    while(u != v){
        u = up[u][0];
        v = up[v][0];
    }
    return u;
}

void testcase(){

    int n;    
    cin >> n;
    
    children = vector<vector<int>>(n);

    LOG = ceil(log2(n));
    

    for(int v=0; v<n; v++){
        int cnt;
        cin >> cnt;
        for(int i =0; i<cnt; i++){
            int c;
            cin >> c;
            children[v].push_back(c);
        }
    }
    
    depth = vector<int>(n, 0);

    up = vector<vector<int>>(n, vector<int>(LOG));

    dfs(0);

    int q; 
    cin >> q;
    for(int i=0; i<q; i++){
        int u, v;
        cin >> u >> v;
        cout << getLCA(u, v);
        cout << '\n';
    }

    
    
}


signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(null);
    //cout.tie(null);
    //generatePrimes(1000001);
    
    int t;
    
    
    //cin >> t;

       
    //while(t--){
        
        testcase();
		

    //}
    
    return 0;
}
