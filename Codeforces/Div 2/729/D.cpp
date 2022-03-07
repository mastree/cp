#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e2 + 10;
const int MOD = 998244353;

int n;
vector<int> ar;
vector<pair<int, int>> ada;
ll conv[N];

ll solve(int pos){
    vector<ll> dp(N, 0);
    dp[0] = 1;
    for (int i=0;i<n;i++){
        if (i == pos) continue;
        if (ar[i] == -1){
            for (int j=0;j<N - 1;j++){
                if (j == 0 && i < pos) dp[j] = (dp[j] + dp[j] + dp[j + 1]) % MOD;
                else dp[j] = (dp[j] + dp[j + 1]) % MOD;
            }
        } else{
            if (ar[i] > ar[pos]){
                for (int j=0;j<N;j++){
                    dp[j] = (dp[j] + dp[j]) % MOD;
                }
                continue;
            }
            for (int j=N - 1;j>=1;j--){
                dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
        }
    }
    ll ret = 0;
    for (int i=0;i<n;i++){
        ret = (ret + dp[i]) % MOD;
    }
    return ret * conv[ar[pos]] % MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        char op;
        cin >> op;
        if (op == '+'){
            int a;
            cin >> a;
            ar.pb(a);
            ada.pb(mp(a, i - 1));
        } else{
            ar.pb(-1);
        }
    }
    sort(ada.begin(), ada.end());
    {
        int temp = 1;
        for (auto& x : ada){
            conv[temp] = x.fi;
            ar[x.se] = temp++;
        }
    }
    ll ans = 0;
    for (int i=0;i<n;i++){
        if (ar[i] != -1){
            ans = (ans + solve(i)) % MOD;
        }
    }
    cout << ans << el;

    return 0;
}