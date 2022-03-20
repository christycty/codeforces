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

ll T, N, M, ok, t1, t2, t3, t4;
ll a[200005], b[200005];
ll e[10], ans;

void f(int x, ll ct, int st) {
    if (x >= 9) {
        t1 = (st & (1 << 0)) || (st & (1 << 1)) || (st & (1 << 2));
        t2 = (st & (1 << 5)) || (st & (1 << 6)) || (st & (1 << 7));
        t3 = (st & (1 << 0)) || (st & (1 << 3)) || (st & (1 << 5));
        t4 = (st & (1 << 2)) || (st & (1 << 4)) || (st & (1 << 7));
        if (! (t1 && t2 && t3 && t4)) return;
        /*if (ct == 16) {
            cout << st << " " << t1 << " " << t2 << " " << t3 << " " << t4 << "!\n";
            cout << (st & (1 << 2)) << " " << (st & (1 << 4)) << " " << (st & (1 << 7)) << "??\n";
        }*/

        ans = min(ans, ct);
        return;
    }
    if (ct >= ans) return;
    f(x + 1, ct, st);
    f(x + 1, ct + e[x], (st | (1 << (x-1))));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        FOR(1,N,i) cin >> a[i];
        FOR(1,N,i) cin >> b[i];
        FOR(1,9,i) e[i] = inf;
        e[1] = abs(b[1] - a[1]);
        e[3] = abs(a[1] - b[N]);
        e[6] = abs(a[N] - b[1]);
        e[8] = abs(a[N] - b[N]);
        FOR(2,N-1,i) {
            e[4] = min(e[4], abs(a[i] - b[1]));
            e[5] = min(e[5], abs(b[N] - a[i]));
            e[2] = min(e[2], abs(a[1] - b[i]));
            e[7] = min(e[7], abs(a[N] - b[i]));
        }
        //FOR(1,8,i) cout << e[i] << " "; cout << "\n";
        ans = e[1] + e[8];
        f(1, 0, 0);
        cout << ans << "\n";
    }
    return 0;
}