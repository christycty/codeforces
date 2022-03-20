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

ll T, N, M, t1, t2, t3, L, ok, ans;
ll a[100005];
PII dp[100005][205];
vector<PIII> tr[100005];
vector<ll> ans_s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        FOR(1,N,i) cin >> a[i];
        FOR(1,N,i) tr[i].clear();
        FOR(1,M,i) {
            cin >> t1 >> t2 >> t3;
            tr[t1].eb(mp(i, mp(t2, t3)));
            //cout << "t1 " << t1 << " t2 " << t2 << " t3 " << t3 << "\n";
        }
        //cout << N << " " << M << "!!!\n";
        ok = 1;
        t3 = 0;
        ans_s.clear();
        FOR(1,N,i) {
            //cout << "i = " << i << "\n";
            L = tr[i].size();
            FOR(0,L,j) FOR(0,200,k) dp[j][k].fi = -1, dp[j][k].se = 0;
            dp[0][0].fi = 0;
            //for (auto j : tr[i]) cout << j.fi << " " << j.se.fi << " " << j.se.se << "\n";
            FOR(1,L,j) { // for each training
                FOR(0,200,k) dp[j][k].fi = dp[j-1][k].fi;
                FOR(0,100,k) {
                    if (dp[j-1][k].fi == -1 || dp[j-1][k].fi + tr[i][j-1].se.fi > a[i]) continue;
                    t1 = k + tr[i][j-1].se.se;
                    //if (j == 2 && k == 0) cout << t1 << " " << tr[i][j-1].se.se << " " << dp[j-1][t1].fi << "\n";
                    if (dp[j][t1].fi == -1 || dp[j][t1].fi > dp[j-1][k].fi + tr[i][j-1].se.fi) {
                        dp[j][t1].fi = dp[j-1][k].fi + tr[i][j-1].se.fi;
                        dp[j][t1].se = 1; // use self
                        //cout << "dp " << dp[j][t1].fi << " " << j << " " << t1 << "\n";
                    }
                }
            }
            t1 = -1;
            FOR(100,200,j) {
                if (dp[L][j].fi != -1 && (t1 == -1 || dp[L][j].fi < dp[L][t1].fi)) t1 = j;
            }
            if (t1 == -1) { ok = 0; break; }
            t3 += dp[L][t1].fi; //cout << "t3 " <<  t3 << "\n";
            if (t3 > a[i]) { ok = 0; break; }
            //if (i == 2) FOR(0,120,j) cout << "j = " << j << " " << dp[L][j].fi << "\n";
            //cout << "t1 = " << t1 << " " << dp[L][t1].fi << "\n";
            // backtrack
            FOD(L,1,j) {
                if (dp[j][t1].se == 1) {
                    ans_s.eb(tr[i][j-1].fi);
                    t1 -= tr[i][j-1].se.se;
                }
            }
        }
        if (!ok) {
            cout << "-1\n"; 
            continue;
        }
        cout << ans_s.size() << "\n";
        for (auto i : ans_s) cout << i << " ";
        cout << "\n";
    }
}

