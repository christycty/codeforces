#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define inf 10000000000
typedef long long ll;

int N;
ll a[2005], dp[2005][2005];

int main(){
    cin >> N;
    FOR(1,N,i) cin >> a[i];
    sort (a + 1, a + 1 + N);
    //FOR(0,N+1,i) FOR(0,N+1,j) dp[i][j] = inf;
    FOR(1,N,i) dp[i][i] = 0;
    FOR(1,N,i) FOR(1,N-i+1,j)
        dp[j][j+i-1] = a[j+i-1] - a[j] + min(dp[j+1][j+i-1], dp[j][j+i-2]);
    cout << dp[1][N] << "\n";
    return 0;
}

