#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int q;
int n;

void solve(){
    cin >> n;
    vector<ll> pos, neg;

    ll kon = 1;
    for (int i=1;i<=n;i++){
        ll a;
        cin >> a;
        if (a >= 0){
            pos.pb(a);
        } else{
            neg.pb(-a);
        }
        kon *= a;
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    if (pos.empty()){
        ll ans = 1;
        for (int i=0;i<5;i++){
            ans *= neg[i];
        }
        cout << -ans << el;
        return;
    }
    ll ans = pos.back();
    pos.pop_back();
    vector<ll> can;
    while (pos.size() >= 2){
        ll temp = pos.back();
        pos.pop_back();
        temp *= pos.back();
        pos.pop_back();
        can.pb(temp);
    }
    while (neg.size() >= 2){
        ll temp = neg.back();
        neg.pop_back();
        temp *= neg.back();
        neg.pop_back();
        can.pb(temp);
    }
    sort(can.begin(), can.end(), greater<ll>());
    if (can.size() >= 2){
        ans *= can[0] * can[1];
        cout << ans << el;
    } else{
        cout << kon << el;
    }
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