#include <bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;

string s;
char c;
int T, ct;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> s >> c;
        int ok = 0;
        FOR(0,s.length(),i) {
            if (s[i] == c && i % 2 == 0) ok = 1;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}