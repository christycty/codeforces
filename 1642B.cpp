#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define fi first
#define se second
typedef long long ll;

int T, N, a[300005], c[300005], M;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        FOR(1,N,i) cin >> a[i];
        sort(a + 1, a + 1 + N);
        M = 1;
        memset(c, 0, sizeof(c));
        c[1] = 1;
        FOR(2, N, i) {
            if (a[i] == a[i-1]) c[M]++;
            else c[++M] = 1;
        }
        sort(c + 1, c + 1 + M);
        FOR(1,M,i) cout << M << " ";
        FOR(M+1,N,i) cout << i << " ";
        cout << "\n";
    }
}