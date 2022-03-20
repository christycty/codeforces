#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;

int N, T, a[6];
bool ok;
bool st[6];

void f(int x){
    if (ok) return;
    if (x > 4) {
        st[0] = st[4];
        st[5] = st[1];
        bool ok1 = 1;
        FOR(1,4,i){
            if (st[i] + st[i+1] > a[i]
            || a[i] > N - 2 + st[i] + st[i+1]) {
                ok1 = 0;
                break;
            }
        }
        ok = ok || ok1;
        return;
    }
    st[x] = 0;
    f(x + 1);
    st[x] = 1;
    f(x + 1);
}

int main(){
    cin >> T;
    while (T--) {
        cin >> N;
        FOR(1,4,i) cin >> a[i];
        ok = 0;
        f(1);
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
