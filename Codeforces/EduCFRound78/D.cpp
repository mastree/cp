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

int n;
pii ar[N];
set<pii> le,ri; // koor, id;
// map <int, pii> info;



void dfs(int node){
    int a = ar[node].fi;
    int b = ar[node].se;
    auto awal = le.upper_bound(a);
    auto akhir = ri.
    while ()
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
        le.insert(mp(ar[i].fi, i));
        ri.insert(mp(ar[i].se, i));
    }



    return 0;
}