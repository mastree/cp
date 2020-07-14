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

const int N = 1e5 + 10;

int q;
int n, x;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> x;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            ar[i] %= x;
        }
        int dp[N];
        int le[N], ri[N];
        fill(dp, dp + N, MOD);
        fill(le, le + N, MOD);
        fill(ri, ri + N, MOD);
        dp[0] = 0;
        for (int i=1;i<=n;i++){
            ar[i] = (ar[i] + ar[i - 1]) % x;
            int temp = ar[i];
            // cout << ar[i] << ":" << temp << " ";
            dp[temp] = min(dp[temp], i);
        }
        // cout << el;
        le[0] = dp[0];
        for (int i=1;i<x;i++){
            le[i] = min(le[i - 1], dp[i]);
        }
        ri[x - 1] = dp[x - 1];
        for (int i=x - 2;i>=0;i--){
            ri[i] = min(dp[i], ri[i + 1]);
        }

        int ans = -1;
        for (int i=1;i<=n;i++){
            int temp = ar[i];
            int mn;
            if (temp == 0) mn = ri[1];
            else if (temp == x - 1) mn = le[x - 2];
            else mn = min(le[temp - 1], ri[temp + 1]);
            // cout << temp << " " << mn << el;
            if (i < mn) continue;
            ans = max(ans, i - mn);
        }
        cout << ans << el;
    }

    return 0;
}