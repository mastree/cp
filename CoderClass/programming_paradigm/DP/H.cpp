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

int n;
vector<int> jump[N];
ll dp[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        jump[a].pb(b);
    }
    dp[0] = 1;
    for (int i=1;i<N;i++){
        dp[i] = (dp[i] + dp[i - 1]) % MOD;
        for (auto x : jump[i]){
            dp[x + 1] = (dp[x + 1] + dp[i]) % MOD;
        }
    }
    cout << (dp[N - 1] - 1LL + MOD) % MOD << el;

    return 0;
}