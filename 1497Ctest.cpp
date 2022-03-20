#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
typedef long long ll;

ll T, N, K;

int hcf(int a, int b) {
    if (b == 0) return a;
    return hcf(b, a % b);
}

int LCM(int a, int b) {
    return a * b / hcf(max(a, b), min(a, b));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    FOR(3,50,i){
        if (i % 2) continue;
        FOR(1,i/2,j) FOR(j,i/2,k) {
            if (j + k != i && LCM(j,LCM(k,i-j-k)) <= i / 2)
                cout << i << " " << j << " " << k << " " << i-j-k << "\n";
        }
    }
    FOR(3,100,i) {
        int N = i;
        if (N % 2 == 1) {
            cout << "1 " << N / 2 << " " << N / 2 << "\n";
        }
        else if (N % 3 == 0) {
            cout << N / 3 << " " << N / 3 << " " << N / 3 << "\n";
        }
        else if (N % 4 == 2) {
            cout << "2 " << (N-2) / 2 << " " << (N - 2) / 2 << "\n";
        }
        else if (N % 4 == 0) {
            cout << N / 4 << " " << N / 4 << " " << N / 2 << "\n";
        }
        else cout << "!!!!!!!!!!!! " << i << "\n";
    }
    return 0;
}
