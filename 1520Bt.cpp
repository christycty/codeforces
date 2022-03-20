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


ll sol(ll k) {
    string N;
    stringstream ss;
    ll s, tt, ld;

    ss << k;
    ss >> N;

    s = (N.length() - 1) * 9;

    tt = N[0] - '0';
    ld = 1;
    for (auto i : N) {
        if (i > N[0]) break;
        else if (i < N[0]) ld = 0;
    }

    if (ld) s += tt;
    else s += tt - 1;

    return s;
}

int main() {
    //ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    ll N, T;
    ll c, tt, s;
    bool ok;

    FOR(1,1000,kk) {
        //cout << kk << "\n";
        N = kk;
        s = 0;
        FOR(1,N,i) {
            tt = i;
            ok = 1;
            c = tt % 10;
            while (tt > 0){
                if (tt % 10 != c) ok = 0;
                tt /= 10;
            }
            if (ok) ++s;
        }
        //cout << kk << "\n";
        if (s != sol(kk)) cout << kk << " " << s << " " << sol(kk) << "\n";
    }
    return 0;
}
