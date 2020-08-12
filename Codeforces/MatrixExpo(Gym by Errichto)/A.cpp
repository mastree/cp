#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

using matrix = vector<vector<ld>>;

matrix mult(const matrix& a, const matrix& b){
    int n = a.size();
    matrix ret(n, vector<ld>(n, 0));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
                ret[i][k] += a[i][j] * b[j][k];
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
    matrix ret(n, vector<ld>(n, 0));
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
ld p;

ld solve(){
    matrix mat(2, vector<ld>(2));
    mat[1][1] = mat[0][0] = ld(1.0) - p;
    mat[1][0] = mat[0][1] = p;

    mat = matexpo(mat, n);
    return mat[0][0];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cout << fixed << setprecision(11);
    cin >> n >> p;
    cout << solve() << el;

    return 0;
}