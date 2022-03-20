#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
typedef long long ll;

ll T, N, M, a[100005];
ll c[100005], ans;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        memset(c, 0, sizeof(c));
        FOR(1,N,i) {
            cin >> a[i];
            c[a[i] % M]++;
        }
        ans = 0;
        FOR(1, (M % 2 ? M / 2 : M / 2 - 1), i) {
            if (c[i] > 0 && c[M-i] > 0) ans++;
            else continue;
            if (c[i] < c[M-i]) c[M-i] -= c[i] + 1, c[i] = 0;
            else c[i] = max(0LL, c[i] - c[M-i] - 1), c[M-i] = 0;
        }
        if (M % 2 == 0 && c[M/2] > 0) {
            ans++;
            c[M/2] = 0;
        }
        if (c[0] > 0) ans++, c[0] = 0;
        //cout << ans << "test\n";
        FOR(1,M,i) ans += c[i];
        cout << ans << "\n";
    }


    return 0;
}
