#include<bits/stdc++.h>
using namespace std;

int t, n, m, x[2];
bool e[1005][1005]; //a = 0, b = 1
int in[1005][2], ot[1005][2];
string s;

int main(){
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> t;
    while (t--){
        cin >> n >> m;
        for (int i = 1; i <= n; ++i){
            cin >> s;
            for (int j = 1; j <= n; ++j) e[i][j] = (1 ? s[j-1] == 'b' : 0);
        }
        if (m % 2 == 1){
            cout << "YES\n";
            for (int i = 1; i <= m + 1; ++i) cout << i % 2 + 1 << " ";
            cout << "\n";
            continue;
        }
        x[0] = x[1] = -1;
        for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
        if (e[i][j] == e[j][i]){
            x[0] = i, x[1] = j;
            break;
        }
        if (x[0] != -1){
            cout << "YES\n";
            for (int i = 1; i <= m + 1; ++i) cout << x[i % 2] << " ";
            cout << "\n";
            continue;
        }

        memset(in, 0, sizeof(in));
        memset(ot, 0, sizeof(ot));
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            if (i == j) continue;
            in[j][e[i][j]] = i;
            ot[i][e[i][j]] = j;
        }
        int a = -1, b, c;
        for (int i = 1; i <= n; ++i){
            if (in[i][0] != 0 && ot[i][0] != 0)
                a = in[1][0], b = i, c = ot[i][0];
            if (in[i][1] != 0 && ot[i][1] != 0)
                a = in[1][1], b = i, c = ot[i][1];
        }
        if (a == -1){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        if (m % 4 == 2){
            for (int i = 1; i <= m + 1; ++i){
                if (i % 2 == 0) cout << b;
                else if (i <= m / 2) cout << a;
                else cout << c;
                cout << " ";
            }
        }
        else{
            cout << b << " ";
            for (int i = 1; i <= m; ++i){
                if (i % 2 == 0) cout << b;
                else if (i <= m / 2) cout << a;
                else cout << c;
                cout << " ";
            }
        }
    }
    return 0;
}

/*
m % 2 == 0
*/
