#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int q;
int n;
string a, b;

void solve(){
    cin >> n;
    cin >> a >> b;
    string ra, rb;
    for (int i=0;i<n;i++){
        if (a[i] != b[i]){
            ra.pb(a[i]);
            rb.pb(b[i]);
        }
    }
    int m = ra.length();
    bool ok = 1;
    for (int i=0;i<m;i++){
        if (rb[i] != ra[(i + 1) % m]){
            ok = 0;
            break;
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