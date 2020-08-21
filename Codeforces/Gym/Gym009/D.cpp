#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e3, P2 = 60, P3 = 38;
const ll BORD = 1e18;

int q;
// ll n;
ll pow2[P2], pow3[P3];
vector<int> adj[N];
ll dist[N][N];
vector<pii> actNode; // id, val



int getid(int a, int b){
    return a + b * P2 + 2;
}
int getid(pii a){
    return getid(a.fi, a.se);
}

bool is_valid(int i, int j){
    return ((BORD + pow2[i] - 1) / pow2[i] > pow3[j]);
}
ll hitung(int i, int j) { return pow2[i] * pow3[j]; }

void solve(ll n){
    int i = P2 - 1;

    if (n == 1LL){
        cout << 1 << el << 1 << el;
        return;
    }

    vector<ll> ans;
    for (int j=(int)(n % 2);j<P3;j++){
        if (n == 1){
            ans.pb(1);
            break;
        }
        int ni = i;
        if (ni < 0) break;
        while (!is_valid(ni, j)){
            ni--;
        }
        while (hitung(ni, j) > n) ni--;
        while (1){
            if ((n - hitung(ni, j)) % 3LL == 0) break;
            ni--;
            if (ni < 0) break;
        }
        if (ni < 0) continue;
        // if (hitung(ni, j) * (P3 - (ll)j) < n) continue;
        ans.pb(hitung(ni, j));
        n -= ans.back();
        i = ni - 1;
        if (n == 0) break;
    }
    cout << ans.size() << el;
    for (auto x : ans) cout << x << " "; cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // freopen("distribution.in", "r", stdin);
    // freopen("distribution.out", "w", stdout);

    pow2[0] = pow3[0] = 1;
    for (int i=1;i<P2;i++){
        pow2[i] = pow2[i - 1] * 2LL;
    }
    for (int i=1;i<P3;i++){
        pow3[i] = pow3[i - 1] * 3LL;
    }
    
    cin >> q;
    while (q--){
        ll n;
        cin >> n;

        solve(n);
    }

    return 0;
}