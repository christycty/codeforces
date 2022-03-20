#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> PII;

ll N, T, c1, c2, c3, r[55];
bool ap;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N;
        c1 = c2 = c3 = 0;
        ap = 0;
        FOR(1,N,i){
            cin >> r[i];
            if (r[i] == 1 || r[i] == 3)  c1++;
        }
        cout << c1 << "\n";
    }
    return 0;
}
