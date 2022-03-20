#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)

int N, Q, K;
int a[100005], l, r, x;
int c[100005];

int main(){
    cin >> N >> Q >> K;
    FOR(1,N,i) cin >> a[i];
    FOR(2,N,i) c[i] = c[i-1] + a[i] - a[i-1] - 1;
    FOR(1,Q,i){
        cin >> l >> r;
        if (l == r){
            cout << K - 1 << "\n";
            continue;
        }
        cout << (a[l] - 1) + (c[r] - c[l]) * 2 + (K - a[r]) << "\n";
    }
    return 0;
}
