#pragma gcc optimize ("O3")
#pragma gcc optimize ("unroll-loops")

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
const int N = 210, M = 30;

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

int n, m, q;
matrix mat[M];

ll calc(int s, int t, int k){
    vector<ll> ret(n, 0);
    ret[s] = 1;
    for (int bit=0;bit<M;bit++){
        if (k & (1 << bit)){
            vector<ll> temp(n, 0);
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    temp[j] = (temp[j] + ret[i] * mat[bit][i][j]) % MOD;
                }
            }
            ret.swap(temp);
        }
    }
    return ret[t];
}

void solve(){
    cin >> n >> m >> q;
    for (int i=0;i<M;i++) mat[i].resize(n, vector<ll>(n, 0));
    for (int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        mat[0][a - 1][b - 1] = 1;
    }
    for (int i=1;i<M;i++){
        mat[i] = mult(mat[i - 1], mat[i - 1]);
    }
    
    while (q--){
        int s, t, k;
        cin >> s >> t >> k;
        s--, t--;
        cout << calc(s, t, k) << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}