#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Piece{
    ll w;
    int a, b, c;
    Piece() {}
    Piece(ll w, int a, int b, int c) : w(w), a(a), b(b), c(c) {}
};

const ll MX = 1e18;

ll a, b, c;
ll kpk;
ll butuh[3];

ll get_lcm(ll a, ll b){
    return a * b / __gcd(a, b);
}

vector<ll> sisa[3];
int id[3];
vector<Piece> ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;
    kpk = get_lcm(get_lcm(a, b), c);
    butuh[0] = kpk / a;
    butuh[1] = kpk / b;
    butuh[2] = kpk / c;
    for (int i=0;i<(int)a;i++){
        sisa[0].pb(butuh[0]);
    }
    for (int i=0;i<(int)b;i++){
        sisa[1].pb(butuh[1]);
    }
    for (int i=0;i<(int)c;i++){
        sisa[2].pb(butuh[2]);
    }
    id[0] = (int)a;
    id[1] = (int)b;
    id[2] = (int)c;
    while (id[0] && id[1] && id[2]){
        int mn = 0;
        for (int i=0;i<3;i++){
            if (sisa[mn].back() > sisa[i].back()){
                mn = i;
            }
        }
        ll w = sisa[mn].back();
        ans.emplace_back(w, id[0], id[1], id[2]);
        for (int i=0;i<3;i++){
            sisa[i].back() -= w;
            if (sisa[i].back() <= 0){
                sisa[i].pop_back();
                id[i]--;
            }
        }
    }
    cout << ans.size() << el;
    for (auto x : ans){
        cout << x.w << " " << x.a << " " << x.b << " " << x.c << el;
    }

    return 0;
}