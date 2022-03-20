#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
typedef long long ll;

ll T, N, K;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        if (N % 2 == 1) {
            cout << "1 " << N / 2 << " " << N / 2 << "\n";
        }
        else if (N % 3 == 0) {
            cout << N / 3 << " " << N / 3 << " " << N / 3 << "\n";
        }
        else if (N % 4 == 2) {
            cout << "2 " << (N-2) / 2 << " " << (N - 2) / 2 << "\n";
        }
        else {
            cout << N / 4 << " " << N / 4 << " " << N / 2 << "\n";
        }
    }


    return 0;
}
