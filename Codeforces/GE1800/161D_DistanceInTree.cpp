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

const int N = 50005;

int n,k;
vector <int> adl[N];
ll child[N][1009], dep[N]; // node, child-depth
bool vis[N], vis2[N];
vector <int> curNode;
ll ans=0;

void dfs(int node, int par, int depth){
//    child[node][0]=1;
    curNode.pb(node);
    dep[node]=depth;
    for (auto chi : adl[node]){
        if (vis[chi]) continue;
        vis[chi]=1;
        dfs(chi,node,depth+1);
    }

    child[par][1]++;
//    cout << child[par][1] <<" " << par << el; 
    for (int i=0;i<500;i++){
        child[par][i+1]+=child[node][i];
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }

    vis[1]=1;
    dfs(1,0,0);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=k;j++){
            cout << "child " << i << " " << j << ": " << child[i][j] << el;
        }
    }
    for (int i=1;i<=n;i++){
    //    ans+=child[i][k];
    //    cout << i << " : " << el;
    //    cout << dep[i] << el;
        for (auto son : adl[i]){
    //        cout << son << " ";
            if (vis2[son]) continue;
    //        vis2[son]=1;
            for (int hand=1;hand<k;hand++){
                cout << i << " " << son << " " << child[son][hand-1]*(child[i][k-hand]-child[son][k-hand-1]) << el;
                ans+=child[son][hand-1]*(child[i][k-hand]-child[son][k-hand-1]);
            }
        }
        vis2[i]=1;
    //    cout << el << ans << el;
    }

    cout << ans/2 << el;

    return 0;
}