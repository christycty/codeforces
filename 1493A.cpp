#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
#define eb emplace_back
typedef long long ll;

int N, K, T;
ll c;

int main(){
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        if (N > K) {
            FOD(N,K+1,i) ans.eb(i);
        }
        if (N > K) c = N - K + (K + 1) / 2 - 1;
        else c = (K + 1) / 2 - 1;
        cout << c << "\n";
    }

    return 0;
}
