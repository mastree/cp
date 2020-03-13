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

const int N = 2008;

int n;
int ar[N][N];
int par[N];
int sz[N];
vector <int> adl[N];

int find(int a){
    if (par[a]==a) return a;
    return par[a] = find(par[a]);
}

void make(int a, int b){
    a=find(a);
    b=find(b);

    if (a==b) return;

    if (sz[a]<sz[b]){
        swap(a,b);
    }

    par[b]=a;
    sz[a]+=sz[b];
}

ll jarak[N]; // jarak ke-root(1);
int up[12][N], dep[N];
vector <pair<int,pii>> v; // weight, node, dest
void dfs_jarak(int node, int p, ll j){
//    cout << node << el;
    jarak[node]=j;
    up[0][node]=p;
    dep[node]=dep[p]+1;

    for (auto dest : adl[node]){
        if (dest!=p){
            dfs_jarak(dest, node, j+(ll)ar[node][dest]);
        //    cout << node << el;
        }
    }
}

void make_lift(){
    for (int i=1;i<11;i++){
        for (int j=1;j<=n;j++){
            if (!up[i-1][j]) continue;
            if (!up[i-1][up[i-1][j]]) continue;

            up[i][j]=up[i-1][up[i-1][j]];
        }
    }
}

int lca(int a, int b){
    if (dep[a]<dep[b]){
        swap(a,b);
    }

    for (int i=11;i>=0;i--){
        if (up[i][a]==0) continue;
        if (dep[a]-(1 << i)>=dep[b]){
            a=up[i][a];
        }
    }

    for (int i=11;i>=0;i--){
        if (up[i][a]==0 || up[i][b]==0) continue;
        if (up[i][a]!=up[i][b]){
            a=up[i][a];
            b=up[i][b];
        }
    }

    if (a!=b){
        a=up[0][a];
        b=up[0][b];
    }

    return a;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<N;i++){
        par[i]=i;
        sz[i]=1;
    }

    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> ar[i][j];
            v.pb(mp(ar[i][j],mp(i,j)));
        }
    }

    for (int i=1;i<=n;i++){
        if (ar[i][i]!=0){
            cout << "NO" << el;
            return 0;
        }
        for (int j=1;j<=n;j++){
            if (i==j) continue;
            if (ar[i][j]!=ar[j][i] || ar[i][j]==0){
                cout << "NO" << el;
                return 0;
            }
        }
    }

    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++){
    //         int a=find(i);
    //         int b=find(j);
    //         if (a==b) continue;
    //         adl[i].pb(j);
    //         adl[j].pb(i);
    //         make(i,j);
    //     }
    // }

    sort(v.begin(),v.end());
    for (auto cur : v){
        int a=cur.se.fi;
        int b=cur.se.se;
        if (find(a)==find(b)) continue;

        adl[a].pb(b);
        adl[b].pb(a);
        make(a,b);
    }

    dep[0]=-1;
    dfs_jarak(1, 0, 0);
    make_lift();

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int lc=lca(i,j);
            if ((ar[i][lc]+ar[j][lc]!=ar[i][j]) || (ar[1][i]+ar[1][j]-2*ar[1][lc]!=ar[i][j])){
                cout << "NO" << el;
                return 0;
            }
        }
    }

    cout << "YES" << el;

    return 0;
}