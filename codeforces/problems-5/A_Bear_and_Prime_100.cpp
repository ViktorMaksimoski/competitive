#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    vector<int> primes;
    int sieve[51];
    memset(sieve, 0, sizeof(sieve));
    sieve[1] = 1;
    for(int i=2; i<=50; i++) {
        if(sieve[i]) continue;
        primes.push_back(i);
        for(int j=i+i; j<=50; j+=i)
            sieve[j] = 1;
    }

    //see if the number is divisible by 2 primes
    int cnt = 0;
    for(int &x : primes) {
        cout << x << endl;
        string s;
        cin >> s;
        if(s == "yes") cnt++;

        if(cnt == 2) {
            cout << "composite" << endl;
            return 0;
        }
    }

    //see if the number is prime^2
    for(int i=0; i<4; i++) {
        cout << primes[i] * primes[i] << endl;
        string s;
        cin >> s;
        
        if(s == "yes") {
            cout << "composite" << endl;
            return 0;
        }
    }

    cout << "prime" << endl;
    return 0;
}