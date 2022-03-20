#include <bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;

string s;
char c;
int T, ct;
ll L, R, a, ans;

void f(ll x) {
    if (x >= L && x <= R)
        ans = max(ans, (x / a) + (x % a));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> L >> R >> a;
        ans = 0;
        f(L), f(R), f(R-1), f(L+1);
        
        f(((R / a) - 1) * a - 1);
        f(((R / a) - 1) * a + a - 1);
        f(ceil(L / a) * a - 1);
        f(((L / a) + 1) * a - 1);

        cout << ans << '\n';
    }
}