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

const int INF = 1e9;

int n;
int dp[(1 << 3)];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<(1 << 3);i++){
        dp[i] = INF;
    }
    cin >> n;
    for (int in=1;in<=n;in++){
        int a;
        string s;
        cin >> a >> s;
        int nil = 0;
        for (int i=0;i<s.length();i++){
            int dig = s[i] - 'A';
            nil = (nil | (1 << dig));
        }
        dp[nil] = min(dp[nil], a);
    }    
    for (int ulang=1;ulang<8;ulang++){
        for (int i=1;i<(1 << 3);i++){
            for (int j=1;j<(1 << 3);j++){
                int now = (i | j);
                dp[now] = min(dp[now], dp[i] + dp[j]);
            }
        }
    }
    if (dp[7] != INF) cout << dp[7] << el;
    else cout << -1 << el;

    return 0;
}