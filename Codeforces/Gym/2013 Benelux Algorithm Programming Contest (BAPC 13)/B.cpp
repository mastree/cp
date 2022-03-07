#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 16;

int q;
int n, c, mon;
pii ar[N];

bool comp(pii &a, pii &b){
    if (a.se != b.se) return a.se > b.se;
    return a.fi < b.fi;
}

void solve(){
    cin >> n >> c >> mon;
    for (int i=0;i<n;i++){
        cin >> ar[i].fi >> ar[i].se;
    }
    sort(ar, ar + n, &comp);
    
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}