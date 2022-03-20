#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;

int N, Q;
int b[100005], c[2];

int main(){
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> N >> Q;
    FOR(1,N,i) cin >> b[i];
    FOR(1,N,i) c[b[i]]++;
    int t, x;
    FOR(1,Q,i){
        cin >> t >> x;
        if (t == 1) {
            b[x] = !b[x];
            c[b[x]]++;
            c[!b[x]]--;
        }
        else {
            cout << (x <= c[1] ? 1 : 0) << "\n";
        }
    }
    return 0;
}
