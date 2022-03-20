#include<bits/stdc++.h>
using namespace std;

int t, x, y, cu, cd, cr, cl;
string s;
bool ok;

int main(){
    cin >> t;
    while (t--){
        cin >> x >> y >> s;
        cu = cd = cr = cl = 0;
        for (auto i : s){
            if (i == 'U') ++cu;
            else if (i == 'D') ++cd;
            else if (i == 'R') ++cr;
            else ++cl;
        }
        ok = 1;
        if (x < 0) ok = ok && (cl >= -x);
        else ok = ok && (cr >= x);
        //cout << ok << "\n";
        if (y < 0) ok = ok && (cd >= -y);
        else ok = ok && (cu >= y);
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
