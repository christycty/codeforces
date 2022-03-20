#include <bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)

int N, a[100], ct;
char c;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    ct = 0;
    FOR(1,N,i) {
        cin >> c;
        if (c == '2' || c == '3' || c == '5' || c == '7') a[++ct] = (int)c - 48;
        else if (c == '4') a[++ct] = 3, a[++ct] = 2, a[++ct] = 2;
        else if (c == '6') a[++ct] = 3, a[++ct] = 5;
        else if (c == '8') a[++ct] = 7, a[++ct] = 2, a[++ct] = 2, a[++ct] = 2;
        else if (c == '9') a[++ct] = 7, a[++ct] = 3, a[++ct] = 3, a[++ct] = 2;
    }
    sort (a + 1, a + 1 + ct, greater<int>());
    FOR(1,ct,i) cout << a[i];
}
/*
by digit see can how expand
2 -> 2
3 -> 3
4 -> 3! * 2! * 2!
5 -> 5
6 -> 5 * 3
7 -> 7
8 -> 7 * 2 * 2 * 2
9 -> 7 * 3! * 3! * 2!
*/
