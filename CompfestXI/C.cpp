#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define fr front

using namespace std;

vector <pil> adlist[200100]; 
int dep[200100],n;
ll dis[200100];
bool vis[200100];
queue <int> child[200100];
pair <int,int> path[400200], stree[2000000];


void dfs(int a,int cur,int dist){
    dep[a]=cur;
    dis[a]=dist;
    vis[a]=1;
    for (auto x : adlist[a]){
        if (!vis[x.fi]){
            dfs(x.fi,cur+1,dist+x.se);
        }
    }
}

void constree(int l, int r, int pos){
    if (l==r) stree[pos]=mp(path[l].se,l);
    else {
        int mid=(l+r)/2;
        constree(l,mid,pos*2+1);
        constree(mid+1,r,pos*2+2);

        stree[pos]=min(stree[pos*2+1],stree[pos*2+2]);
    }
}

pair<int,int> cari(int ql, int qr, int l, int r, int pos){
    if (l>=ql && r<=qr) return stree[pos];
    if (r<ql || l>qr) return {MOD,0};

    int mid=(l+r)/2;
    return min(cari(ql,qr,l,mid,pos*2+1),cari(ql,qr,mid+1,r,pos*2+2));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> n >> q;

    for (int e=0;e<n-1;e++){
        int a,b;
        ll c;
        cin >> a >> b >> c;

        a--;
        b--;
        adlist[a].pb(mp(b,c));
        adlist[b].pb(mp(a,c));
    }

    dfs(0,0,0);

    for (int i=0;i<n;i++){
        for (auto x : adlist[i]){
            if (dep[i]<dep[x.fi]){
                child[i].push(x.fi);
            }
        }
    }

    stack <int> st;
    st.push(0);
    int firstap[n],depth=0,itt=0;

    for (int i=0;i<n;i++) firstap[i]=MOD;
    firstap[0]=0;

    while (!st.empty()){
        path[itt]=mp(st.top(),depth);
        int x=st.top();

        if (!child[x].empty()) {
            itt++;
            depth++;
            st.push(child[x].fr());
            path[itt]=mp(child[x].fr(),depth);
            firstap[child[x].fr()]=min(firstap[child[x].fr()],itt);
            child[x].pop();
        }
        else {
            st.pop();
            depth--;
            itt++;
        }

    }
    constree(0,itt-1,0);

    while (q--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        int p1=firstap[a],p2=firstap[b];

        pair <int,int> sim=cari(min(p1,p2),max(p1,p2),0,itt-1,0);
        int par=path[sim.se].fi;
     //   cerr << par << el;
        cout << dis[a]+dis[b]-2*dis[par] << el;
    }

    return 0;
}