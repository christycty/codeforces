#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
typedef long long ll;

ll N, a[200005], T;
ll mn, id;

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        FOR(1,N,i) cin >> a[i];
        sort(a + 1, a + 1 + N);
        mn = a[2] - a[1];
        id = 1;
        FOR(2,N-1,i){
            if (abs(a[i+1]-a[i]) < mn){
                mn = abs(a[i+1] - a[i]);
                id = i;
            }
        }
        cout << a[id] << " ";
        FOR(id+2,N,i) cout << a[i] << " ";
        FOR(1,id-1,i) cout << a[i] << " ";
        cout << a[id+1] << "\n";
    }
    return 0;
}
