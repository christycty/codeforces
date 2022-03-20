#include <bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;
typedef pair<ll,pair<ll,ll>> PLLL;
#define fi first 
#define se second
#define mp make_pair
#define inf 0x3f3f3f3f

ll T, N, pos, t1, t2;
ll tmp[2005], a[2005], ans[2005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        FOR(1,N,i) cin >> a[i];
        FOD(N,1,i) {
            FOR(1,N,j) if (a[j] == i) {
                pos = j; break;
            }
            if (pos == i) {
                ans[i] = 0;
                continue;
            } 
            ans[i] = pos;
            FOR(1,i,j) tmp[j] = a[(j+pos-1)%i+1];
            a[i] = i;
            FOR(1,i,j) a[j] = tmp[j];
           // FOR(1,N,j) cout << tmp[j] << " "; cout << "!\n";
        }
        FOR(1,N,i) cout << ans[i] << " "; cout << "\n";
        //FOR(1,N,i) cout << tmp[i] << " "; cout << "\n";
    }
}