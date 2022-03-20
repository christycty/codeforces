#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;

ll N, X, T, a[105], c;
bool ok;

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> X;
        FOR(1,N,i) cin >> a[i];
        sort(a + 1, a + 1 + N);
        c = 0;
        FOR(1,N,i) c += a[i];
        if (c == X) cout << "NO\n";
        else {
            cout << "YES\n";
            c = 0;
            FOR(1,N-1,i){
                c += a[i];
                if (c == X) {
                    swap(a[i], a[i+1]);
                    break;
                }
            }
            FOR(1,N,i) cout << a[i] << " "; cout << "\n";
        }
    }
    return 0;
}
