#include <bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;
typedef pair<ll,pair<ll,ll>> PLLL;
#define fi first 
#define se second
#define mp make_pair

ll T, N, M, c;
PLLL a[200005], b[200005];
string s;

bool cmp(PLLL t1, PLLL t2) {
    return t1.se.se < t2.se.se;
}

bool cmp2(PLLL t1, PLLL t2) {
    return t1.se.fi < t2.se.fi;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        getline(cin ,s);
        cin >> N >> M;
        FOR(1,M,i) {
            cin >> a[i].se.fi >> a[i].se.se;
            a[i].fi = i;
        } 

        /*cout << "=========\n";
        FOR(1,M,i) cout << a[i].se.fi << " " << a[i].se.se << "\n";
        cout << "=========\n";*/
        
        sort(a + 1, a + M + 1, cmp);
        //FOR(1,2*N,i) cout << a[i].se.se << " "; cout << "\n";
        c = 0;
        FOR(1,2*N,i) b[i] = a[i], c += a[i].se.se;
        sort(b + 1, b + 1 + 2 * N, cmp2);
        cout << c << "\n";
        FOR(1,N,i) cout << b[i].fi << " " << b[2*N-i+1].fi << "\n";
        if (T > 0) cout << "\n";
    }
}