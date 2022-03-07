#include <bits/stdc++.h>

/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
/** END OF DESPERATE OPTIMIZATION **/

#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const int INF = 2e9 + 10;

int n, m;
vector<vector<pii>> adj;
int k;
vector<pii> vec;
vector<pii> stud[N]; // jarak, id

vector<bool> bisa(int mnnode){
    priority_queue<pii, vector<pii>, greater<pii>> setdah;
    vector<int> dp(n + 1, INF);
    for (int i=1;i<=mnnode;i++){
        dp[i] = 0;
        pq.push(mp(0, i));
    }
    vector<bool> ret(k + 1, 0);
    while (!pq.empty()){
        int node = pq.top().se;
        int cur = pq.top().fi;
        pq.pop();

        if (cur > dp[node]) continue;
        
        for (auto& x : stud[node]){
            if (x.fi < cur) continue;
            ret[x.se] = 1;
        }
        for (auto& x : adj[node]){
            if (dp[x.fi] > cur + x.se){
                dp[x.fi] = cur + x.se;
                pq.push(mp(dp[x.fi], x.fi));
            }
        }
    }
    return ret;
}
int geton(const vector<bool>& vec){
    int ret = 0;
    for (const auto& x : vec) if (x) ret++;
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    adj.resize(n + 1, vector<pii>());
    for (int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    cin >> k;
    for (int i=1;i<=k;i++){
        int p, a;
        cin >> p >> a;
        vec.emplace_back(p, a);
        stud[p].emplace_back(a, i); 
    }
    // for (int i=1;i<=n;i++) sort(stud[i].begin(), stud[i].end(), greater<pii>());

    int l = 1, r = n, best = -1;
    while (l <= r){
        int m = (l + r) / 2;
        if (geton(bisa(m)) >= k){
            r = m - 1;
            best = m;
        } else{
            l = m + 1;
        }
    }
    auto v1 = bisa(best);
    auto v2 = bisa(best - 1);
    for (int i=k;i>=1;i--){
        if (v1[i] && !v2[i]){
            cout << i << el;
            break;
        }
    }

    return 0;
}