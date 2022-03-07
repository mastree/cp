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

int q;
int n;
ll ar[N];

void solve(){
    vector<ll> od, ev;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        if (ar[i] & 1) od.pb(ar[i]);
        else ev.pb(ar[i]);
    }
    sort(od.begin(), od.end());
    sort(ev.begin(), ev.end());
    ll a = 0, b = 0;
    int turn = 0;
    while (od.size() || ev.size()){
        turn++;
        if (turn & 1){
            if (ev.empty() || (od.size() && od.back() > ev.back())) od.pop_back();
            else{
                a += ev.back();
                ev.pop_back();
            }
        } else{
            if (od.empty() || (ev.size() && ev.back() > od.back())) ev.pop_back();
            else{
                b += od.back();
                od.pop_back();
            }
        }
    }
    if (a > b){
        cout << "Alice" << el;
    } else if (b > a){
        cout << "Bob" << el;
    } else{
        cout << "Tie" << el;
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