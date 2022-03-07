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

const int N = 2e3 + 10;
const int INF = 1e9;

int q, n;
string s, t;
int pcs[N][26], pct[N][26];
int dp[N][N]; // pt s, pt t

bool same_canon(string a, string b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        cin >> s >> t;

        if (!same_canon(s, t)){
            cout << -1 << el;
            continue;
        }

        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        s = "*" + s;
        t = "*" + t;
        for (int i=1;i<=n;i++){
            int sdig = s[i] - 'a';
            int tdig = t[i] - 'a';
            for (int j=0;j<26;j++){
                pcs[i][j] = pcs[i - 1][j];
                pct[i][j] = pct[i - 1][j];
            } 
            pcs[i][sdig]++;
            pct[i][tdig]++;
        }
        for (int i=0;i<=n;i++) fill(dp[i], dp[i] + n + 2, INF);
        dp[0][0] = 0;
        for (int j=0;j<=n;j++){
            for (int i=j;i<=n;i++){
                if (i < n) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
                int cnt[26];
                int mn = INF;
                for (int k=0;k<26;k++){
                    cnt[k] = pcs[i][k] - pct[j][k];
                    mn = min(mn, cnt[k]);
                }
                if (mn < 0) continue;
                if (i < n && s[i + 1] == t[j + 1]){
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
                }
                if (j < n){
                    int ndig = t[j + 1] - 'a';
                    if (cnt[ndig] > 0){
                        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
                    }
                }
            }
        }
        cout << dp[n][n] << el;
    }

    return 0;
}