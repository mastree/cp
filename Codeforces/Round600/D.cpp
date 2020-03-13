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

const int N = 2e5 + 10;

int n,m;

vector <int> adl[N];
int par[N];
int sz[N];
pii range[N];
int mx[N];

int find(int a){
    if (par[a] == a){
        return a;
    }

    return par[a] = find(par[a]);
}

void make(int a, int b){
    a = find(a);
    b = find(b);

    if (a==b) return;

    if (sz[a]<sz[b]){
        swap(a,b);
    }

    sz[a]+=sz[b];
    par[b]=a;
}

void make_pasti(int a, int b){
    a = find(a);
    b = find(b);

    if (sz[a]<sz[b]){
        swap(a,b);
    }

    mx[a]=max(mx[a], mx[b]);

    sz[a]+=sz[b];
    par[b]=a;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i=0;i<N;i++){
        par[i]=i;
        sz[i]=1;
    }

    for (int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);

        make(a,b);
    }


    for (int i=1;i<=n;i++){
        mx[find(i)] = max(mx[find(i)], i);
    }

    int ans=0;
    for (int i=1;i<n;i++){
        int last = mx[find(i)];
        // cout << last << el;
        if (last>i+1){
            if (find(i+1)!=find(i)){
                // cout << i << " " << i+1 << el;
                make_pasti(i,i+1);
                ans++;
            }
        }
    }

    cout << ans << el;

    return 0;
}