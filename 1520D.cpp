#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back
typedef long long ll;
typedef pair<int,int> PII;

ll N, T, a[200005], c[200005], mx, t;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N;
        FOR(1,N,i) cin >> a[i];
        FOR(1,N,i) c[i] = a[i] - i;
        sort(c + 1, c + 1 + N);
        //FOR(1,N,i) cout << c[i] << " "; cout << "\n";
        mx = t = 1;
        c[N+1] = c[N] + 10;
        FOR(2,N+1,i){
            if (c[i] != c[i-1]) {
                mx = max(mx, t);
                t = 0;
            }
            ++t;
        }
        //mx = max(mx, t);
        //cout << mx << " | ";
        cout << (ll)(mx - 1) * (ll)mx / 2LL << "\n";
    }


    return 0;
}
