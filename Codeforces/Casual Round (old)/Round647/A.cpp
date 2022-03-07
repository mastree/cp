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

const int N = 5e5 + 10;

int n, m;
vector<int> adl[N];
int t[N];
pii ar[N];

int col[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    for (int i=1;i<=n;i++){
        cin >> t[i];
        ar[i] = mp(t[i], i);
    }
    sort(ar + 1, ar + n + 1);

    vector<int> ans;
    for (int i=1;i<=n;i++){
        int ambil = ar[i].fi;
        int node = ar[i].se;
        set<int> setdah;
        bool bisa = 1;
        for (auto x : adl[node]){
            if (col[x] && col[x] <= ambil){
                if (col[x] == ambil){
                    bisa = 0;
                    break;
                } else{
                    setdah.insert(col[x]);
                } 
            }
        }
        if (!bisa || setdah.size() != ambil - 1){
            cout << -1 << el;
            return 0;
        }
        col[node] = ambil;
        ans.pb(node);
    }
    for (auto x : ans){
        cout << x << " ";
    }
    cout << el;

    return 0;
}