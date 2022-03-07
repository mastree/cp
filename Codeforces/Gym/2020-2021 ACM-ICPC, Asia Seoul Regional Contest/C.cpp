#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int n, k;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    vector<vector<pii>> adj(n + 1);
    for (int i=0;i<n - 1;i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
    vector<int> vec;
    vector<bool> apart(n + 1, 0);
    for (int i=0;i<k;i++){
        int a;
        cin >> a;
        vec.emplace_back(a);
        apart[a] = 1;
    }
    int ans = 0;
    function<bool(int, int)> dfs = [&](int node, int p) -> bool {
        bool ret = apart[node];
        for (auto& x : adj[node]){
            if (x.first == p) continue;
            ret |= dfs(x.first, node);
        }
        ans += ret;
        return ret;
    };
    dfs(vec[0], vec[0]);
    cout << ans << el;

    return 0;
}