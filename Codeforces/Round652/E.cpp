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

const int N = 3e5 + 10;

int n, m;
int ar[N];
pii tar[N];
int cnt[N];

bool kur[N];
vector<int> v[N];
vector<int> vnext[N]; 
set<int> setdah[N];

vector<int> ans;

int deg[N];
vector<int> adl[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=m;i++){
        cin >> tar[i].fi >> tar[i].se;
        cnt[tar[i].fi]++;
        cnt[tar[i].se]++;
    }
    bool ok = 1;
    for (int i=1;i<=n;i++){
        if (ar[i] < cnt[i]){
            ok = 0;
            kur[i] = 1;
        } 
    }
    if (ok){
        cout << "ALIVE" << el;
        for (int j=1;j<=n;j++) cout << j << " "; cout << el;
        return 0;
    }

    int cnt = 0;
    for (int i=1;i<=m;i++){
        int a, b;
        a = tar[i].fi;
        b = tar[i].se;
        if (!kur[a] || !kur[b]){
            ans.pb(i);
            continue;
        }
        setdah[a].insert(i);
        setdah[b].insert(i);
        cnt++;
    }
    set<pii> sisa;
    for (int i=1;i<=n;i++){
        if (setdah[i].size()){
            sisa.insert(mp(ar[i], i));
        }
    }

    while (sisa.size() && cnt){
        auto temp = *sisa.begin();
        
        auto pp = *setdah[temp.se].begin();
        int a = tar[pp].fi;
        int b = tar[pp].se;
        ans.pb(pp);
        if (ar[a] || ar[b]){
            sisa.erase(mp(ar[a], a));
            sisa.erase(mp(ar[b], b));
            ar[a] = max(0, ar[a] - 1);
            ar[b] = max(0, ar[b] - 1);
            sisa.pb(mp(ar[a], a));
            sisa.pb(mp(ar[b], b));
            setdah[]
        } else{
            cout << "DEAD" << el;
            return 0;
        }
    }
    if (cnt){
        cout << "DEAD" << el;
        return 0;
    }

    return 0;
}