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

int n;
pii a, b;

bool valid(int x){
    return 1 <= x && x <= n;
}
bool valid(pii x){
    return valid(x.fi) && valid(x.se);
}
pii domove(pii x, pii move){
    return mp(x.fi + move.fi, x.se + move.se);
}

/*
cuma butuh ngecek 3 * N max

XXXXX
XXXXX
XXXXX
XXXXX
XXXXX

*/

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
int randint(){
    ll ret = rng32();
    return (int)(ret % n + 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> a.fi >> a.se;
    cin >> b.fi >> b.se;

    vector<pii> move, rmove;
    for (int i=0;i<n;i++){
        pii x;
        cin >> x.fi >> x.se;
        move.pb(x);
        rmove.emplace_back(-x.fi, -x.se);
    }
    // check if alice wins
    {
        map<pii, int> vis;
        for (auto& x : move){
            if (valid(domove(a, x))) vis[domove(a, x)]++;
        }
        if (vis[b]){
            cout << "Alice wins" << el;
            return 0;
        }
        for (auto& x : rmove){
            if (valid(domove(b, x)) && vis[domove(b, x)]++){
                cout << "Alice wins" << el;
                return 0;
            }
        }
    }
    // check if alice can run away with teleportation
    if (n <= 1000){
        vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, 0));
        queue<pair<pii, int>> q; // node, depth
        q.push(mp(b, 0));
        while (!q.empty()){
            pii cur = q.front().fi;
            int dep = q.front().se;
            q.pop();
            if (vis[cur.fi][cur.se]) continue;
            vis[cur.fi][cur.se] = 1;
            if (dep >= 2) continue;
            for (auto& x : move){
                pii nx = domove(cur, x);
                if (valid(nx)) q.push(mp(nx, dep + 1));
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (!vis[i][j]){
                    cout << "tie " << i << " " << j << el;
                    return 0;
                }
            }
        }
        cout << "Bob wins" << el;
        return 0;
    }
    cout << "tie ";
    set<pii> setdah;
    {
        for (auto& x : move){
            auto temp = domove(b, x);
            if (valid(temp)){
                setdah.insert(temp);
            }
        }
        setdah.insert(b);
    }
    while (1){
        pii pos = mp(randint(), randint());
        if (setdah.find(pos) != setdah.end()) continue;
        bool ok = 1;
        for (auto& x : rmove){
            auto temp = domove(pos, x);
            if (valid(temp) && setdah.find(temp) != setdah.end()){
                ok = 0;
                break;
            }
        }
        if (!ok) continue;
        cout << pos.fi << " " << pos.se << el;
        return 0;
    }

    return 0;
}