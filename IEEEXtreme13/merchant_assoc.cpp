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

const int N = 200010;

int n, m;
ll cost[N];
vector <int> adl[N];
vector <int> merch_start;

pair<int,ll> up[19][N]; // node, min-cost on path except for a and b

int dep[N];
bool vis[N];
void dfs_tour(int a, int par){
    vis[a]=1;
    dep[a]=dep[par]+1;
    up[0][a]=mp(par,cost[par]);

    for (auto dest : adl[a]){
        if (!vis[dest]){
            dfs_tour(dest, a);
        }
    }
}

pil ask(int a, int b){
    int start=a;
    if (dep[a]<dep[b]) swap(a,b);

    ll ansmin=MOD;
    for (int i=18;i>=0;i--){
        if (up[i][a].fi==0) continue;
        if (dep[a]-(1 << i)>=dep[b]){
            ansmin=min(ansmin,up[i][a].se);
            a=up[i][a].fi;
        }
    } 

    for (int i=18;i>=0;i--){
        if (up[i][a].fi==0 || up[i][b].fi==0) continue;
        if (up[i][a].fi!=up[i][b].fi){
            ansmin=min(ansmin,up[i][a].se);
            a=up[i][a].fi;
            ansmin=min(ansmin,up[i][b].se);
            b=up[i][b].fi;
        }
    }

    if (a!=b){
        int i=0;
        ansmin=min(ansmin,up[i][a].se);
        a=up[i][a].fi;
        ansmin=min(ansmin,up[i][b].se);
        b=up[i][b].fi;
    }

    return mp(a,min(ansmin, cost[start])); // LCA, minimum cost
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> cost[i];
    }

    for (int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }

    cin >> m;
    for (int i=0;i<m;i++){
        int st;
        cin >> st;
        merch_start.pb(st);
    }

    dep[1]=-1;
    dfs_tour(1,1);

    for (int i=1;i<19;i++){
        for (int j=1;j<=n;j++){
            if (up[i-1][j].fi==0) continue;
            if (up[i-1][up[i-1][j].fi].fi==0) continue;

            up[i][j].fi=up[i-1][up[i-1][j].fi].fi;
            up[i][j].se=min(up[i-1][j].se, up[i-1][up[i-1][j].fi].se);
        }
    }

    // for (int i=1;i<=n;i++){
    //     cout << up[0][i].fi << ":" << cost[up[0][1].fi] << " ";
    // }cout << el;

    // cout << ask(4,5).fi << " " << ask(4,5).se << el;
    // cout << ask(3,1).fi << " " << ask(3,1).se << el;
    // cout << ask(8,10).fi << " " << ask(8,10).se << el;

    return 0;
}