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

const int N = 2e5 + 10;

int n, m, k;

bool is_sp[N];
vector <int> sp;
vector <int> adl[N];
int ans; 
int jarak[N];
int jarak2[N];

int par[N];
bool ispath[N];
vector <int> path;

pii ino[N];

bool vis[N];
bool vis2[N];
void bfs(){
    queue<pii> qu; // node, depth
    qu.push(mp(1, 0));

    while (!qu.empty()){
        auto cur = qu.front();
        qu.pop();
        if (vis[cur.fi]){
            continue;
        }
        vis[cur.fi] = 1;
        jarak[cur.fi] = cur.se;

        for (auto child : adl[cur.fi]){
            if (!vis[child]){
                if (par[child] == 0) par[child] = cur.fi;
                qu.push(mp(child, cur.se + 1));
            }
        }
    }
}

void bfs2(){
    queue<pii> qu; // node, depth
    qu.push(mp(n, 0));

    while (!qu.empty()){
        auto cur = qu.front();
        qu.pop();
        if (vis2[cur.fi]){
            continue;
        }
        vis2[cur.fi] = 1;
        jarak2[cur.fi] = cur.se;

        for (auto child : adl[cur.fi]){
            if (!vis2[child]){
                qu.push(mp(child, cur.se + 1));
            }
        }
    }
}

set <pii> setdah;
// bool udh[N];

void sol(){
    fill(vis, vis + n + 3, 0);
    queue <int> qu;
    qu.push(1);
    while (!qu.empty()){
        int cur = qu.front();
        qu.pop();
        if (vis[cur]) continue;
        vis[cur] = 1;
        if (is_sp[cur]){
            pii pus = mp(jarak2[cur], cur);
            setdah.erase(pus);
            if (setdah.empty()) break;

            auto temp = setdah.end();
            temp--;
            ans = max(ans, jarak[cur] + (*temp).fi + 1);
        }

        for (auto x : adl[cur]){
            if (!vis[x]) qu.push(x);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1;i<=k;i++){
        int a;
        cin >> a;
        sp.pb(a);
        is_sp[a] = 1;
    }

    bool langsung = 0;
    for (int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
        if (is_sp[a] && is_sp[b]){
            langsung = 1;
        }
    }

    bfs();
    bfs2();
    int cur = n;

    ispath[n] = 1;
    while (cur != 1){
        path.pb(cur);
        cur = par[cur];
        ispath[cur] = 1;
    }
    path.pb(1);
    if (langsung){
        cout << jarak[n] << el;
        return 0;
    }

    for (auto x : sp){
        ino[x] = mp(jarak[x], jarak2[x]);
        setdah.insert(mp(jarak2[x], x));
    }
    
    sol();
    ans = min(ans, jarak[n]);
    cout << ans << el;

    return 0;
}