#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n + 2, vector<char>(m + 2));
    vector<vector<int>> adjacents(n + 2, vector<int>(m + 2, 0));
    vector<pii> pos;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == '^') {
                pos.emplace_back(i, j);
            }
            if (mat[i][j] == '.' || mat[i][j] == '^') adjacents[i][j] = 4;
        }
    }
    queue<pii> q;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            if (adjacents[i][j] < 2) q.emplace(i, j);
        }
    }
    while (!q.empty()) {
        int r = q.front().fi;
        int c = q.front().se;
        q.pop();
        for (int id = 0; id < 4; id++) {
            int nr = r + di[id];
            int nc = c + dj[id];
            if (nr < 1 || n < nr || nc < 1 || m < nc) continue;
            adjacents[nr][nc]--;
            if (adjacents[nr][nc] == 1) q.emplace(nr, nc);
        }
    }
    bool ok = 1;
    for (auto& x : pos) {
        if (adjacents[x.fi][x.se] < 2) ok = 0;
    }
    cout << (ok ? "Possible\n" : "Impossible\n");
    if (ok) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << ((adjacents[i][j] < 2 || mat[i][j] == '#') ? mat[i][j] : '^');
            }
            cout << '\n';
        }
    }
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