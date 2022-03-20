#include <bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;

int T, N, a[55];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        if (N == 3) {
            cout << "1 3 2\n2 3 1\n3 2 1\n";
        }
        else {
            FOD(N,1,i) a[N-i+1] = i;
            FOR(1,N,i) {
                FOR(1,N,j) cout << a[(i+j)%N+1] << " ";
                cout << "\n";
            }            
        }
    }
}