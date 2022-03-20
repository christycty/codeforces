#include <bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;
typedef pair<ll,ll> PLL;
typedef pair<ll,pair<ll,ll>> PLLL;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
#define fi first 
#define se second
#define mp make_pair
#define eb emplace_back
#define inf 0x3f3f3f3f

ll T, N, M, ok;
ll a[1005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        a[1] = 1;
        ok = 1;
        FOR(2,N,i) {
            a[i] = a[i-1] * 3;
            if (a[i] > 1000000000) {
                ok = 0;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
        if (ok) {FOR(1,N,i) cout << a[i] << " "; cout << "\n"; }
    }
    return 0;
}