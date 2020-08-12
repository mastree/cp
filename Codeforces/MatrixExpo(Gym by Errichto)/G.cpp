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

const ll MOD = 1e9 + 7;

matrix mult(const matrix& a, const matrix& b){
    int n = a.size();
    matrix ret(n, vector<ll>(n, 0));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
                ret[i][k] = (ret[i][k] + a[i][j] * b[j][k] % MOD) % MOD;
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
    matrix ret(n, vector<ll>(n, 0));
    for (int i=0;i<n;i++){
        ret[i][i] = 1;
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

ll n;
ll k;
ll p, q, r;

void solve(){
    cin >> n >> k;
    vector<int> va(n), vc(n);
    for (int i=0;i<n;i++) cin >> va[i];
    for (int i=0;i<n;i++) cin >> vc[i];
    cin >> p >> q >> r;

    if (k < n){
        cout << va[k] << el;
        return;
    }

    int len = n + 6;
    matrix mat(len, vector<ll>(len, 0)), mat2(len, vector<ll>(len, 0));
    for (int i=0;i<n;i++){
        mat[0][i] = vc[i];
    }
    mat[0][n] = 1;
    mat[0][n + 2] = 1;
    mat[0][n + 5] = 1;

    for (int i=0;i<n - 1;i++){
        mat[i + 1][i] = 1;
    }
    mat[n][n] = 1;
    mat[n + 1][n + 1] = 1;
    mat[n + 2][n + 1] = 1;
    mat[n + 2][n + 2] = 1;
    mat[n + 3][n + 3] = 1;
    mat[n + 4][n + 3] = 1;
    mat[n + 4][n + 4] = 1;
    mat[n + 5][n + 3] = -1;
    mat[n + 5][n + 4] = 2;
    mat[n + 5][n + 5] = 1;

    for (int i=0;i<n;i++){
        mat2[i][i] = va[n - i - 1];
    }
    mat2[n][n] = p;
    mat2[n + 1][n + 1] = q;
    mat2[n + 2][n + 2] = 1LL * n * q % MOD;
    mat2[n + 3][n + 3] = r;
    mat2[n + 4][n + 4] = 1LL * (n + 1) * r % MOD;
    mat2[n + 5][n + 5] = 1LL * (1LL * n * n % MOD) * r % MOD;

    mat = matexpo(mat, k - n + 1);
    mat2 = mult(mat, mat2);
    ll ans = 0;
    for (int i=0;i<len;i++){
        ans = (ans + mat2[0][i]) % MOD;
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}