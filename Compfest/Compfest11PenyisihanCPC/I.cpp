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

int n, m;
pll juri[N];
set <pair<pll, int>> kue; // kue, id

int ans[N];
pll ja, jb;
vector <int> ja_id, jb_id;

pll norm(pll a){
    ll gg = __gcd(abs(a.fi), abs(b.fi));
}

void make_jarak(){
    auto it = kue.begin();

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for (int i=1;i<=m;i++){
        cin >> juri[i].fi >> juri[i].se;
    }
    for (int i=1;i<=n;i++){
        pair<pll, int> temp;
        cin >> temp.fi.fi >> temp.fi.se;
        temp.se = i;
        if (kue.empty()){
            kue.insert(temp);
            continue;
        }
        auto itb = kue.lower_bound(temp));
        auto ita = itb;
        if (ita != kue.begin()){
            ita--; 
        }
        if (itb != kue.end() && temp.fi.se < (*itb).fi.se) continue;
        vector <pair<pll, int>> pus;
        while ((*ita).fi.se < temp.fi.se){
            pus.pb((*ita));
            if (ita == kue.begin()) break;
            ita--;
        }
        for (auto x : pus) kue.erase();
        kue.insert(temp);
    }
    make_jarak();

    return 0;
}