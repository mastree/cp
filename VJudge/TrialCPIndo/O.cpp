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

int n, m;
vector<int> adl[N];
int par[N], sz[N];
ll cnt[N];

int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}
void init(){
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    init();
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
        make(a, b);
    } 
    bool ok = 1;
    for (int i=1;i<=n;i++){
        cnt[find(i)] += (int) adl[i].size();
    }
    for (int i=1;i<=n;i++){
        if (par[i] == i && sz[i] >= 3){
            ll temp = (ll)sz[i];
            temp = temp * (temp - 1);
            if (cnt[i] != temp) ok = 0;
        }
    }
    if (ok) cout << "YES" << el;
    else cout << "NO" << el;

    return 0;
}