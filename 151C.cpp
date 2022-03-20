#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
typedef long long ll;

ll Q, T, t, ok;
bool sieve[5000005];

bool check(ll x) {
    bool ok = 0;
    FOR(2,T,i) {
        if (Q % i == 0){
            ok = 1;
            break;
        }
    }
    if (!ok) return 0;

}

int main() {
    cin >> Q;
    
    memset(sieve, 1, sizeof(sieve));
    T = (ll)floor(sqrt(Q));
    ok = 0;
    FOR(2,T,i) {
        if (Q % i == 0){
            ok = 1;
            break;
        }
    }
    if (!ok){
        cout << "1\n0\n"; return 0;
    }
    t = -1;
    ok = 0;
    FOR(2,T,i){
        if (sieve[i]) {
            FOR(2,T/i,j) sieve[j] = 0;
            if (Q % i == 0){
                if (t != -1) ok = 1;
                t = i;
            } 
        }
        else if (Q % i == 0){
            t = i;
            ok = 1;
            break;
        }
    }
    if (!ok) {
        cout << "2\n";
    }
    else{
        cout << "1\n" << (sieve[t] ? Q / t : t) << "\n";
        cout << check((sieve[t] ? Q / t : t)) << "\n";
    }

    return 0;
}