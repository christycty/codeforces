#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)

int N, T, h[105];
long long c, t;
bool ok;

int main(){
    cin >> T;
    while (T--){
        cin >> N;
        FOR(1,N,i) cin >> h[i];
        c = 0, t = 0;
        ok = 1;
        FOR(1,N,i){
            c += i - 1;
            t += h[i];
            if (t < c) ok = 0;
            /*if (h[i-1] >= h[i])
                t = (h[i-1]-h[i]-1) / 2 + 1, c += t, h[i] += t, h[i-1] -= t;*/
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}
