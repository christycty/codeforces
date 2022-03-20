#include <bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;
typedef pair<ll,ll> PLL;
typedef pair<ll,pair<ll,ll>> PLLL;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
#define fi first 
#define se second
#define mp make_pair
#define eb emplace_back
#define inf 0x3f3f3f3f

int T, N, L, R;
int p[200005], l[200005];
string ans;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        FOR(1,N,i){
            cin >> p[i];
            l[p[i]] = i;;
        } 
        ans = "1";
        L = R = l[1];
        FOR(2,N,i) {
            L = min(L, l[i]);
            R = max(R, l[i]);
            if (R - L + 1 == i) ans += "1"; else ans += "0";
        }
        cout << ans << "\n";
    }
} 