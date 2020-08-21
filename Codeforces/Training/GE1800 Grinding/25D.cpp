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

const int N = 1e3 + 10;

int n;
vector <int> adl[N];
vector <pii> edl;
vector <pii> dup;
vector <pii> take[N];
// vector <bool> taken;

int par[N], sz[N];

int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;

    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
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
        edl.pb(mp(a, b));
    }

    for (int i=0;i<N;i++){
        par[i] = i;
        sz[i] = 1;
    }

    for (auto x : edl){
        if (find(x.fi) == find(x.se)){
            dup.pb(x);
            // taken.pb(0);
        }
        else {
            make(x.fi, x.se);
        }
    }

    int scnt = 0;
    vector <int> v;
    for (int i=1;i<=n;i++){
        if (par[i] == i){
            v.pb(i);
            scnt++;
        }
    }
    if (scnt == 1){
        cout << 0 << el;
        return 0;
    }

    for (auto x : dup){
        int pp = find(x.fi);
        take[pp].pb(x);
    }

    cout << scnt - 1 << el;
    for (int i=0;i<scnt;i++){
        for (int j=0;j<scnt;j++){
            if (i==j || find(v[i]) == find(v[j])) continue;
            if (take[v[i]].size()){
                auto temp = take[v[i]][take[v[i]].size() - 1];
                cout << temp.fi << " " << temp.se << " " << find(v[i]) << " " << find(v[j]) << el;
                make(v[i], v[j]);
                take[v[i]].pop_back();
                continue;
            } 
            if (take[v[j]].size()){
                auto temp = take[v[j]][take[v[j]].size() - 1];
                cout << temp.fi << " " << temp.se << " " << find(v[i]) << " " << find(v[j]) << el;
                make(v[i], v[j]);
                take[v[j]].pop_back();
                continue;
            } 
        }
    }

    return 0;
}