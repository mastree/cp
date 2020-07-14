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

const int N = 1e5 + 10;

int n, m;
set<int> adl[N];
bool vis[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        if (a == b) continue;
        adl[a].insert(b);
        adl[b].insert(a);
    }    
    set<int> setdah;
    vector<int> ans;
    setdah.insert(1);
    while (!setdah.empty()){
        int node = *setdah.begin();
        setdah.erase(node);
        if (vis[node]) continue;
        vis[node] = 1;
        ans.pb(node);
        for (auto x : adl[node]){
            if (!vis[x]) setdah.insert(x);
        }
    }
    for (auto x : ans) cout << x << " ";cout << el;

    return 0;
}