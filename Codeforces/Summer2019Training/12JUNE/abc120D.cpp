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

int n,m;
int par[100005],sz[100005];
pair <int,int> ar[100005];
ll cnt;

int parent(int a){
    if (par[a]!=a) return parent(par[a]);
    return a;
}

void make(int a, int b){
    int pa=parent(a);
    int pb=parent(b);

    if (pa==pb) return;

    cnt-=(ll)(sz[pa])*((ll)(sz[pb]));
    if (sz[pa]>=sz[pb]){
        sz[pa]+=sz[pb];
        par[pb]=pa;
    } else{
        sz[pb]+=sz[pa];
        par[pa]=pb;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    cnt=(ll)n*((ll)(n-1))/2;

    for (int i=1;i<=n;i++){
        par[i]=i;
        sz[i]=1;
    }

    for (int i=0;i<m;i++){
        cin >> ar[i].fi >> ar[i].se;
    }

    ll ans[m+1];
    for (int i=m;i>0;i--){
        ans[i]=cnt;
        make(ar[i-1].fi,ar[i-1].se);
    }

    for (int i=1;i<=m;i++) cout << ans[i] << el;

    return 0;
}