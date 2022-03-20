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

ll T, A, B, C, X, Y;
ll a[] = {1, 1, 11, 101, 1009, 10007, 100003, 1000003, 10000019, 100000007};
ll b[] = {1, 1, 13, 103, 1013, 10009, 100019, 1000033, 10000079, 100000037};

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> A >> B >> C;
        X = a[C] * a[A-C+1];
        Y = a[C] * b[B-C+1];
        cout << X << " " << Y << "\n";
    }
    return 0;
}
