#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;

ll T, N, cur, c = 0;
ll s[5015], d[5015];

int main(){
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N;
        FOR(1,N,i) cin >> s[i];
        memset(d, 0, sizeof(d));  //difference array
        cur = 0, c = 0;
        FOR(1,N,i){
            cur += d[i];
            cout << i << " " << cur << " " <<d[i] << ":\n";
            // pass on
            if (cur > 0) {
                d[max((ll)i + 1, i + s[i] - cur + 1)]++;
                d[min(N + 1, i + s[i] + 1)]--;
                cout << "ps " << i+s[i]-cur+1 << " " << i+s[i]+1 << "\n";
            }
            s[i] -= cur;
            //need new jump
            if (s[i] > 1) {
                c += s[i] - 1;
                d[i + 2]++;
                d[min(N + 1, i + s[i] + 1)]--;
                cout << "nw " << s[i] << " " << i+2 << " " << i+s[i]+1 << "\n";
            }

        }
        cout << c << "\n";
    }
    return 0;
}

