#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = double;
using pdi = pair<ld, int>;

int n, m, d;
unordered_map<ll, ld> dp;
ll ppow[12];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(11);

    ppow[0] = 1;
    for (int i=1;i<12;i++){
        ppow[i] = ppow[i - 1] * 10LL;
    }

    cin >> n >> m >> d;
    ll sawal = 0;
    int tot = 0;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        tot += x;
        sawal += ppow[x - 1];
    }
    for (int i=0;i<m;i++){
        ll x;
        cin >> x;
        tot += x;
        sawal += ppow[x + 5];
    }
    if (tot <= d){
        cout << 1 << el;
        return 0;
    }
    dp[sawal] = (ld)1;
    set<pair<int, ll>> pq;
    pq.insert(mp(0, sawal));
    ld ans = 0;
    
    while (!pq.empty()){
        auto tp = *pq.begin();
        ll cur = tp.se;
        ll temp = cur;
        pq.erase(tp);
        if (tp.fi == d){
            if (cur / ppow[6] == 0) ans += dp[cur];
            continue;
        }
        auto ldp = dp[cur];
        int tot = 0;
        for (int i=0;i<12;i++){
            tot += (int)((ll)((cur / ppow[i]) % 10LL));
        }
        ld chance = ((ld)1) / ((ld)tot);
        for (int i=0;i<12;i++){
            ll tcnt = (ll)((cur / ppow[i]) % 10LL);
            if (tcnt){
                ll ncur = cur - ppow[i];
                if (i != 0 && i != 6) ncur += ppow[i - 1];
                dp[ncur] += ldp * chance * ((ld)tcnt);
                pq.insert(mp(tp.fi + 1, ncur));
            }
        }
    }
    cout << ans << el;

    return 0;
}