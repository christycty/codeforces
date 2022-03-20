#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;

ll T, N, u, v;
ll a[105];
bool ys, sp1, sp2, ok;

int main(){
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N >> u >> v;
        FOR(1,N,i) cin >> a[i];
        ys = 1, sp1 = sp2 = 1;
        ok = 0;
        if (a[1] != 1) sp1 = 0;
        if (a[N] != 1000000) sp2 = 0;
        FOR(2,N,i) {
            if (a[i] != a[i-1]) ys = 0;
            if (abs(a[i] - a[i-1]) > 1) ok = 1;
            if (a[i] != 2) sp1 = 0;
            if (a[i] != 1000000 - 1) sp2 = 0;
        }
        if (ok) cout << "0\n";
        else if (ys) cout << v + min(u, v) << "\n";
        //else if (sp1 || sp2) cout << min(u, 2 * v) << "\n";
        else cout << min(u, v) << "\n";
    }
    return 0;
}

/*
wall = v + min(u, v)
if a[1] = 1 and others = 2
*/
