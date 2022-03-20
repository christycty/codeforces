#include <bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;
typedef pair<ll,ll> PLL;

ll T, N, a[200005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        FOR(1,N,i) cin >> a[i];
        ll mx = 0, c = 0;
        FOR(1, N, i) mx = max(a[i], mx), c += a[i];
        if (c == 0) cout << "0\n";
        else if (c - mx + 1 < mx) cout << 2 * mx - c << "\n";
        else cout << 1 << "\n";
    }
    return 0;
}