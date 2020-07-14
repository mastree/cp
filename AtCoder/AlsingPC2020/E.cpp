#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int q;
int n;
vector<ll> le[N], ri[N];

ll dp1[N], dp2[N];

void init(){
    fill(dp1, dp1 + n + 3, 0);
    fill(dp2, dp2 + n + 3, 0);
    for (int i=0;i<=n + 1;i++){
        le[i].clear();
        ri[i].clear();
    }
}

void init_dp(){
    // dp1 aka left, dp2 aka right
    priority_queue<ll> setdah;
    for (int i=n;i>=1;i--){
        for (auto x : le[i]) setdah.push(x);
        if (!setdah.empty()){
            dp1[i] = setdah.top();
            setdah.pop();
        }
    }
    while (!setdah.empty()) setdah.pop();
    for (int i=1;i<=n;i++){
        for (auto x : ri[i]) setdah.push(x);
        if (!setdah.empty()){
            dp2[i] = setdah.top();
            setdah.pop();
        }
    }
    int last = 1;
    for (int i=1;i<=n;i++){
        last = max(last, i);
        if (dp1[i] == 0){
            while (last < n && dp1[last] == 0) last++;
            if (dp1[last]) swap(dp1[i], dp1[last]);
        }
    }
    last = n;
    for (int i=n;i>=1;i--){
        last = min(last, i);
        if (dp2[i] == 0){
            while (last > 1 && dp2[last] == 0) last--;
            if (dp2[last]) swap(dp2[i], dp2[last]);
        }
    }

    ll tot = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i=1;i<=n;i++){
        tot += dp1[i];
        pq.push(dp1[i]);
    }
    for (int i=n;i>=1;i--){
        dp1[i] = tot;
        tot -= pq.top();
        pq.pop();
    }
    tot = 0;
    for (int i=1;i<=n;i++){
        tot += dp2[i];
        pq.push(dp2[i]);
    }
    for (int i=1;i<=n;i++){
        dp2[i] = tot;
        tot -= pq.top();
        pq.pop();
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;

        init();
        ll base = 0;
        for (int i=1;i<=n;i++){
            ll k, l, r;
            cin >> k >> l >> r;

            if (l > r){
                le[k].pb(l - r);
            } else{
                ri[k + 1].pb(r - l);
            }
            base += min(l, r);
        }
        init_dp();
        ll tot = 0;
        for (int i=0;i<=n;i++){
            tot = max(tot, dp1[i] + dp2[i + 1]);
        }
        cout << base + tot << el;
    }

    return 0;
}