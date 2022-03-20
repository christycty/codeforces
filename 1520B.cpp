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

ll T;
string N;
ll c, tt, s, ld;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N;
        s = (N.length() - 1) * 9;

        tt = N[0] - '0';
        ld = 1;
        for (auto i : N) {
            if (i > N[0]) break;
            else if (i < N[0]) ld = 0;
        }
        if (ld) s += tt;
        else s += tt - 1;

        cout << s << "\n";
    }


    return 0;
}
