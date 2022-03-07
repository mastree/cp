#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;

const int N = 1e5 + 10;
const ll INF = 1e18;

int n, m;
pii s, t;
int snode, tnode;
vector<pii> pt;
int nodecnt;
vector<pil> adj[N * 4];
vector<pair<pii, int>> vec;

bool comp(const pair<pii, int>& a, const pair<pii, int>& b){
    return a.fi.se < b.fi.se;
}

void init(){
    for (auto x : pt){
        vec.pb(mp(x, 0));
    }
    sort(vec.begin(), vec.end());
    {
        for (auto& x : vec){
            x.se = ++nodecnt;
            if (x.fi == s) snode = nodecnt;
            if (x.fi == t) tnode = nodecnt;
        }
    }
    pii xx, yy;
    {
        int len = vec.size();
        vector<int> nodes;
        ll bef = -1;
        for (int i=0;i<len - 1;i++){
            nodes.pb(vec[i].se);
            if (vec[i].fi.fi != vec[i + 1].fi.fi){
                nodecnt++;
                for (auto x : nodes){
                    adj[nodecnt].pb(mp(x, 0LL));
                    adj[x].pb(mp(nodecnt, 0LL));
                }
                if (bef != -1){
                    adj[nodecnt].pb(mp(nodecnt - 1, vec[i].fi.fi - bef));
                    adj[nodecnt - 1].pb(mp(nodecnt, vec[i].fi.fi - bef));
                }
                bef = vec[i].fi.fi;
                nodes.clear();
            }
        }
        nodes.pb(vec[len - 1].se);
        nodecnt++;
        for (auto x : nodes){
            adj[nodecnt].pb(mp(x, 0LL));
            adj[x].pb(mp(nodecnt, 0LL));
        }
        if (bef != -1){
            adj[nodecnt].pb(mp(nodecnt - 1, vec[len - 1].fi.fi - bef));
            adj[nodecnt - 1].pb(mp(nodecnt, vec[len - 1].fi.fi - bef));
        }
        xx = mp(len, nodecnt);
    }
    {
        sort(vec.begin(), vec.end(), &comp);
        int len = vec.size();
        vector<int> nodes;
        ll bef = -1;
        for (int i=0;i<len - 1;i++){
            nodes.pb(vec[i].se);
            if (vec[i].fi.se != vec[i + 1].fi.se){
                nodecnt++;
                for (auto x : nodes){
                    adj[nodecnt].pb(mp(x, 0LL));
                    adj[x].pb(mp(nodecnt, 0LL));
                }
                if (bef != -1){
                    adj[nodecnt].pb(mp(nodecnt - 1, vec[i].fi.se - bef));
                    adj[nodecnt - 1].pb(mp(nodecnt, vec[i].fi.se - bef));
                }
                bef = vec[i].fi.se;
                nodes.clear();
            }
        }
        nodes.pb(vec[len - 1].se);
        nodecnt++;
        for (auto x : nodes){
            adj[nodecnt].pb(mp(x, 0LL));
            adj[x].pb(mp(nodecnt, 0LL));
        }
        if (bef != -1){
            adj[nodecnt].pb(mp(nodecnt - 1, vec[len - 1].fi.se - bef));
            adj[nodecnt - 1].pb(mp(nodecnt, vec[len - 1].fi.se - bef));
        }
        yy = mp(xx.se + 1, nodecnt);
    }
}

ll dp[N * 4];
void solve(){
    fill(dp, dp + nodecnt + 2, INF);
    set<pli> setdah;
    dp[snode] = 0;
    setdah.insert(mp(0LL, snode));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int node = tp.se;
        if (node == tnode) continue;
        ll cur = tp.fi;
        for (auto x : adj[node]){
            if (x.fi == tnode) continue;
            if (dp[x.fi] > cur + x.se){
                setdah.erase(mp(dp[x.fi], x.fi));
                dp[x.fi] = cur + x.se;
                setdah.insert(mp(dp[x.fi], x.fi));
            }
        }
    }
    if (snode == tnode){
        cout << 0 << el;
        return;
    }
    ll ans = INF;
    for (auto x : vec){
        if (x.se == tnode) continue;
        ll tam = abs(x.fi.fi - t.fi) + abs(x.fi.se - t.se);
        ans = min(ans, dp[x.se] + tam);
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> s.fi >> s.se >> t.fi >> t.se;
    pt.pb(s);
    pt.pb(t);
    for (int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        pt.pb(mp(a, b));
    }
    init();
    solve();

    return 0;
}