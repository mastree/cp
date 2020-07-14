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
const ll INF = 1e18;

int n;
ll ar[N];
ll slot, ans;

ll dp[N], slots[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    slot = 1;
    for (int i=0;i<=n;i++){
        cin >> ar[i];
    }    
    for (int i=0;i<=n;i++){
        slots[i] = slot;
        slot -= ar[i];
        if (slot < 0){
            cout << -1 << el;
            return 0;
        }
        dp[i] += ar[i];
        slot = min(slot + slot, INF);
    }
    ll cur = 0;
    for (int i=n;i>=0;i--){
        if (cur){
            dp[i] = min(dp[i] + cur, slots[i]);
        }
        ans += dp[i];
        cur = dp[i];
    }
    cout << ans << el;

    return 0;
}