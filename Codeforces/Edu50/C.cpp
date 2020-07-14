#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const ll MX = 1e18;
const int LEN = 20;
const int CNT = 4;

int q;
ll l, r;

ll dp[LEN][CNT][2];

ll calc(string s){
    ll ret = 0;
    for (int i=0;i<LEN;i++){
        for (int j=0;j<CNT;j++){
            dp[i][j][0] = dp[i][j][1] = 0LL;
        }
    }
    int len = s.length();
    dp[0][0][1] = 1; // prefix inisial 1
    for (int i=0;i<len;i++){
        ll cdig = (ll)(s[i] - '0');
        for (int j=0;j<4;j++){
            if (i == 0){
                if (j > 0) dp[i + 1][j][0] += dp[i][j - 1][1] * (cdig - 1);
                if (cdig && j > 0) dp[i + 1][j][1] = dp[i][j - 1][1];
                // else dp[i + 1][j][1] = dp[i][j][1]; 
            } else{
                dp[i + 1][j][0] += dp[i][j][0];
                if (cdig) dp[i + 1][j][0] += dp[i][j][1];
                if (j > 0) dp[i + 1][j][0] += dp[i][j - 1][1] * max(0LL, (cdig - 1)) + dp[i][j - 1][0] * 9;
                if (cdig && j > 0) dp[i + 1][j][1] = dp[i][j - 1][1];
                else if (!cdig) dp[i + 1][j][1] = dp[i][j][1];
            }
        }
    }
    for (int i=0;i<4;i++){
        ret += dp[len][i][0] + dp[len][i][1];
    }
    return ret;
}

ll sol(ll a){
    if (a == 0) return 0;
    ll ret = 0;
    string s = to_string(a);
    int len = s.length();
    ret += calc(s);
    string temp;
    for (int i=1;i<len;i++){
        temp.pb('9');
        ret += calc(temp);
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> l >> r;
        cout << sol(r) - sol(l - 1) << el;
    }

    return 0;
}