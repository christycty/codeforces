#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, T;
bool ok;

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        ok = 0;
        ok = (N%2==0) && ((int)sqrt(N/2) * (int)sqrt(N/2) == (N / 2));
        ok |= (N%4==0) && ((int)sqrt(N/4) * (int)sqrt(N/4) == (N / 4));
        cout << (ok  ? "YES\n" : "NO\n");
    }
    return 0;
}
