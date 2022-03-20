#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)

int N, T, M, c1;
string a, b, s;
bool st;


int main(){
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N >> s;
        M = c1 = 0;
        for (auto i : s) M += (i - '0');
        if (M % 2 == 1 || s[0] == '0' || s[N-1] == '0') {
            cout << "NO\n";
            continue;
        }
        st = 0;
        a = b = "";
        FOR(0,N-1,i) {
            if (s[i] == '1') {
                c1++;
                if (c1 <= M / 2) a += '(', b += '(';
                else a += ')', b += ')';
            }
            else {
                if (st) a += '(', b += ')';
                else a += ')', b += '(';
                st = 1 - st;
            }
        }
        cout << "YES\n" << a << "\n" << b << "\n";
    }
    return 0;
}

