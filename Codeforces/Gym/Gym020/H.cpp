#pragma gcc optimize ("O2")
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

const int N = 1e5 + 10, MX = 2e2;
const ll INF = 1e18;

int n;
int ar[N];

int dec(char a){
    if (a <= '9') return a - '0';
    return a - 'A' + 10;
}

ll dp[MX];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        char a, b;
        cin >> a >> b;
        ar[i] = dec(a) * 16 + dec(b);
    }
    fill(dp, dp + MX, -INF);
    for (int i=0;i<n;i++){
        ll bdp[MX];
        for (int j=0;j<MX;j++){
            bdp[j] = dp[j];
        }
        if (i < MX){
            dp[i] = ar[i];
        }
        if (i != 0) dp[0] = bdp[0] + (ar[i] ^ i);
        for (int j=1;j<MX;j++){
            dp[j] = max(dp[j], bdp[j - 1]);
            if (bdp[j] != -INF) dp[j] = max(dp[j], bdp[j] + (ar[i] ^ (i - j)));
        }
    }
    ll ret = 0;
    for (int i=0;i<MX;i++){
        ret = max(ret, dp[i]);
    }
    cout << ret << el;

    return 0;
}