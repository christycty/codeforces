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

int N, T;
string s;
bool ch[30], ok;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N >> s;
        s = '-' + s;
        FOR(0,26,i) ch[i] = 0;
        ok = 1;
        FOR(1,N,i) {
            if (s[i] != s[i-1]) {
                if (!ch[s[i]-'A']) ch[s[i]-'A'] = 1;
                else ok = 0;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }


    return 0;
}
