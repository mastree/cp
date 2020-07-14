#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
// #define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;

typedef vector<vector<ll>> matrix;

int n, q;
string s;

matrix idd(2, vector<ll>(2, 0));
matrix t[4 * N];
bool lazy[4 * N];

matrix mult(matrix b, matrix a){
    matrix ret(2, vector<ll>(2, 0));
    for (int i=0;i<2;i++){
        for (int k=0;k<2;k++){
            for (int j=0;j<2;j++){
                ret[i][j] += a[i][k] * b[k][j];
                ret[i][j] %= MOD;
            }
        }
    }

    return ret;
}

matrix bmat(ll a, ll b, ll c, ll d){
    matrix ret(2, vector<ll>(2));
    ret[0][0] = a % MOD;
    ret[0][1] = b % MOD;
    ret[1][0] = c % MOD;
    ret[1][1] = d % MOD;
    return ret;
}

matrix scont(matrix a){
    swap(a[0][0], a[1][1]);
    swap(a[0][1], a[1][0]);
    return a;
}

void build(int v, int tl, int tr){
    if (tl == tr){
        if (s[tl] == 'A'){
            t[v] = bmat(1, 1, 0, 1);
        } else{
            t[v] = bmat(1, 0, 1, 1);
        }
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = mult(t[v * 2], t[v * 2 + 1]);
}

void push(int v){
    if (lazy[v]){   
        lazy[v * 2] ^= 1;
        lazy[v * 2 + 1] ^= 1;
        t[v * 2] = scont(t[v * 2]);
        t[v * 2 + 1] = scont(t[v * 2 + 1]);
        lazy[v] = 0;
    } 
}

void update(int v, int tl, int tr, int l, int r){
    if (l > r) return;
    else if (l == tl && tr == r){
        lazy[v] ^= 1;
        t[v] = scont(t[v]);
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(tm, r));
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    t[v] = mult(t[v * 2], t[v * 2 + 1]);
}

matrix query(int v, int tl, int tr, int l, int r){
    if (l > r) return idd;
    else if (l <= tl && tr <= r){
        return t[v];
    }
    push(v);   
    int tm = (tl + tr) / 2;
    return mult(query(v * 2, tl, tm, l, min(tm, r)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

pair<ll, ll> ask(int l, int r, ll a, ll b){
    matrix res = query(1, 1, n, l, r);
    return mp((res[0][0] * a + res[0][1] * b) % MOD, (res[1][0] * a + res[1][1] * b) % MOD);
}

void printMat(matrix a){
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            cout << a[i][j] << " ";
        }
        cout << el;
    }
    cout << "======" << el;;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    idd[0][0] = idd[1][1] = 1;
    cin >> n >> q;
    cin >> s;
    s = "*" + s + "*";
    build(1, 1, n);
    // for (int i=1;i<=n;i++){
    //     printMat(query(1, 1, n, 1, i));
    // }
    while (q--){
        int tipe;
        cin >> tipe;
        if (tipe == 1){
            int l, r;
            cin >> l >> r;
            update(1, 1, n, l, r);
        } else{
            int l, r;
            ll a, b;
            cin >> l >> r >> a >> b;
            pair<ll, ll> ans = ask(l, r, a, b);
            cout << ans.fi << " " << ans.se << el;
        }
    }

    return 0;
}