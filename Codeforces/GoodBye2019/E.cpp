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

const int N = 1e3 + 7;

int n;
pair<ll, ll> ar[N];
int par[N];
int sz[N];

vector <pair<ll, pii>> sorted; // jarak, id1, id2;
vector <int> ans;

vector<int> ac;
int couple[N];
// map<int, int> couple;
map<int, int> grup; // 1==A, 2==B;

int find(int a){
    if (par[a] == a) return a;
    par[a] = find(par[a]);
    return par[a];
}

void make(int a, int b){
    a = find(a);
    b = find(b);

    if (a==b) return;
    if (sz[a]<sz[b]) swap(a,b);

    par[b]=a;
    sz[a]+=sz[b];
}

bool cmp(pair<ll, pii> a, pair<ll, pii> b){
    return a.fi < b.fi;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<=N;i++){
        par[i] = i;
        sz[i] = 1;
    }
    sz[0]=0;

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
    }

    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            ll dx = abs(ar[i].fi - ar[j].fi);
            ll dy = abs(ar[i].se - ar[j].se);
            ll dist = dx * dx + dy * dy;
            sorted.pb(mp(dist,mp(i,j)));
        }
    }

    sort(sorted.begin(), sorted.end(), cmp);
    int len = sorted.size();
    ll bef = 0;
    for (int i=0;i<len;i++){
        ll dist = sorted[i].fi;
        int a = sorted[i].se.fi;
        int b = sorted[i].se.se;
        if (dist!=bef){
            bef = dist;
            for (auto x : ac){
                couple[x] = 0;
            }
            ac.clear();
        }
        if (couple[a]){
            make(couple[a], b);
        }

        if (couple[b]){
            make(a, couple[b]);
        }
        couple[a] = b;
        couple[b] = a;
        ac.pb(a);
        ac.pb(b);
    }


    int cur = 1;
    for (int i=1;i<=n;i++){
        int a = find(i);
        if (grup[a]) continue;

        grup[a] = cur;
        cur++;
    }

    for (int i=1;i<=n;i++){
        if (grup[find(i)] % 2 || grup[find(i)]==0){
            ans.pb(i);
        }
    }

    cout << ans.size() << el;
    for (auto x : ans){
        cout << x << " ";
    }
    cout << el;

    return 0;
}