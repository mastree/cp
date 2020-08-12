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

const string SAD = "SD", FLIP = "AEIUO";

const ll MOD = 1e9 + 7;
constexpr int SZ = 2;

void mult(matrix& ret, const matrix& a, const matrix& b){
    ret = {{0, 0}, {0, 0}};
    for (int i=0;i<SZ;i++){
        for (int j=0;j<SZ;j++){
            for (int k=0;k<SZ;k++){
                ret[i][k] = (ret[i][k] + a[i][j] * b[j][k]) % MOD;
            }
        }
    }
}

const matrix msad = {
    {0, 1},
    {0, 1}
};
const matrix mflip = {
    {0, 1},
    {1, 0}
};
const matrix mhappy = {
    {1, 0},
    {1, 0}
};
const matrix iden = {
    {1, 0},
    {0, 1}
};
const matrix sabeb = {
    {19, 7},
    {6, 20}
};

matrix getmatrix(char cc){
    if (cc == 'H') return mhappy;
    if (cc == '?') return sabeb;
    for (auto x : SAD){
        if (cc == x) return msad;
    }
    for (auto x : FLIP){
        if (cc == x) return mflip;
    }
    return iden;
}

const int N = 2e5 + 10;

matrix t[4 * N];
int n, q;
string ar;

void build(int v, int tl, int tr){
    if (tl == tr){
        t[v] = getmatrix(ar[tl]);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    mult(t[v], t[v * 2], t[v * 2 + 1]);
}
int pos;
char val;
void update(int v, int tl, int tr){
    if (pos < tl || tr < pos) return;
    else if (tl == tr){
        t[v] = getmatrix(val);
        return;
    }
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm);
    update(v * 2 + 1, tm + 1, tr);
    mult(t[v], t[v * 2], t[v * 2 + 1]);
}
ll ask(){
    return t[1][0][0];
}

void solve(){
    cin >> n >> q;
    cin >> ar;
    ar = "*" + ar;

    for (int i=0;i<n * 4;i++){
        t[i].resize(SZ, vector<ll>(SZ));
    }
    build(1, 1, n);
    cout << ask() << el;
    while (q--){
        cin >> pos >> val;
        update(1, 1, n);
        cout << ask() << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}