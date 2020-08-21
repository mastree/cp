#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll INF = 2e18;

int q;
ll n, a, b, c, d;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> a >> b >> c >> d;
        map<ll, ll> dp;
        map<ll, bool> vis;

        dp[n] = 0;
        priority_queue<ll> pq;
        pq.push(n);
        while (!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            if (vis[temp]) continue;
            vis[temp] = 1;

            ll dpcur = dp[temp];
            for (ll i=-4;i<=4;i++){
                ll delta = abs(i) * d;
                ll ncur = i + temp;
                if (ncur >= 0){
                    if (ncur == 0){
                        if (dp[ncur] == 0) dp[ncur] = dp[temp] + delta;
                        else dp[ncur] = min(dp[ncur], dp[temp] + delta);
                        continue;
                    }
                    if (ncur % 2 == 0){
                        ll sim = dp[ncur / 2];
                        if (sim != 0) dp[ncur / 2] = min(sim, dp[temp] + delta + a);
                        else dp[ncur / 2] = dp[temp] + delta + a;
                        pq.push(ncur / 2);
                    }
                    if (ncur % 3 == 0){
                        ll sim = dp[ncur / 3];
                        if (sim != 0) dp[ncur / 3] = min(sim, dp[temp] + delta + b);
                        else dp[ncur / 3] = dp[temp] + delta + b;
                        pq.push(ncur / 3);
                    }
                    if (ncur % 5 == 0){
                        ll sim = dp[ncur / 5];
                        if (sim != 0) dp[ncur / 5] = min(sim, dp[temp] + delta + c);
                        else dp[ncur / 5] = dp[temp] + delta + c;
                        pq.push(ncur / 5);
                    }
                }
            }
        }
        ll ans = INF;
        for (auto x : dp){
            if (x.first >= INF / d) continue;
            ans = min(ans, x.second + x.first * d);
        }
        cout << ans << '\n';
    }

    return 0;
}