#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
#define pair<int,int> PII;

int N, T, c, ct[300005];
string a, b;
bool ok;

int main(){
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N >> a >> b;
        memset(ct, 0, sizeof(ct));
        FOR(0,N-1,i) {
            ct[i] = ct[i-1];
            if (a[i] == '0') ct[i]--; else ct[i]++;
        }
        c = 0;
        ok = 1;
        FOD(N-1,0,i) {
            if ( char ((a[i]-'0'+c) % 2 + '0') != b[i] ) {    // need swap
                if (ct[i] == 0) {
                    c++;
                }
                else {
                    ok = 0;
                    break;
                }
           }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
