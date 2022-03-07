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

typedef pair<ll, ll> pll;

const int N = 1e5 + 10;
const ll BORD = 225LL * ((ll)1e10);
const ll ACC = 1e6;
const pll ORI = mp(0LL, 0LL);

int n;
pll ar[N];

ll jarak(pll a, pll b){
    ll delx = a.fi - b.fi;
    ll dely = a.se - b.se;
    return delx * delx + dely + dely;
}
pll movea(pll a, pll b){
    return mp(a.fi + b.fi, a.se + b.se); 
}
pll moveb(pll a, pll b){
    return mp(a.fi - b.fi, a.se - b.se); 
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
    }
    pll cur = ORI;
    for (int i=1;i<=n;i++){
        pll ncur1, ncur2;
        ncur1 = movea(cur, ar[i]);
        ncur2 = moveb(cur, ar[i]);
        if (jarak(ncur1, ORI) > BORD){
            cout << -1 << " ";
            cur = ncur2;
            continue;
        }
        if (jarak(ncur2, ORI) > BORD){
            cout << 1 << " ";
            cur = ncur1;
            continue;
        }
        if (ncur1.fi <= ACC && ncur1.se <= ACC){
            cout << 1 << " ";
            cur = ncur1;
        } else if (ncur2.fi <= ACC && ncur2.se <= ACC){
            cout << -1 << " ";
            cur = ncur2;
        } else if (jarak(ncur1, ORI) <= jarak(ncur2, ORI)){
            cout << 1 << " ";
            cur = ncur1;
        } else{
            cout << -1 << " ";
            cur = ncur2;
        }
    }
    cout << el;

    return 0;
}