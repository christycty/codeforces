#include <bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;

ll a[200005], N, T, ok;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        FOR(1,N,i) cin >> a[i];        
        FOD(N,2,i) {
            if (a[i] < a[i-1]) {
                cout << -1 << "\n";
                break;
            }
            else if (i == 2) {
                cout << "0\n";
            }
            else if (abs(a[i-1] - a[i]) < 1e18 && a[i-1] - a[i] <= a[i-1]) {
                cout << i - 2 << "\n";
                FOR(1,i-2,j) cout << j << " " << i-1 << " " << i << "\n";
                break;
            }
        }
    }
}