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

const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;

struct Matrix{
    ll mat[2][2] = {{0, 0}, {0, 0}};
    Matrix() {}
    Matrix(bool iden){
        if (iden){
            mat[0][0] = mat[1][1] = 1;
        } else{
            mat[0][0] = mat[0][1] = mat[1][0] = 1;
        }
    }

    Matrix operator*(const Matrix& other){
        Matrix ret;
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                for (int k=0;k<2;k++){
                    ret.mat[i][k] = (ret.mat[i][k] + mat[i][j] * other.mat[j][k]);
                }
            }
        }
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                ret.mat[i][j] %= MOD;
            }
        }
        return ret;
    }
    Matrix operator+(const Matrix& other){
        Matrix ret;
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                ret.mat[i][j] = (mat[i][j] + other.mat[i][j]);
                if (ret.mat[i][j] >= MOD) ret.mat[i][j] -= MOD;
            }
        }
        return ret;
    }
};
int n, m;
ll ar[N];

Matrix simp[51];
Matrix getfib(ll a){
    Matrix ret(true);
    for (int i=0;i<51;i++){
        ll bit = (1LL << i);
        if (a & bit){
            ret = ret * simp[i];
        } else if (a < bit) break;
    }
    return ret;
}

Matrix t[4 * N];
ll lazy[4 * N];
void build(int v, int tl, int tr){
    if (tl == tr){
        t[v] = getfib(ar[tl] - 1);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = t[v * 2] + t[v * 2 + 1];
}
void push(int v){
    if (lazy[v]){
        Matrix temp = getfib(lazy[v]);
        t[v * 2] = t[v * 2] * temp;
        t[v * 2 + 1] = t[v * 2 + 1] * temp;
        lazy[v * 2] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
    }
    lazy[v] = 0;
}
void update(int v, int tl, int tr, int l, int r, ll add){
    if (l > r || tr < l || r < tl) return;
    else if (l <= tl && tr <= r){
        t[v] = t[v] * getfib(add); 
        lazy[v] += add;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, r, add);
    update(v * 2 + 1, tm + 1, tr, l, r, add);
    t[v] = t[v * 2] + t[v * 2 + 1];
}
ll ask(int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return 0;
    else if (l <= tl && tr <= r){
        return t[v].mat[0][0];
    }
    push(v);
    int tm = (tl + tr) / 2;
    return (ask(v * 2, tl, tm, l, r) + ask(v * 2 + 1, tm + 1, tr, l, r)) % MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    simp[0] = Matrix(false);
    for (int i=1;i<51;i++){
        simp[i] = simp[i - 1] * simp[i - 1];
    }
    build(1, 1, n);
    while (m--){
        int tipe;
        cin >> tipe;
        if (tipe == 1){
            int l, r;
            ll add;
            cin >> l >> r >> add;
            update(1, 1, n, l, r, add);
        } else{
            int l, r;
            cin >> l >> r;
            cout << ask(1, 1, n, l, r) << el;
        }
    }

    return 0;
}