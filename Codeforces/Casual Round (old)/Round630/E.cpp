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

typedef vector<vector<ll>> matrix;

const ll MOD = 998244353;

ll n, m, l, r;
ll ans;
ll mx;

ll slots;

ll fpow(ll a, ll b){
    if (b == 0) return 1;
    ll tm = fpow(a, b / 2);
    tm = tm * tm % MOD;
    if (b & 1){
        tm = tm * a % MOD;
    }
    return tm;
}

matrix mult(matrix a, matrix b){
    matrix ret(2, vector<ll>(2, 0));

    for (int i=0;i<2;i++){
        for (int k=0;k<2;k++){
            for (int j=0;j<2;j++){
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
            }
        }
    }

    return ret;
}

matrix fmat(matrix a, ll b){
    matrix ret(2, vector<ll>(2, 0));
    if (b == 0){
        ret[0] = {1, 0};
        ret[1] = {0, 1};
        return ret;
    }
    if (b == 1){
        return a;
    }
    ret = fmat(a, b / 2);
    ret = mult(ret, ret);
    if (b & 1){
        ret = mult(ret, a);
    }

    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> l >> r;
    slots = n * m;

    mx = r - l;
    if (mx == 0){
        cout << 1 << el;
        return 0;
    }

    if (slots & 1LL){
        // ll temp = n * m;
        cout << fpow((mx + 1) % MOD, slots) << el;
        return 0;
    }

    matrix temp(2, vector<ll>(2, 0));
    temp[0] = {(mx / 2LL + 1LL) % MOD, ((mx + 1LL) / 2LL) % MOD};
    temp[1] = {((mx + 1LL) / 2LL) % MOD, (mx / 2LL + 1LL) % MOD};

    temp = fmat(temp, slots);
    ll ev = temp[0][0];
    ll od = temp[0][1];

    cout << ev << el;

    return 0;
}