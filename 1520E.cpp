#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back
#define inf (ll)1e16
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;

ll N, T, L, R, lc, rc, mn;
string s;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N >> s;
        s = '.' + s;
        L = R = lc = rc = 0;
        // L = #sheeps at left, lc = total space at left
        // rc = cost to move all sheeps at right to current point
        // lc = cost to move all sheeps at left to current point - 1
        FOD(N,1,i) {
            rc += R;
            if (s[i] == '*') ++R;
        }
        mn = inf;
        FOR(1,N,i) {
            //cout << i << " " << rc - R * (R - 1) / 2 + lc - L * (L + 1) / 2 << "\n";
            mn = min(mn, rc - R * (R - 1) / 2 + lc - L * (L + 1) / 2);
            if (s[i] == '*') ++L, --R;
            rc -= R, lc += L;
        }
        cout << mn << "\n";
    }


    return 0;
}

// R R-1 R-2 ... 1
// R = 2 --> -1
// R = 3 --> -1 -2
// total -( R*(R-1)/2 )

// L = 2 --> -1 -2
// L = 3 --> -1 -2 -3
// total -( (1+L)*L/2)
