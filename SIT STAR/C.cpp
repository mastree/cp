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
void solve(){
    int n, m, p;
    cin >> n >> m >> p;
    if (n > m) swap(n, m);
    // n < m
    bool ok = 0;
    for (int i=1;i * i<=p;i++){
        if (p % i == 0){
            int j = p / i;
            if (n >= i && m >= j){
                ok = 1;
                break;
            }
        }
    }
    if (ok) cout << "YES" << el;
    else cout << "NO" << el;
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