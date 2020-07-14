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

const int N = 3e5 + 10;

int n, k, d;
set<int> adl[N];
bool pol[N];
vector<int> vpol;

unordered_map<int, int> edid[N];

vector<pii> ans;
pii dp[N]; // jarak, source

void dfs(int node, int p, int source){
    if (dp[node].se != source){
        ans.pb(mp(p, node));
        adl[node].erase(p);
        return;
    }
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs(x, node, source);
    }
}

void solve(){
    queue<pair<int, pii>> qu; // node, jarak, source
    for (auto x : vpol){
        qu.push(mp(x, mp(0, x)));
    } 
    fill(dp, dp + n + 2, mp(0, 0));
    while (!qu.empty()){
        auto temp = qu.front();
        qu.pop();
        if (dp[temp.fi].se) continue;
        dp[temp.fi] = temp.se;
        for (auto x : adl[temp.fi]){
            if (!dp[x].se){
                qu.push(mp(x, mp(temp.se.fi + 1, temp.se.se)));
            }
        }
    }
    for (auto x : vpol){
        dfs(x, x, x);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> d;
    for (int i=1;i<=k;i++){
        int a;
        cin >> a;
        if (!pol[a]) vpol.pb(a);
        pol[a] = 1;
    }
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].insert(b);
        adl[b].insert(a);
        edid[a][b] = i;
        edid[b][a] = i;
    }
    solve();
    cout << ans.size() << el;
    for (auto x : ans){
        cout << edid[x.fi][x.se] << " ";
    }
    cout << el;

    return 0;
}