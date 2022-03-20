#include<bits/stdc++.h>
using namespace std;

int t, n, k, c, mx;
int h[105];

int main(){
    cin >> t;
    while (t--){
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> h[i];
        c = 0;
        mx = h[n];
        for (int i = n - 1; i >= 1; --i){
            c += (mx > h[i] ? mx - h[i] : 0);
            mx = max(mx, h[i]);
        }
        if (k > c) cout << "-1\n";
        else{
            for (int i = 1; i <= k; ++i){
                for (int j = 1; j < n; ++j)
                    if (h[j] < h[j+1]){
                        ++h[j];
                        if (i == k) cout << j << "\n";
                        break;
                    }
            }
        }
    }
    return 0;
}
