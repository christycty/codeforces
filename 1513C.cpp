#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> PII;

ll N, M, T, c[200025][10], a[200025], t;
string n;

int main() {
    c[0][0] = 1;
    FOR(1,10000,i) {
        c[i][0] = c[i-1][9];
        FOD(9,1,j) c[i][j] = c[i-1][j-1];
        c[i][1] = (c[i][1] + c[i][0]) % MOD;
    }
    cin >> T;
    while (T--) {
        cin >> n >> M;
        t = 0;
        for (auto i : n) {
            t += a[i-'0'+M];
            t %= MOD;
        }
        /*cin >> N >> M;
        t = 0;
        while (N > 0) {
            t += a[N%10+M];
            t %= MOD;
            N /= 10;
        }*/
        cout << t << "\n";
    }
    return 0;
}
