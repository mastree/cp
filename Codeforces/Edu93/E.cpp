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
const ll INF = 1e18;
const ll MX = 1e9;

int q;

ll tot;
set<ll> mx;
set<ll> setdah[2];

ll lastmx(int id){
    ll l = 0, r = MX;
    while (l < r){
        ll m = (l + r + 1) / 2;
        if (setdah[id].lower_bound(m) == setdah[id].end()){
            r = m - 1;
            continue;
        }
        auto temp = *setdah[id].lower_bound(m);
        if (mx.find(temp) != mx.end()){
            r = m - 1;
        } else{
            l = m;
        }
    }
    return l;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    mx.insert(INF);
    setdah[0].insert(0);
    setdah[1].insert(0);
    while (q--){
        int tipe;
        ll d;
        cin >> tipe >> d;
        if (tipe == 0){
            if (d > 0){
                setdah[tipe].insert(d);
                mx.insert(d);
                tot += d + d;
                while (mx.size() > setdah[1].size()){
                    auto cur = *mx.begin();
                    mx.erase(cur);
                    tot -= cur;
                }
            } else{
                d = -d;
                setdah[tipe].erase(d);
                tot -= d;
                if (mx.find(d) != mx.end()) {
                    mx.erase(d);
                    tot -= d;

                    ll last0 = lastmx(0);
                    ll last1 = lastmx(1);
                    if (last0 > last1){
                        mx.insert(last0);
                        tot += last0;
                    } else{
                        mx.insert(last1);
                        tot += last1;
                    }
                }
            }
        } else{
            if (d > 0){
                ll last0 = lastmx(0);
                ll last1 = lastmx(1);
                last1 = max(last1, d);
                if (last0 > last1){
                    mx.insert(last0);
                    tot += last0;
                } else{
                    mx.insert(last1);
                    tot += last1;
                }
                setdah[tipe].insert(d);
                tot += d;
            } else{
                d = -d;
                setdah[tipe].erase(d);
                tot -= d;
                if (mx.find(d) != mx.end()){
                    mx.erase(d);
                    tot -= d;
                } else{
                    auto temp = *mx.begin();
                    mx.erase(temp);
                    tot -= temp;
                }
            }
        }
        // cout << el;
        // for (int i=0;i<2;i++){
        //     for (auto x : setdah[i]) cout << x << " "; cout << el;
        // }
        // for (auto x : mx) cout << x << " "; cout << el;
        ll last0 = lastmx(0);
        ll last1 = lastmx(1);
        if (last1 == 0 && setdah[1].size() > 1){
            cout << tot - *setdah[1].upper_bound(last1) + last0 << el;
        } else{
            cout << tot << el;
        }
    }

    return 0;
}