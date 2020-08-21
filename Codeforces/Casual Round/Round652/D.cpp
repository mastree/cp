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

const int N = 2e6 + 10;
const ll MOD = 1e9 + 7;

int q;
int n;

ll dp[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    dp[1] = dp[2] = 0;
    for (int i=3;i<N;i++){
        dp[i] = (dp[i - 1] + dp[i - 2] * 2LL) % MOD;
        if (i % 3LL == 0){
            dp[i] = (dp[i] + 1) % MOD;
        }
    }

    cin >> q;
    while (q--){
        cin >> n;
        cout << (dp[n] * 4LL) % MOD << el;
    }

    return 0;
}