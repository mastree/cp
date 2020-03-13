#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

int n;
vector <pii> ad[100007];
bool vis[100007];
bool col[100007];

void dfs(int a,bool c){
    col[a]=c;
    for (auto x : ad[a]){
        if (vis[x.fi]) continue;
        vis[x.fi]=1;
        if (x.se&1){
            dfs(x.fi,!c);
        } else {
            dfs(x.fi,c);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    memset(vis,0,n+3);
    memset(col,0,n+3);
    for (int i=1;i<n;i++){
        int a,b,w;
        cin >> a >> b >> w;

        ad[a].pb(mp(b,w));
        ad[b].pb(mp(a,w));
    }

    vis[1]=1;
    dfs(1,0);

    for (int i=1;i<=n;i++) cout << (col[i]) << el;

    return 0;
}