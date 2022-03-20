#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int,int> PII;
typedef pair<double, double> PDD;

int T;
double ans, slp1, slp2;
PDD c[3];

double slope(PDD a, PDD b) {
    if (x1 - x2 == 0) return -1;
    else return (y2 - y1) / (x2 - x1);
}

int main() {
    cin >> T;
    while (T--) {
        for (int i = 0; i < 3; ++i) cin >> c[i].fi >> c[i].se;
        sort(c, c + 3);
        slp1 = slope(c[0].fi, c[0].se, c[2].fi, c[2].se);
        slp2 = slope(c[0].fi, c[0].se, c[1].fi, c[1].se);
        if (slp1 < slp2) ans = dis()
    }

}