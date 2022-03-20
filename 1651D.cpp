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
ll ans;
ll x[200005], y[200005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    FOR(1,N,i) cin >> x[i];
    FOR(1,N,i) cin >> y[i];
    
    cout << ans << "\n";
    return 0;
}