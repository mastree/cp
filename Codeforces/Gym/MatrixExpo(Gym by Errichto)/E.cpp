#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;

using matrix = vector<vector<ll>>;

const ll MOD = 4294967296;

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

const int N = 8;

int getid(int a, int b){
    return a * N + b; 
}
pii getpos(int id){
    int a = id / N;
    int b = id % N;
    return mp(a, b);
}

int di[N] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dj[N] = {-1, 1, -2, 2, -2, 2, -1, 1};

ll k;
matrix mat(65, vector<ll>(65, 0));

void init_mat(){
    for (int i=0;i<=N * N;i++){
        mat[N * N][i] = 1;
    }
    for (int i=0;i<N * N;i++){
        pii cur = getpos(i);
        int r = cur.fi;
        int c = cur.se;
        for (int j=0;j<N;j++){
            int nr = r + di[j];
            int nc = c + dj[j];
            if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
            int ni = getid(nr, nc);
            mat[i][ni] = 1;
        }
    }
}

void solve(){
    cin >> k;
    init_mat();
    mat = matexpo(mat, k + 1);
    cout << mat[N * N][0] << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}