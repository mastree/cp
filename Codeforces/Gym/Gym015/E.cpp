#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

typedef vector<vector<bool>> Matrix;

Matrix mult(const Matrix& a, const Matrix& b){
    int n = a[0].size();
    Matrix ret(n, vector<bool>(n, 0));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
                ret[i][k] = (ret[i][k] || (a[i][j] && b[j][k]));
            }
        }
    }
    return ret;
}

Matrix matexpo(Matrix a, int b){
    int n = a[0].size();
    Matrix ret(n, vector<bool>(n, 0));
    for (int i=0;i<n;i++) ret[i][i] = 1;
    while (b){
        if (b & 1){
            ret = mult(ret, a);
        }
        a = mult(a, a);
        b >>= 1;
    }
    return ret;
}

const int N = 60;

int q;
int n, m, k;

void solve(){
    cin >> n >> m >> k;

    Matrix mat(n, vector<bool>(n, 0));
    for (int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    Matrix res = matexpo(mat, k);
    int ans = 0;
    for (int i=0;i<n;i++){
        if (res[i][i]) ans++;
    }
    cout << ans << el;
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