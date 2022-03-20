#include<bits/stdc++.h>
using namespace std;

int t, n, m, culm;
int a[100005], b[100005], c[100005];
int cm[100005];
bool ok;
queue<int> q[100005];

int main(){
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> t;
    while (t--){
        cin >> n >> m;
        memset(cm, 0, sizeof(cm));
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        for (int i = 1; i <= m; ++i){ cin >> c[i]; cm[c[i]]++; }

        ok = 0;
        for (int i = 1; i <= n; ++i) if (b[i] == c[m]) ok = 1;
        for (int i = 1; i <= n; ++i) if (a[i] != b[i]) --cm[b[i]];
        for (int i = 1; i <= n; ++i) if (cm[i] < 0) ok = 0;
        if (!ok){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        int lst = -1;
        for (int i = n; i >= 1; --i) if (a[i] != b[i] && b[i] == c[m]){
            lst = i;
            break;
        }
        if (lst == -1) for (int i = 1; i <= n; ++i) if (b[i] == c[m]){
            lst = i;
            break;
        }
        for (int i = 1; i <= n; ++i) if (a[i] != b[i]) q[b[i]+culm].push(i);
        for (int i = 1; i <= m; ++i){
            if (q[c[i]+culm].empty()) cout << lst << " ";
            else {
                cout << q[c[i]+culm].front() << " ";
                q[c[i]+culm].pop();
            }
        }
        cout << '\n';
        culm += m;
    }
    return 0;
}

