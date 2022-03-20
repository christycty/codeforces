#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define fi first
#define se second
#define mp make_pair
#define inf 0x3f3f3f3f
typedef long long ll;
typedef pair<ll,ll> PLL;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;


ll N, S, K, dp[55][3005], r[55], c[55];
char ch;
bool ok;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> S >> K;
    FOR(1,N,i) cin >> c[i];
    FOR(1,N,i) {
        cin >> ch;
        r[i] = (ch == 'R' ? 1 : (ch == 'G' ? 2 : 3));
    }
    priority_queue<PIII, vector<PIII>, greater<PIII>> pq;
    FOR(0,N,i) FOR(0,K+500,j) dp[i][j] = inf;
    FOR(1,N,i){
        dp[i][c[i]] = abs(i-S);
        pq.push(mp(abs(i-S), mp(i, c[i])));
    }
    /*while (!pq.empty()) {
        auto t1 = pq.top();
        pq.pop();
        cout << t1.fi << " " << t1.se.fi << " " << t1.se.se << "\n";
    }*/
    ok = 0;
    while (!pq.empty()) {
        auto t1 = pq.top();
        pq.pop();
        //cout << t1.fi << " " << t1.se.fi << " " << t1.se.se << "\n";
        if (t1.se.se >= K) {
            ok = 1;
            cout << t1.fi << "\n";
            break;
        }
        FOR(1,N,i) {
            if (r[i] == r[t1.se.fi] || c[i] <= c[t1.se.fi]) continue;
            if (dp[i][t1.se.se+c[i]] > t1.fi + abs(i-t1.se.fi)) {
                dp[i][t1.se.se+c[i]] = t1.fi + abs(i-t1.se.fi);
                pq.push(mp(dp[i][t1.se.se+c[i]], mp(i, t1.se.se+c[i])));
            }
        }
    }
    if (!ok) cout << "-1\n";
    return 0;
}