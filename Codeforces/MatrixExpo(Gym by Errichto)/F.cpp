#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

using matrix = vector<vector<ll>>;

const int N = 100;
const ll INF = (ll)1e18 + 10LL;

matrix mult(const matrix& a, const matrix& b){
    int n = a.size();
    matrix ret(n, vector<ll>(n, INF));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
                if (a[i][j] >= INF || b[j][k] >= INF) continue;
                ret[i][k] = min(ret[i][k], a[i][j] + b[j][k]);
            }
        }
    }
    return ret;
}

void printmat(const matrix& a){
    int n = a.size();
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << el;
    }
}

matrix matexpo(matrix a, ll b){
    int n = a.size();
    matrix ret(n, vector<ll>(n, INF));
    for (int i=0;i<n;i++){
        ret[i][i] = 0;
    }
    while (b){
        if (b & 1){
            ret = mult(ret, a);
        }
        b >>= 1;
        a = mult(a, a);
    }
    return ret;
}


int n, m;
ll k;

void solve(){
    cin >> n >> m >> k;
    matrix mat(n, vector<ll>(n, INF));
    for (int i=0;i<m;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        a--, b--;
        mat[a][b] = w;
    }
    mat = matexpo(mat, k);
    ll ans = INF;
    for (int i=0;i<n;i++){
        for (auto x : mat[i]) ans = min(ans, x);
    }
    if (ans >= INF){
        cout << "IMPOSSIBLE" << el;
    } else{
        cout << ans << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}