#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;

int slen, tlen;
string s, t;
int dp[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    slen = s.length();
    tlen = t.length();

    for (int i=0;i<slen;i++){
        for (int j=0;j<tlen;j++){
            dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            if (s[i] == t[j]){
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            }
        }
    }
    cout << dp[slen][tlen] << el;

    return 0;
}