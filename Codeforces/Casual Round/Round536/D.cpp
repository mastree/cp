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
unordered_map<int, bool> udah[N];
vector<int> adl[N];

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
        if (!udah[a][b]){
            udah[a][b] = 1;
            udah[b][a] = 1;
            adl[a].pb(b);
            adl[b].pb(a);
        }
    }
    set<int> ekspan;
    vector<int> ans;
    // ans.pb(1);
    ekspan.insert(1);
    while (!ekspan.empty()){
        int temp = *ekspan.begin();
        ekspan.erase(temp);
        ans.pb(temp);
        vis[temp] = 1;
        for (auto x : adl[temp]){
            if (!vis[x]){
                ekspan.insert(x);
            }
        }
    }
    for (auto x : ans){
        cout << x << " ";
    }
    cout << el;

    return 0;
}