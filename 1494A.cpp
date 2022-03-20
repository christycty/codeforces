#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;

int N, T;
string a, s;
int c1, c2;
bool ok, ok2;

int main(){
    cin >> T;
    while (T--) {
        cin >> a;
        ok = 0;
        FOR(0,2,i) {
            ok2 = 1;
            c1 = c2 = 0;
            for (auto j : a) {
                if (j - 'A' == i) c1++; else c2++;
                if (a[0] - 'A' != i && c1 > c2
                    || a[0] - 'A' == i && c2 > c1)
                        ok2 = 0;
            }
            if (c1 != c2) ok2 = 0;
            //cout << i << " " << ok2 << "\n";
            ok = (ok || ok2);
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
