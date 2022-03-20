#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)

long long N, c, t;

int main() {
    cin >> N;
    FOR(1,N,i) {
        cin >> t;
        c += t - 1;
        cout << (c % 2 == 1 ? 1 : 2) << "\n";
    }
}
