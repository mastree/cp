#pragma gcc optimize("O2")
#pragma gcc optimize("unroll-loops")

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
const ll MX = 1e18;
const ll MXH = 2e9;

const int MAXN = (1 << 18);
const int MAXLOG = 18;

struct sparse_table
{
    ll dp[MAXN][MAXLOG];
    int prec_lg2[MAXN], n;

    sparse_table() { memset(dp, 0, sizeof(dp)); memset(prec_lg2, 0, sizeof(prec_lg2)); n = 0; }

    void init(vector<ll> &a){
        n = a.size();
        for(int i = 2; i < 2 * n; i++) prec_lg2[i] = prec_lg2[i >> 1] + 1;
        for(int i = 0; i < n; i++) dp[i][0] = a[i];
        for(int j = 1; (1 << j) <= n; j++)
            for(int i = 0; i < n; i++)
                dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    }

    ll query(int l, int r){
        int k = prec_lg2[r - l + 1];
        return max(dp[l][k], dp[r - (1 << k) + 1][k]);
    }
};

int n;
ll k;
ll ar[N];
sparse_table table_le, table_ri;

void init(){
    {
        vector<ll> vec(n + 2, 0);
        for (int i=1;i<=n;i++){
            vec[i] = ar[i] - i;
        }
        table_le.init(vec);
    }
    {
        vector<ll> vec(n + 2, 0);
        for (int i=n;i>=1;i--){
            vec[i] = ar[i] - (n - i + 1);
        }
        table_ri.init(vec);
    }
}

ll pre[N];

ll sum_range(ll l, ll r){
    return (r + l) * (r - l + 1) / 2; 
}

bool bisa(ll mx){
    for (int i=1;i<=n;i++){
        if (ar[i] >= mx) return 1;
        if (i == 1 || i == n) continue;
        ll butuhle = mx - i;
        ll butuhri = mx - (n - i + 1);
        if (table_le.query(1, i - 1) < butuhle || table_ri.query(i + 1, n) < butuhri) continue;

        int posle = -1, posri = -1;
        {
            int l = 1, r = i - 1;
            while (l < r){
                int m = (l + r + 1) / 2;
                if (table_le.query(m, i - 1) >= butuhle){
                    l = m;
                } else{
                    r = m - 1; 
                }
            }
            posle = l + 1;
        }
        {
            int l = i + 1, r = n;
            while (l < r){
                int m = (l + r) / 2;
                if (table_ri.query(i + 1, m) >= butuhri){
                    r = m;
                } else{
                    l = m + 1; 
                }
            }
            posri = r - 1;
        }
        ll need = sum_range(mx - (i - posle), mx) + sum_range(mx - (posri - i), mx) - mx;
        ll cur = need - (pre[posri] - pre[posle - 1]);
        if (cur <= k){
            return 1;
        }
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("landscape.in", "r", stdin); 
    freopen("landscape.out", "w", stdout);
    ll mx = -MX;
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        mx = max(mx, ar[i]);
        pre[i] = pre[i - 1] + ar[i];
    }
    init();

    ll l = mx, r = 2e9;
    while (l < r){
        ll m = (l + r + 1) / 2;
        if (bisa(m)){
            l = m;
        } else{
            r = m - 1;
        }
    }
    cout << l << el;

    return 0;
}