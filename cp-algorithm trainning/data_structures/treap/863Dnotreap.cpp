#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int n, q, m;
int ar[N];
pair<int, pii> quer[N];

int solve(int id){
    for (int i=q;i>=1;i--){
        int tipe = quer[i].fi;
        int l = quer[i].se.fi;
        int r = quer[i].se.se;

        if (id < l || r < id) continue;
        if (tipe == 1){
            if (id == l) id = r;
            else id--;
        } else{
            int range = r - l + 1;
            id = range - (id - l) + (l - 1);
        }
    }
    return ar[id];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=q;i++){
        cin >> quer[i].fi >> quer[i].se.fi >> quer[i].se.se;
    }

    while (m--){
        int b;
        cin >> b;
        cout << solve(b) << " ";
    }
    cout << el;

    return 0;
}