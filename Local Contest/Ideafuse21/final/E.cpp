#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int LEN = 11;
const int K = 10;
const int LOWER = 2;

int q;
int n, k;

int dp[LEN][LOWER]; // pos, is_lower
int calc0(string sn, int nodig){
    int len = sn.size();
    for (int i=0;i<LEN;i++){
        for (int j=0;j<LOWER;j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int pos=0;pos<len;pos++){
        int dig = sn[pos] - '0';
        // 0
        for (int ndig=(pos == 0);ndig<dig;ndig++){
            if (ndig != nodig) dp[pos + 1][1] += dp[pos][0];
        }
        if (dig != nodig) dp[pos + 1][0] += dp[pos][0];
        
        // 1
        for (int ndig=(pos == 0);ndig<=9;ndig++){
            if (ndig != nodig) dp[pos + 1][1] += dp[pos][1];
        }
    }
    return dp[len][0] + dp[len][1];
}

void solve(){
    cin >> n >> k;
    int ans = 0;
    string sn = to_string(n);
    int len = sn.size();
    ans += calc0(sn, k);
    for (int i=1;i<len;i++){
        string temp;
        for (int j=0;j<i;j++) temp.pb('9');
        ans += calc0(temp, k);
    }
    if (k != 0){
        if (k * 10 <= n) ans++;
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}