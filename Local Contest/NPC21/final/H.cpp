#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>

#define el '\n'
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 5e3 + 10;
const int MOD = 1e9 + 7;

int n, k;
int ar[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    vector<ll> dp(k + 1, 0);
    vector<ll> ndp(k + 1, 0);
    dp[0] = 1; 
    for (int i=1;i<=n;i++){
        int slot = i;
        fill(ndp.begin(), ndp.end(), 0);
        for (int j=0;j<=k;j++){
            if (dp[j] == 0) continue;
            vector<ll> pil = {1 + j, i - (1 + j)};
            for (int dif=0;dif<2;dif++){
                int nj = j + dif;
                if (nj <= k){
                    ndp[nj] = (ndp[nj] + dp[j] * pil[dif]) % MOD;
                }
            }
        }
        dp.swap(ndp);
    }
    cout << dp[k] << el;

    return 0;
}