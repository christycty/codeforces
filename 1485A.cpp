#include<bits/stdc++.h>
using namespace std;

int N, T;
int a, b, c;

int cal(int x, int y){
    int c = 0;
    while (x > 0) x /= y, ++c;
    return c;
}

int main(){
    cin >> T;
    while (T--){
        cin >> a >> b;
        c = 0;
        if (b == 1) ++b, ++c;
        while (a > 0){
            //cout << a << " " << b << " " << c << "\n";
            //cout << cal(a, b) << " " << cal(a, b+1) << "\n";
            if (cal(a, b) >= cal(a, b + 1) + 1) ++b;
            else a /= b;
            ++c;
        }

        cout << c << "\n";
    }
    return 0;
}

/*
# operations = ceil( log_b(a) )
ok iff b > a

*/
