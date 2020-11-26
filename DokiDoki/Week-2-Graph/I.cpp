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
using pli = pair<ll, int>;

const int N = 1e5 + 10;
const ll INF = 1e18;

int n, m, k;
ll train[N];
ll dist[N];
vector<pil> adj[N];

int ans = 0;
bool mark[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1;i<=m;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }
    for (int i=1;i<=k;i++){
        int a;
        ll w;
        cin >> a >> w;
        if (train[a]){
            ans++;
            train[a] = min(train[a], w);
        } else train[a] = w;
    }
    fill(dist, dist + n + 2, INF);
    for (int i=1;i<=n;i++){
        if (train[i]){
            dist[i] = train[i];
        }
    }
    dist[1] = 0;
    {
        set<pli> setdah;
        for (int i=1;i<=n;i++){
            if (dist[i] < INF){
                setdah.insert(mp(dist[i], i));
            }
        }
        while (!setdah.empty()){
            auto tp = *setdah.begin();
            setdah.erase(tp);
            ll cur = tp.fi;
            int node = tp.se;
            for (auto x : adj[node]){
                if (dist[x.fi] >= cur + x.se){
                    if (train[x.fi]) mark[x.fi] = 1;
                    setdah.erase(mp(dist[x.fi], x.fi));
                    dist[x.fi] = cur + x.se;
                    setdah.insert(mp(dist[x.fi], x.fi));
                }
            }
        }
        for (int i=1;i<=n;i++) if (mark[i]) ans++;
    }
    cout << ans << el;

    return 0;
}