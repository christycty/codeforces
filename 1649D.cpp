#include <bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;
typedef pair<ll,ll> PLL;
#define eb emplace_back

ll T, N, tmp, ct[1000005], C, a[1000005], ok;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> C;
        FOR(1,N,i) cin >> a[i];
        sort(a + 1, a + 1 + N);
        if (a[1] != 1) {
            cout << "No\n";
            continue;
        }
        memset(ct, 0, sizeof(ct));
        FOR(1,N,i) ct[a[i]]++;
        FOR(1,C,i) ct[i] += ct[i-1];
        ok = 1;
        FOR(2,N,i) {
            FOR(2, (ll)sqrt(a[i]), j) {
                if (ct[j] == ct[j-1]) { // j not exist
                    if (ct[a[i]/j] - ct[a[i]/(j+1)] > 0) {
                        ok = 0;
                        break;
                    }
                }
                else {
                    if (ct[a[i]/j] - ct[a[i]/j-1] == 0) {
                        ok = 0;
                        break;
                    }
                }
            }
            if (!ok) break;
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}

/*
1 = must need


*/