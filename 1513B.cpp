#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> PII;

ll N, a[200005], T, c, t;

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        FOR(1,N,i) cin >> a[i];
        t = a[1];
        c = 0;
        FOR(2,N,i) t &= a[i];
        FOR(1,N,i) if (a[i] == t) ++c;
        if (c >= 2) {
            t = c * (c - 1) % MOD;
            FOR(2,N-2,i) t = t * i % MOD;
            cout << t << "\n";
        }
        else cout << "0\n";
    }
    return 0;
}
