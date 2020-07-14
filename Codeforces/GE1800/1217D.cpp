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

const int N = 5e3 + 10;

int n, m;
vector<int> adl[N];
vector<int> in[N];
vector<pii> edge;
map<pii, int> warna;
// int par[N];
int color[N];

bool dfs_cycle(int node){
    if (color[node] == 2) return 0;
    else if (color[node] == 1) return 1;
    color[node] = 1;
    bool ret = 0;
    for (auto x : adl[node]){
        ret |= dfs_cycle(x);
    }
    color[node] = 2;
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        in[b].pb(a);
        edge.pb(mp(a, b));
    }
    bool det = 0;
    for (int i=1;i<=n;i++){
        det |= dfs_cycle(i);
    }
    if (!det){
        cout << 1 << el;
        for (int i=1;i<=edge.size();i++){
            cout << 1 << " ";
        }
        cout << el;
    } else{
        for (int i=1;i<=n;i++){
            if (in[i].empty()){
                for (auto x : adl[i]){
                    if (!warna[mp(i, x)]){
                        warna[mp(i, x)] = 1;
                    }
                }
            } else if (adl[i].empty()){
                for (auto x : in[i]){
                    if (!warna[mp(x, i)]){
                        warna[mp(x, i)] = 1;
                    }
                }
            } else{
                for (auto x : adl[i]){
                    if (!warna[mp(i, x)]){
                        warna[mp(i, x)] = 1;
                    }
                }
                for (auto x : in[i]){
                    if (!warna[mp(x, i)]){
                        warna[mp(x, i)] = 2;
                    }
                }
            }
        }
        cout << 2 << el;
        for (auto x : edge){
            cout << warna[x] << " ";
        }
        cout << el;
    }

    return 0;
}