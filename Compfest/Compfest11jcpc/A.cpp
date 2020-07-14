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
const ll INF = 1e18;

int n, m, k;
vector <pil> adl[N]; 
vector <int> tel[N];
vector <int> nodeWtel[N];
ll telprice[N];

ll distA[N];
ll teldistA[N];

void make_dist(){
    fill(distA, distA + n + 2, INF);
    fill(teldistA, teldistA + m + 2, INF);
    distA[1] = 0;
    set <pli> setdah;
    for (int i=1;i<=n;i++){
        setdah.insert(mp(distA[i], i));
    }

    while (!setdah.empty()){
        auto it = setdah.begin();
        setdah.erase(it);
        int node = it->se;
        ll dist = it->fi;
        for (auto t : tel[node]){
            if (dist + telprice[t] < teldistA[t]){
                teldistA[t] = dist + telprice[t];
                for (auto dest : nodeWtel[t]){
                    if (teldistA[t] < distA[dest]){
                        setdah.erase(mp(distA[dest], dest));
                        distA[dest] = teldistA[t];
                        setdah.insert(mp(distA[dest], dest));
                    }
                }
            }
        }
        for (auto x : adl[node]){
            if (dist + x.se < distA[x.fi]){
                setdah.erase(mp(distA[x.fi], x.fi));
                distA[x.fi] = dist + x.se;
                setdah.insert(mp(distA[x.fi], x.fi));
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1;i<=m;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adl[a].pb(mp(b, w));
        adl[b].pb(mp(a, w));
    }
    for (int i=1;i<=n;i++){
        int len;
        cin >> len;
        for (int j=1;j<=len;j++){
            int a;
            cin >> a;
            tel[i].pb(a);
            nodeWtel[a].pb(i);
        }
    }
    for (int i=1;i<=m;i++){
        cin >> telprice[i];
    }
    make_dist();
    cout << distA[n] << el;

    return 0;
}