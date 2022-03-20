#include <bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;
typedef pair<ll,ll> PLL;
#define MOD 1000000007

ll N, P, c[200005], tmp, dp[200005];
set<ll> s;

bool ok(ll x) {
    tmp = x;
    while (true) {
        if (tmp & 1) tmp = (tmp - 1) >> 1;
        else if (tmp % 4 == 0) tmp = tmp >> 2;
        else return true;
        if (tmp <= 0) return true;
        if (s.find(tmp) != s.end()) return false;
    }
}

ll ln2(ll x) {
    tmp = 0;
    while (x > 0) {
        x /= 2;
        tmp++;
    }
    return tmp;
}

int main() {
    cin >> N >> P;
    FOR(1,N,i) {
        cin >> tmp;
        s.insert(tmp);
    } 
    memset(c, 0, sizeof(c));
    for (auto itr = s.begin(); itr != s.end(); itr++) {
        if (ok(*itr)) c[ln2(*itr)]++;
    }
    memset(dp, 0, sizeof(dp));
    dp[1] = c[1];
    dp[2] = dp[1] + c[2];
    FOR(3,P,i) dp[i] = (dp[i-1] + dp[i-2] + c[i]) % MOD;
    //FOR(1,P,i) cout << c[i] << " "; cout << "\n";
    //FOR(1,P,i) cout << dp[i] << " "; cout << "\n";
    FOR(2,P,i) dp[i] = (dp[i] + dp[i-1]) % MOD;
    cout << dp[P] << "\n";
}

/*
(2^p-1) * 2 + 1 = 2^(p+1) - 1
(2^p-1)*  4 = 2^(p+2) - 4 => if p=1: 1*4 <= 2^3-4 (i.e. still fit in 2^3)
=> dp transition dp[i] = dp[i-1] + dp[i-2] + c[i]
dp[i] = #elements in [2^(i-1), 2^i-1]
c[i] = elements within range dp[i] that cannot be computed from others

How to remove numbers that can be generated from other numbers:
(credits to tutorial comments)
- think of operations as appending "00" or "1" to binary
-> "parents" are its prefixes
*/