#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
typedef long long ll;

ll N, M, BIT[200005], fac[200005], ans, tc;
ll s[200005], t[200005], c[200005];

void add(ll v, ll ind) {
    while (ind <= M) BIT[ind] += v, ind += ind & -ind;
}

ll sum(ll x) {
    ll c = 0;
    while (x > 0) c += BIT[x], x -= x & -x;
    return c;
}

int main() {
    memset(c, 0, sizeof(c));
    cin >> N >> M;
    FOR(1,N,i) {
        cin >> s[i];
        c[s[i]]++;
    }
    FOR(1,M,i) add(c[i], i);
    FOR(1,M,i) cin >> t[i];
    fac[0] = 1;
    FOR(1,N,i) fac[i] = fac[i-1] * i % MOD;
    ans = 0;
    FOR(1,M,i) {
        //cout << "i = " << i << "\n";
        if (i > N) break;
        tc = fac[N-i] * sum(t[i]-1);
        FOR(1,t[i]-1,j) {
            if (c[j] == 0) continue;
            if (tc < c[j]) tc *= MOD;
            tc /= c[j];
        }
        ans = (ans + tc) % MOD;
        if (!c[t[i]]) {
            break;
        }
        c[t[i]]--, add(-1, t[i]);
    }
    cout << ans << "\n";
    return 0;
}