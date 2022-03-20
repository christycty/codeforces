#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define pair<int,int> PII;

int N, T;
string s, s1, s2;

bool pal(string st) {
    int N = st.length();
    FOR(0,N/2,i) if (st[i] != st[N-i-1]) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> s;
        bool chk = 0;
        for (auto i : s) if (i != 'a') chk = 1;
        s1 = s + 'a';
        s2 = 'a' + s;
        if (!pal(s1)) cout << "YES\n" << s1 << "\n";
        else if (!pal(s2)) cout << "YES\n" << s2 << "\n";
        else cout << "NO\n";
    }
    return 0;
}
