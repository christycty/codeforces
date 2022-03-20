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

ll N, T, a[105][105], x, y, c;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N;
        if (N == 1) cout << "1\n";
        else if (N == 2) cout << "-1\n";
        else {
            c = 0;
            FOR(1,2*N-1,i) {
                if (i % 2 == 0) x = 1, y = i / 2 + 1;
                else x = i / 2 + 1, y = 1;
                while (x <= N && y <= N) ++c, a[x][y] = c, x++, y++;
            }
            FOR(1,N,i) {
                FOR(1,N,j) cout << a[i][j] << " ";
                cout << "\n";
            }
        }
    }


    return 0;
}
