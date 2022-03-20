#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)

int N, T;
long long a, b, c, d;

int ct(int x, int y){
    int k = 0;
    FOR(1,x,i) FOR(1,y,j) if (i/j==i%j) ++k;
    return k;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--){
        cin >> a >> b;
        //cout << ct (a, b) << " ";
        //a = min(a, (b + 1) * (b + 1));
        if (b < 2) c = 0;
        else c = min(b + 1, a) - 2;  // N - 1

        d = min(b, a / 2 - 1);
        FOR(2,d,i){
            if (a >= i * i) c += i - 2;
            else c += a / (i + 1) - 1;
        }
        cout << c << "\n";
    }
    return 0;
}
/*
#factors smaller than sqrt?


and N - 1
= min(b + 1, a)
*/
