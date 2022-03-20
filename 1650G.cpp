#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
typedef pair<int,int> PII;
#define MOD 1000000007
#define inf 0x3f3f3f3f
typedef long long ll;
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second

ll T, N, M, s, e, t1, t2;
PII t3;
vector<int> ed[200005];
ll d[200005][2], dist[200005];
bool v[200005], v2[200005][2];
string st;

void reset() {
    FOR(1,N,i) ed[i].clear();
    memset(d, 0, sizeof(d));
    memset(v, 0, sizeof(v));
    memset(v2, 0, sizeof(v2));
    FOR(1,N,i) dist[i] = inf;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> T;
    while (T--) {
        getline(cin, st);
        cin >> N >> M >> s >> e;
        reset();
        FOR(1,M,i) {
            cin >> t1 >> t2;
            ed[t1].eb(t2), ed[t2].eb(t1);
        }
        dist[s] = 0, v[s] = 1;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            t1 = q.front();
            //if (t1 == e) break;
            q.pop();
            for (auto i : ed[t1]) {
                if (v[i]) continue;
                v[i] = 1;
                dist[i] = dist[t1] + 1;
                q.push(i);                
            }
        }
        //FOR(1,N,i) cout << "dist " << dist[i] << " "; cout << "\n";
        queue<PII> q2;
        
        q2.push(mp(s, 0));
        d[s][0] = 1;
        while (!q2.empty()) {
            t3 = q2.front();
            q2.pop(); 
            if (v2[t3.fi][t3.se]) continue;
            v2[t3.fi][t3.se] = 1;
            for (auto i : ed[t3.fi]) {
                // ok: dist[t3.fi]+1 == sp (sp path)
                if (dist[t3.fi] + 1 + t3.se == dist[i]) {
                    d[i][0] = (d[i][0] + d[t3.fi][t3.se]) % MOD;
                    q2.push( mp(i, 0) );
                }
                else if (dist[t3.fi] + 1 + t3.se == dist[i] + 1) {
                    d[i][1] = (d[i][1] + d[t3.fi][t3.se]) % MOD;
                    q2.push( mp(i, 1));
                }
            }
        }
        //FOR(1,N,i) cout << "d[i] " << d[i][0] << " " << d[i][1] << "\n";
        cout << (d[e][0] + d[e][1]) % MOD << "\n";
    }
    return 0;
}

/*
sp = shortest path
observation:
1) no repeated edge (since repeat edge += 2 >= sp + 2 --> must > sp + 1)
2) only sp and sp+1 possibility

(1) find sp for all nodes (basic bfs) --> dist[i]

d[i][j] = #path from node s to i with sp[i]+j steps, j = 0/1
(2) bfs again to compute d[i][j]
    - push pair(i,j) into queue (treat separately)
    - check sp(neighbour)+0/1 == cur_step(sp+0/1) -> push neighbour (0/1)

ans = d[e][0] + d[e][1]
*/