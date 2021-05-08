#include <bits/stdc++.h>
using namespace std;

void printPrimes2(long long n){

    vector<long long>spf(n+1, 0);
    vector<long long>primes;
    for(long long i=2; i<=n; i++){
        if(spf[i] == 0){
            //cout << i << " ";
            primes.push_back(i);
            spf[i] = i;
        }
        for(long long j=0; j<(long long)primes.size() && i*primes[j]<=n && primes[j]<=spf[i]; j++){
            spf[i*primes[j]] = primes[j];
        }
    }
    cout << '\n';

}

void printPrimes1(long long n){

    vector<bool>isPrime(n+1, true);
    for(long long i=2; i<=n; i++){
        if(isPrime[i]){
            //cout << i << " ";
            for(long long j=i*i; j<=n; j += i){
                isPrime[j] = false;
            }
        }
    }
    cout << '\n';

}

int main(){

    int n;
    cout << "Enter the number: ";
    cin >> n;
    clock_t start, end;
    
    start = clock();
    printPrimes1(n);
    end = clock();

    long double time_taken = (long double)(end-start)/(long double)(CLOCKS_PER_SEC);

    cout << "Time taken by sieve: " << fixed << time_taken << setprecision(5);
    cout << " sec\n";

    start = clock();
    printPrimes2(n);
    end = clock();

    time_taken = (long double)(end-start)/(long double)(CLOCKS_PER_SEC);

    cout << "Time taken by modified sieve: " << fixed << time_taken << setprecision(5);
    cout << " sec\n";

    return 0;
}