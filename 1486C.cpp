#include<bits/stdc++.h>
using namespace std;
#define FOR(s,e,i) for (int i = s; i <= e; ++i)

int N, tmp;
bool ok;

int f(int L, int R, int pos){
    //if (L >= R) return pos;
    if (L + 1 == R) return (pos == L ? R : L);  //2 left
    if (L + 2 == R){
        if (pos == L + 1) {
            cout << "? " << L << " " << L + 1 <<  "\n";
            fflush(stdout);
            cin >> tmp;
            if (tmp == pos) return L; else return R;
        }
        else {
            int t1, t2;
            if (pos == L) t1 = L + 1, t2 = R;
            else t1 = L, t2 = L + 1;
            cout << "? " << t1 << " " << t2 <<  "\n";
            fflush(stdout);
            cin >> tmp;
            return (tmp == t1 ? t2 : t1);
        }
    }
    int mid = (L + R) / 2;
    if (pos <= mid) {
        cout << "? " << L << " " << mid <<  "\n";
        fflush(stdout);
        cin >> tmp;
        if (tmp == pos) return f(L, mid, pos);
        else {
            cout << "? " << mid + 1 << " " << R <<  "\n";
            fflush(stdout);
            cin >> tmp;
            return f(mid + 1, R, tmp);
        }
    }
    else {
        cout << "? " << mid + 1 << " " << R <<  "\n";
        fflush(stdout);
        cin >> tmp;
        if (tmp == pos) return f(mid + 1, R, pos);
        else{
            cout << "? " << L << " " << mid <<  "\n";
            fflush(stdout);
            cin >> tmp;
            return f(L, mid, tmp);
        }
    }
}

int main(){
    cin >> N;
    cout << "? 1 " << N << "\n";
    fflush(stdout);
    cin >> tmp;
    int ans = f(1, N, tmp);
    cout << "! " << ans;
    fflush(stdout);
    return 0;
}

/*
1 2 3 4 5
1 5 4 2 3
3 5 2 4 1
5 4 3 2 1
6 2 4 5 1 3
2 5 6 4 1 3
*/
