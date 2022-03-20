#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)
#define FOD(s,e,i) for (int i = s; i >= e; --i)
typedef long long ll;

int N, T, M, ida, idb, t, TN, TM;
ll a[200005], b[200005], ta[200005], tb[200005], c[200005];
ll ans, ans2;

void init(){
    cin >> TN >> TM;
    ans = ans2 = 0;
    ida = TN + 1;
    idb = TM + 1;
    FOR(1,TN,i) {
        cin >> ta[i];
        if (ida > TN && ta[i] > 0) ida = i;
    }
    FOR(1,TM,i) {
        cin >> tb[i];
        if (idb > TM && tb[i] > 0) idb = i;
    }
}

void run(ll &as) {
    int j = M;
    c[N+1] = 0;
    FOD(N,1,i) {
        c[i] = c[i+1];
        while (j > 1 && b[j] > a[i]) j--;
        if (a[i] == b[j]) c[i]++;
    }
   // FOR(1,N,i) cout << a[i] << " "; cout << "\n";
   // FOR(1,M,i) cout << b[i] << " "; cout << "\n";
    as = c[1];  //no walk
    int R = 1;  //L, R = index of first and last special positions occupied by the pile
    int fx = 1; //index of first unmoved box
    FOR(1,M,L) {
        while (fx <= N && b[L] + fx - 2 >= a[fx]) ++fx;     //b[L] + fx - 2 < a[fx] -> ok
        while (R <= M && b[R] - b[L] + 1 <= fx - 1) ++R;
        as = max(as, R - L + c[fx]);
        //cout << "L " << L << " R " << R << " fx " << fx << " ans " << as << "\n";
    }
    return;
}

int main(){
    //ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        init();

        N = M = 0;
        FOR(ida,TN,i) a[i-ida+1] = ta[i], ++N;
        FOR(idb,TM,i) b[i-idb+1] = tb[i], ++M;
        run(ans);

        N = M = 0;
        FOD(ida-1,1,i) a[ida-i] = -ta[i], ++N;
        FOD(idb-1,1,i) b[idb-i] = -tb[i], ++M;
        run(ans2);

        cout << ans + ans2 << "\n";
    }
    return 0;
}
