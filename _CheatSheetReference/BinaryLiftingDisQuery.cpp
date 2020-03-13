/*
LCA W/ BINARY LIFTING

problem statement :
https://www.spoj.com/problems/DISQUERY/

INPUT:
N (node count)
u v w (edge u-v and weight)
...
Q (query)
a b (node1, node2)
*/

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

const int N = 100007;

int n;
vector <pii> adl[N]; // dest, weight;
int len, dep[N];
pair<int,pii> up[19][N]; // node, min, max

bool vis[N];
void dfs_tour(int a, int par, int w){
    vis[a]=1;
    dep[a]=dep[par]+1;
    if (a!=1) up[0][a]=mp(par,mp(w,w));
    else up[0][a]=mp(0,mp(0,0));

    for (auto dest : adl[a]){
        if (!vis[dest.fi]){
            dfs_tour(dest.fi, a, dest.se);
        }
    }
}

pii ask(int a, int b){
    if (dep[a]<dep[b]) swap(a,b);

    int ansmin=MOD,ansmax=-1;
    for (int i=18;i>=0;i--){
        if (up[i][a].fi==0) continue;
        if (dep[a]-(1 << i)>=dep[b]){
            ansmin=min(ansmin,up[i][a].se.fi);
            ansmax=max(ansmax,up[i][a].se.se);
            a=up[i][a].fi;
        }
    } 

    for (int i=18;i>=0;i--){
        if (up[i][a].fi==0 || up[i][b].fi==0) continue;
        if (up[i][a].fi!=up[i][b].fi){
            ansmin=min(ansmin,up[i][a].se.fi);
            ansmax=max(ansmax,up[i][a].se.se);
            a=up[i][a].fi;
            ansmin=min(ansmin,up[i][b].se.fi);
            ansmax=max(ansmax,up[i][b].se.se);
            b=up[i][b].fi;
        }
    }

    if (a!=b){
        int i=0;
        ansmin=min(ansmin,up[i][a].se.fi);
        ansmax=max(ansmax,up[i][a].se.se);
        a=up[i][a].fi;
        ansmin=min(ansmin,up[i][b].se.fi);
        ansmax=max(ansmax,up[i][b].se.se);
        b=up[i][b].fi;
    }

    return mp(ansmin,ansmax);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n-1;i++){
        int a,b,w;
        cin >> a >> b >> w;
        adl[a].pb(mp(b,w));
        adl[b].pb(mp(a,w));
    }

    dep[1]=-1;
    dfs_tour(1,1,0);

    for (int i=1;i<19;i++){
        for (int j=1;j<=n;j++){
            if (up[i-1][j].fi==0) continue;
            if (up[i-1][up[i-1][j].fi].fi==0) continue;

            up[i][j].fi=up[i-1][up[i-1][j].fi].fi;
            up[i][j].se.fi=min(up[i-1][j].se.fi, up[i-1][up[i-1][j].fi].se.fi);
            up[i][j].se.se=max(up[i-1][j].se.se, up[i-1][up[i-1][j].fi].se.se);
        }
    }

    int q;
    cin >> q;
    while (q--){
        int a,b;
        cin >> a >> b;

        pii ans=ask(a,b);
        cout << ans.fi << " " << ans.se << el;
    }

    return 0;
}