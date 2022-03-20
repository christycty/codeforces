#include <bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;
typedef pair<ll,ll> PLL;

int T, N, a[105];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        FOR(1,N,i) cin >> a[i];
        int t1 = N, t2 = 0;
        FOR(1,N,i) if (a[i] != 1) {
            t1 = i;
            break;
        }
        FOD(N,1,i) if (a[i] != 1) {
            t2 = i;
            break;
        }
        if (t1 == N) {
            cout << "0\n";
        }
        else {
            cout << t2 - t1 + 2 << "\n";
        }
    }
    return 0;
}