#include <bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;
typedef pair<ll,ll> PLL;

ll T, N, a[200005], c;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        FOR(1,N,i) cin >> a[i];
        c = 0;
        FOR(2,N-1,i) if (a[i] > a[i-1] && a[i] > a[i+1]) {
            c++;
            a[i+1] = max(a[i], a[i+2]);
        }
        cout << c << "\n";
        FOR(1,N,i) cout << a[i] << " "; cout << "\n";
    }
}

/*

dont think too much @@
Note: resulting array can be V-shaped (vertex may be at anywhere including 1 and N)
LtR[i] = #operations to maintain non-increasing until i (from 1)
RtL[i] = #operations to maintain non-increasing until i (from N)
*/