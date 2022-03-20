#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> PII;

ll N, Q, a[300005], t;
ll f[55], tme[55];

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> N >> Q;
    FOR(1,N,i) cin >> a[i];
    FOR(1,N,i) if (!f[a[i]]) f[a[i]] = i;
    //FOR(1,N,i) tme[i] = 1;
    FOR(1,Q,i) {
        cin >> t;
        cout << f[t] << " ";
        FOR(1,50,j) if (f[j] < f[t]) ++f[j];
        f[t] = 1;
    }
    return 0;
}
