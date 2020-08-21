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

int q;
ll d, m;
ll cnt[35];
ll dp[35];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> d >> m;
        for (ll i=31;i>=0;i--){
            ll temp = d - (1LL << i) + 1LL;
            cnt[i] = max(min(temp, (1LL << i)), 0LL);
        }
        ll ans = 0;
        fill(dp, dp + 34, 0);
        ll pc = 0;
        for (ll i=31;i>=0;i--){
            dp[i] = cnt[i];
            dp[i] = (dp[i] + dp[i] * pc % m) % m;
            pc = (pc + dp[i]) % m;
        }

        cout << pc << el;

    }

    return 0;
}