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

const int N = 2e5 + 9;
const int INF = 2e9 + 10;

int q;
int n, k;
ll ar[N], p;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> p >> k;

        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        sort(ar + 1, ar + n + 1);

        ll dp[n+7];
        for (int i=1;i<n+7;i++){
            dp[i] = INF;
        }
        dp[0] = 0;

        ll tot = 0;
        for (int i=1;i<k;i++){
            dp[i] = dp[i-1] + ar[i];
            if (dp[i] <= p) tot=i;
        }

        for (int i=k;i<=n;i++){
            dp[i] = min(min(dp[i-1] + ar[i], dp[i-k] + ar[i]), dp[i]);
            // cout << i<< ":" << dp[i] << " ";
            if (dp[i] <= p) tot=i;
        } 
        // cout << el;

        cout << tot << el;
    }

    return 0;
}