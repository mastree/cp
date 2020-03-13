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

const int N = 1e3 + 7;
const int H = 1e4 + 7;
const int INF = 2e9;

int h, n;
int dp[H];
int a[N], b[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
    }

    fill(dp, dp + H, INF);
    dp[h] = 0;
    for (int i=h;i>=0;i--){
        for (int j=1;j<=n;j++){
            int id = max(i - a[j], 0);
            // cout << i << " " << id << "=> " << dp[i] + b[j] << el;
            dp[id] = min(dp[id], dp[i] + b[j]);
        }
    }
    cout << dp[0] << el;

    return 0;
}