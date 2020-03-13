/*
LCA W/ EULER TOUR

problem statement :
https://www.codechef.com/problems/TALCA

INPUT:
N (node)
u v (edge of the tree(N-1))
...
Q (query)
r a b (r=root, a=node1, b=node2)
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

const int N = 200007;

vector <pii> euler; // node, height;
int n, q, dep[N], debut[N];
vector <int> adl[N];
bool vis[N];
pii stree[8*N];
int len; // length euler tour;

void dfs_tour(int a, int h){
    dep[a]=h;
    euler.pb(mp(a,h));
    vis[a]=1;
    debut[a]=euler.size()-1;
    for (auto dest : adl[a]){
        if (vis[dest]) continue;
        dfs_tour(dest, h+1);
        euler.pb(mp(a,h));
    }
}

void constree(int low, int high, int pos){
    if (low==high){
        stree[pos]=euler[low];
        return;
    }

    int left=pos*2+1;
    int mid=(low+high)/2;
    constree(low,mid,left);
    constree(mid+1,high,left+1);

    if (stree[left].se<stree[left+1].se){
        stree[pos]=stree[left];
    } else{
        stree[pos]=stree[left+1];
    }
}

pii ask(int qlow, int qhigh, int low, int high, int pos){
    if (qhigh<low || qlow>high){
        return mp(1,MOD);
    }

    if (qlow<=low && qhigh>=high){
        return stree[pos];
    }

    int left=pos*2+1, mid=(low+high)/2;
    
    pii res1=ask(qlow,qhigh,low,mid,left);
    pii res2=ask(qlow,qhigh,mid+1,high,left+1);
    
    if (res1.se>res2.se){
        return res2;
    } 
    return res1;
}

pii lca(int a, int b){
    int tma=min(debut[a],debut[b]);
    int tmb=max(debut[a],debut[b]);
    return ask(tma, tmb, 0, len-1, 0); 
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }

    dfs_tour(1, 0);
    len=euler.size();
    constree(0,len-1,0);
    
    cin >> q;
    while(q--){
        int r, a, b;
        cin >> r >> a >> b;

        pii lab=lca(a,b);
        pii lra=lca(r,a);
        pii lrb=lca(r,b);

        vector <pii> ans;
        ans.pb(mp(lab.se,lab.fi));
        ans.pb(mp(lra.se,lra.fi));
        ans.pb(mp(lrb.se,lrb.fi));

        sort(ans.begin(),ans.end(),greater<pii>());
        cout << ans[0].se << el;
    }

    return 0;
}