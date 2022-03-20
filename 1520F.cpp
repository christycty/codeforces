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

ll N, T, L, R, K, res, mid;

int main() {
    //ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> N >> T >> K;
    L = 1, R = N;
    while (L < R) {
        mid = (L + R) / 2;
        cout << "? 1 " << mid << "\n";
        fflush(stdout);
        cin >> res;
        if (mid - res >= K) R = mid;
        else L = mid + 1;
    }
    cout << "! " << R << "\n";
    return 0;
}
