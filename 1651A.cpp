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

ll T, N, M;
ll a[100005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        //FOR(1,N,i) cin >> a[i];
        ll t = 1;
        FOR(1,N,i) t *= 2;
        cout << t - 1 << "\n";
    }
    return 0;
}