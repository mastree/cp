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

int n;
vector <int> des[N];
map <int, int> ada, balik;

vector <int> hub[N];
vector <pii> adl[N];

vector <pair<pii, int>> ans;
bool vis[N];

void sol(int node){
    if (vis[node]) return;
    vis[node] = 1;
    for (auto dest : adl[node]){
        if (vis[dest.fi]) continue;

        ans.pb(mp(mp(node, dest.fi), dest.se));
        sol(dest.fi);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    // cout << n << el;
    for (int i=1;i<=n;i++){
        int m;
        cin >> m;
        for (int j=0;j<m;j++){
            int a;
            cin >> a;
            des[i].pb(a);
            ada[a] = 1;
            // cout << a << " ";
        }
        // cout << el;
    }

    int cur = 1;
    for (auto x : ada){
        balik[cur] = x.fi;
        // cout << x.fi << " => " << cur << el;
        ada[x.fi] = cur++;
    }    

    for (int i=1;i<=n;i++){
        int m = des[i].size();
        for (int j=0;j<m;j++){
            des[i][j] = ada[des[i][j]];
            hub[des[i][j]].pb(i);
        }
    }

    // for (int i=1;i<cur;i++){
    //     for (auto x : hub[i]){
    //         cout << x << " ";
    //     }
    //     cout << el;
    // }
    
    for (int i=1;i<cur;i++){
        for (int j=0;j<hub[i].size()-1;j++){
            int a = hub[i][j];
            int b = hub[i][j+1];
            adl[a].pb(mp(b, i));
            adl[b].pb(mp(a, i));
        }
    }
    // cout << "tes" << el;

    sol(1);
    if (ans.size() == n-1){
        for (auto x : ans){
            cout << x.fi.fi << " " << x.fi.se << " " << balik[x.se] << el;
        }
    } else{
        cout << "impossible" << el;
    }

    return 0;
}