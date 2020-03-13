#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

typedef vector<vector<ll>> matrix;

const ll MOD = 1e9 + 7;

int q;
ll n, m;

matrix mult(matrix a, matrix b){
    matrix res(2, vector<ll>(2, 0));
    res[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
    res[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
    res[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
    res[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;

    return res;
}

matrix fpow(matrix a, ll b){
    if (b==0){
        matrix id(2, vector<ll>(2));
        id[0] = {1, 0};
        id[1] = {0, 1};
        return id;
    }
    matrix tm = fpow(a, b/2);
    tm = mult(tm, tm);
    if (b%2 == 1){
        tm = mult(tm, a);
    }

    return tm;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    matrix mat(2, vector<ll>(2));
    while (q--){
        cin >> n >> m;
        m %= MOD;
        m = (m + MOD) % MOD;
        mat[0] = {m-1, m-1};
        mat[1] = {1, 0};

        if (n==1){
            cout << m << el;
            continue;
        } else if (n==2){
            cout << m * m % MOD << el;
            continue;
        }
        matrix hit = fpow(mat, n-2);
        cout << (((hit[0][0] * m % MOD) * m % MOD + hit[0][1] * m % MOD) % MOD + MOD) % MOD  << el;  
    }

    return 0;
}