#include <bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;
typedef pair<ll,ll> PLL;

ll T, N, a[105], c;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        FOR(1,N,i) cin >> a[i];
        FOR(1,N,i) FOR(1,N,j) {
            if (i == j) continue;
            a[i] = (a[i] | a[j]) - a[j];
        }
        c = 0;
        FOR(1,N,i) c += a[i];
        cout << c << "\n";
    }
}