#include <bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;
typedef pair<ll,pair<ll,ll>> PLLL;
#define fi first 
#define se second
#define mp make_pair
#define inf 0x3f3f3f3f

ll T, N, pos, t1, t2, D, mn, mx;
ll tmp[200005], a[200005], ans;
string s;

ll f() {
    sort(tmp + 1, tmp + 1 + N);
    t1 = tmp[1] - 1;
    FOR(2,N,i) t1 = min(t1, tmp[i]-tmp[i-1] - 1);
    return t1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        getline(cin, s);
        cin >> N >> D;
        FOR(1,N,i) cin >> a[i];
        a[0] = 0;
        mn = 1, mx = 1;
        FOR(2,N,i) {
            if (a[i] - a[i-1] < a[mn]-a[mn-1]) mn = i;
            if (a[i] - a[i-1] > a[mx]-a[mx-1]) mx = i;
        }

        ans = a[mn] - a[mn-1] - 1;
        
        if (a[mx] > a[mx-1] + 1) {
            FOR(1,N,i) tmp[i] = a[i];
            tmp[mn] = (a[mx] + a[mx-1] + 1) / 2;
            ans = max(ans, f());
            
            if (mn - 1 > 0){
            FOR(1,N,i) tmp[i] = a[i];
            tmp[mn-1] = (a[mx] + a[mx-1] + 1) / 2;
            ans = max(ans, f());}
        }
        
        if (a[N] != D) {
            FOR(1,N,i) tmp[i] = a[i];
            tmp[mn] = D;
            ans = max(ans, f());

            if (mn - 1 > 0){
            FOR(1,N,i) tmp[i] = a[i];
            tmp[mn-1] = D;
            ans = max(ans, f());}
        }

        if (mn - 1 > 0) {
            FOR(1,N,i) tmp[i] = a[i];
            tmp[mn-1] = (a[mn] + a[mn-2] + 1) / 2;
            ans = max(ans, f());
        }

        
        FOR(1,N,i) tmp[i] = a[i];
        tmp[mn] = ((mn == N ?  D : a[mn+1]) + a[mn-1] + 1) / 2;
        ans = max(ans, f());
        
        
        cout << ans << "\n";
    }
}