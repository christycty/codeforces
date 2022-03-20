#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;

struct building {
    int id, tw;
    ll h;
};

ll N, T, M, x, t, mn, mx;
building b[100005];
ll ct[100005];

bool cmph(building & t1, building & t2) {
    return t1.h < t2.h;
}

bool cmpid(building & t1, building & t2) {
    return t1.id < t2.id;
}


int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M >> x;
        FOR(1,N,i) {
            b[i].id = i;
            cin >> b[i].h;
        }
        sort(b + 1, b + 1 + N, cmph);
        t = 1;
        FOR(1,N/(2*M),i){
            FOR(1,M,j) b[t].tw = j, ++t;
            FOD(M,1,j) b[t].tw = j, ++t;
        }
        if (N % (2 * M) >= M) {
            FOR(1,M,j) b[t].tw = j, ++t;
        }

        FOD(N%M,1,i) b[t].tw = i, ++t;

       // FOR(1,N,i) cout << b[i].tw << " "; cout << "\n";

        sort(b + 1, b + 1 + N, cmpid);

        memset(ct, 0, sizeof(ct));
        FOR(1,N,i) ct[b[i].tw] += b[i].h;
        mn = mx = ct[1];
        FOR(1,M,i) mn = min(mn, ct[i]), mx = max(mx, ct[i]);
        if (mx - mn > x) cout << "NO\n";
        else {
            cout << "YES\n";
            FOR(1,N,i) cout << b[i].tw << " ";
            cout << "\n";
        }
    }
    return 0;
}
