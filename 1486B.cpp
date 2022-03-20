#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
typedef long long ll;

int N, T;
ll x[1005], y[1005];
bool ok;

int main(){
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--){
        cin >> N;
        FOR(1,N,i) cin >> x[i] >> y[i];
        sort (x + 1, x + 1 + N);
        sort (y + 1, y + 1 + N);
        //FOR(1,N,i) cout << x[i] << " ";
        if (N % 2 == 1) cout << "1\n";
        else cout << (x[N/2+1]-x[N/2]+1) * (y[N/2+1]-y[N/2]+1) << "\n";
    }

    return 0;
}
