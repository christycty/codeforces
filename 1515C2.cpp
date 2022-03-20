#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;
typedef pair<ll,int> PLI;

struct building {
    int id, tw;
    ll h;
};

ll N, T, M, x;
building b[100005];
PLI t;

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
        priority_queue<PLI, vector<PLI>, greater<PLI>> pq;
        FOR(1,M,i) pq.push({0, i});
        FOR(1,N,i) {
            t = pq.top();
            pq.pop();
            b[i].tw = t.second;
            t.first += b[i].h;
            pq.push(t);
        }
        sort(b + 1, b + 1 + N, cmpid);
        cout << "YES\n";
        FOR(1,N,i) cout << b[i].tw << " ";
        cout << "\n";
    }
    return 0;
}
