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

unordered_map<int, bool> gak[N];

int par[N], sz[N];
vector<int> uni[N];

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
    for (auto x : uni[b]){
        uni[a].pb(x);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        gak[a][b] = 1;
        gak[b][a] = 1;
    }
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
        uni[i].pb(i);
    }

    for (int i=1;i<=n;i++){
        if (par[i] == i && sz[i] == 1){
            int cur = i;
            for (int j=i+1;j<=n;j++){
                bool bisa = 0;
                for (auto x : uni[cur]){
                    if (!gak[x][j]){
                        bisa = 1;
                        break;
                    }
                }
                if (bisa) make(cur, j);
                cur = find(cur);
            }
        }
    }

    vector<int> ans;
    for (int i=1;i<=n;i++){
        if (par[i] == i) ans.pb(sz[i]);
    } 
    sort(ans.begin(), ans.end());
    cout << ans.size() << el;
    for (auto x : ans){
        cout << x << " ";
    }
    cout << el;

    return 0;
}