#include <bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;
typedef pair<ll,ll> PLL;

ll c[505], a[505];
ll T, N, tmp;
vector<PLL> ans;

bool check() {
    FOR(1,N,i) {
        tmp = 0;
        FOR(1,N,j) if (a[j] == a[i]) ++tmp;
        if (tmp % 2 != 0) {
            return false;
        }
    } 
    return true;
}

void f(int x, int y) {

}

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        FOR(1,N,i) cin >> a[i];
        if (!check()) {
            cout << "-1\n";
            continue;
        }
        ans.clear();
        memset(c, 0, sizeof(c));
        FOR(1,N,i) {
            tmp = i;
            FOR(i+1,N,j) if (a[j] < a[tmp]) tmp = j;
            f(i, tmp);
        }
        cout << ans.size() << "\n";
        
    }
}