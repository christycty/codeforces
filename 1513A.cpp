#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
typedef long long ll;
typedef pair<int,int> PII;

ll N, K, t, t1, T;

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> K;
        if (K > (N - 1) / 2){
            cout << "-1\n";
            continue;
        }
        t = 1;
        FOR(1,N,i) {
            if (K > 0 && i % 2 == 0) {
                cout << N - K + 1 << " ";
                --K;
            }
            else {
                cout << t << " ";
                ++t;
            }
        }
        cout << "\n";
    }
    return 0;
}
