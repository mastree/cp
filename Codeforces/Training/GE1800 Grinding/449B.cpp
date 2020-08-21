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

const ll INF = 1e18;
const int N = 1e5 + 4;

int n, m ,k;
vector <pair<int, ll>> adl[N];
ll dist[N];
bool train[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=0;i<m;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adl[a].pb(mp(b, w));
        adl[b].pb(mp(a, w));
    }

    set <pair<ll, int>> ss;
    dist[1] = 0;
    ss.insert(mp(dist[1], 1));
    for (int i=2;i<=n;i++){
        dist[i] = INF;
        ss.insert(mp(dist[i], i));
    }

    for (int i=0;i<k;i++){
        int a;
        ll w;
        cin >> a >> w;
        if (dist[a] > w){
            ss.erase(mp(dist[a], a));
            dist[a] = w;
            ss.insert(mp(dist[a], a));
            train[a] = 1;
        }
    }

    while (!ss.empty()){
        auto cur = (*ss.begin());
        ss.erase(ss.begin());

        for (auto x : adl[cur.se]){
            if (dist[x.fi] >= dist[cur.se] + x.se){
                if (train[x.fi]){
                    train[x.fi] = 0;
                }
                ss.erase(mp(dist[x.fi], x.fi));
                dist[x.fi] = dist[cur.se] + x.se;
                ss.insert(mp(dist[x.fi], x.fi));
            }
        }
    }

    int ans = 0;
    for (int i=1;i<=n;i++){
        if (train[i]) ans++;
    }
    cout << k-ans << el;

    return 0;
}