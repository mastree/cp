#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll INF = 1e18;

ll c, n, p, w

ll slot;
deque<ll> deq;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> n >> p >> w;
    slot = n;

    ll tot = 0;
    while (slot && w){
        slot--;
        ll kur = min(w, p);
        w -= kur;
        deq.push_back(kur);
        tot += kur;
    }
    ll ans = 0;
    while (tot >= c){

    }

    return 0;
}