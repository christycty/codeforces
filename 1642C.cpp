#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
typedef long long ll;

ll T, N, a[200005], x, b[200005], ans, pt;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> x;
        FOR(1,N,i) cin >> a[i];
        sort(a + 1, a + 1 + N);
        memset(b, 0, sizeof(b));
        ans = 0;
        pt = 2;
        FOR(1,N,i) {
            if (b[i]) continue;
            while (pt <= N && a[i] * x > a[pt]) pt++;
            if (pt <= N && a[i] * x == a[pt]) b[pt] = 1, pt++;
            else ans++;
            //cout << "i " << i << " pt " << pt << " ans " << ans << "\n";
        }
        cout << ans << "\n";
    }
}