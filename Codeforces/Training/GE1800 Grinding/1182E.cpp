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

const int MOD = 1e9 + 7;

matrix basef = {
    {0, 0, 1},
    {0, 1, 0},
    {1, 0, 0}
};
matrix matf = {
    {1, 1, 1},
    {1, 0, 0},
    {0, 1, 0}
};
matrix basec = {
    {0},
    {0},
    {0},
    {0},
    {2}
};
matrix matc = {
    {1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1}
};

ll n, c;
ll f[3];

matrix mult(const matrix& a, const matrix& b){
    assert(a[0].size() == b.size());
    int n = a.size();
    int m = b.size();
    int l = b[0].size();
    matrix ret(n, vector<ll>(m, 0));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            for (int k=0;k<l;k++){
                ret[i][k] = (ret[i][k] + a[i][j] * b[j][k]) % (MOD - 1);
            }
        }
    }
    return ret;
}
matrix matexpo(matrix a, ll b){
    assert(a.size() == a[0].size());
    int n = a.size();
    matrix ret(n, vector<ll>(n, 0));
    for (int i=0;i<n;i++) ret[i][i] = 1;
    while (b){
        if (b & 1){
            ret = mult(ret, a);
        }
        b >>= 1;
        a = mult(a, a);
    }
    return ret;
}
ll fpow(ll a, ll b){
    ll ret = 1;
    while (b){
        if (b & 1){
            ret = ret * a % MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<3;i++) cin >> f[i];
    cin >> c;
    matrix ff = mult(matexpo(matf, n - 3), basef);
    matrix cc = mult(matexpo(matc, n - 3), basec);
    ll ret = fpow(c, cc[0][0]);
    for (int i=0;i<3;i++){
        ret = ret * fpow(f[i], ff[0][i]) % MOD;
    }
    cout << ret << el;

    return 0;
}