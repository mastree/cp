#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int q;
int n;

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        int sisa = n * 2;
        while (sisa){
            int kur = min(sisa / 2, i);
            sisa -= kur * 2;
            for (int j=1;j<=kur;j++){
                cout << '(';
            }
            for (int j=1;j<=kur;j++){
                cout << ')';
            }
        }
        cout << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}