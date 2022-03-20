#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)

int T, N, a[105];

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N;
        FOR(1,N,i) cin >> a[i];
        sort(a + 1, a + 1 + N);
        a[0] = -1;
        FOR(1,N,i) if (a[i] != a[i-1]) cout << a[i] << " ";
        FOR(1,N,i) if (a[i] == a[i-1]) cout << a[i] << " ";
        cout << "\n";
    }


    return 0;
}
