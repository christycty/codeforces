#include <bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;
typedef pair<ll,ll> PLL;
#define eb emplace_back

ll T, N, tmp, ct, M;
vector<ll> r[100005], c[100005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    FOR(1,N,i) FOR(1,M,j) {
        cin >> tmp;
        r[tmp].eb(i);
        c[tmp].eb(j);
    }
    ct = 0;
    FOR(1,100000,i){
        tmp = r[i].size();
        if (tmp == 0) continue;
        sort(r[i].begin(), r[i].end());
        FOR(1,tmp,j) {
            ct += j * (tmp - j) * (r[i][j] - r[i][j-1]);
        }
    }
    FOR(1,100000,i){
        tmp = c[i].size();
        if (tmp == 0) continue;
        sort(c[i].begin(), c[i].end());
        FOR(1,tmp,j) {
            ct += j * (tmp - j) * (c[i][j] - c[i][j-1]);
        }
    }
    cout << ct << "\n";
    return 0;
}