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

const ll MOD = 998244353;
const int N = 3e3 + 10;

ll ans;
string s, t;
int slen, tlen;

bool ada[N][26];
vector <int> pos[26];

ll dp[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    slen = s.length();
    tlen = t.length();
    s = "*" + s;
    t = "*" + t;
    for (int i=1;i<=slen;i++){
        int dig = s[i] - 'a';
        ada[i][dig] = 1;
        pos[dig].pb(i);
    }

    // for (int i=tlen;i>0;i--){
    //     int dig_t = t[i] - 'a';
    //     if (i == tlen){
    //         for (auto ch : pos[dig_t]){
    //             dp[i][ch] = 1;
    //         }
    //         continue;
    //     }
    //     ll pc[N];
    //     fill(pc, pc + N, 0);
    //     for (int j=1;j<N;j++){
    //         pc[j] = (pc[j - 1] + dp[i + 1][j]) % MOD;
    //     }

    //     for (auto ch : pos[dig_t]){
    //         dp[i][ch] = pc[ch - 1];
    //     }
    // }

    priority_queue <int>

    for (int i=0;i<N;i++){
        ans = ((ans + dp[1][i]) % MOD * );
    }
    cout << ans << el;

    return 0;
}