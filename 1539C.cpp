#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
typedef long long ll;

ll N, K, x, M, ans;
ll a[200005], c[200005];
set<ll> st;

int main() {
    M = 0;
    cin >> N >> K >> x;
    FOR(1,N,i) cin >> a[i];
    sort(a + 1, a + 1 + N);
    FOR(1,N,i) {
        if (st.empty() || st.lower_bound(a[i] - x) == st.end()){
            st.insert(a[i]);
            if (i != 1) {
                c[++M] = a[i] - *prev(st.lower_bound(a[i] - x), 1);
            }
           //cout << i << " ";
        }
        else {
            st.erase( st.lower_bound(a[i] - x) );
            st.insert(a[i]);
        }
    }
    //cout << "\n";
    ans = st.size();
    sort(c + 1, c + 1 + M);
    //FOR(1,M,i) cout << c[i] << " ";
    FOR(1,M,i) {
        if ((ceil((double)c[i] / x) - 1) <= K) {
           // cout << (ceil((double)c[i] / x) - 1) << " ";
            ans--;
            K -= (ceil((double)c[i] / x) - 1);
        }
        else break;
        if (K <= 0) break;
    }
    cout << ans << "\n";
    return 0;
}
