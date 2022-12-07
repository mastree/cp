#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> deg(n + 1);
    vector<unordered_map<int, ll>> mans(n + 1), ans(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        deg[a]++;
        deg[b]++;
        mans[a][b] += c;
        mans[b][a] += c;
    }
    vector<pii> query(q);
    vector<set<int>> vq(n + 1);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        query[i] = {a, b};
        if (deg[a] < deg[b] || (deg[a] == deg[b] && a < b)) swap(a, b);
        vq[a].insert(b);
    }
    for (int a = 1; a <= n; a++) {
        for (auto& b : vq[a]) {
            for (auto& x : mans[b]) {
                if (mans[a].count(x.first)) {
                    int temp = min(mans[a][x.first], x.second);
                    ans[a][b] += temp;
                }
            }
        }
    }
    for (auto& quer : query) {
        cout << ans[quer.fi][quer.se] + ans[quer.se][quer.fi] + mans[quer.fi][quer.se] * 2 << ' ';
    }
    cout << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
