#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int q;
void solve(){
    int d;
    ll n;
    cin >> d >> n;
    if (n > (1LL << (d + 1)) - 1){
        cout << "NO" << el;
        return;
    }
    if (n == 0){
        cout << "YES 0" << el;
        return;
    }
    ll cur = 0;
    int jump = 0;
    bool sisa = 0;
    for (int i=d;i>=0;i--){
        if (cur < 0) break;
        jump++;
        ll bit = (1LL << i);
        if (sisa){
            if (n & bit){
                cur -= bit;
                sisa = 0;
            } else{
                cur -= bit;
            }
        } else{
            if (n & bit){
                cur += bit;
            } else{
                cur += bit;
                sisa = 1;
            }
        }
        if (cur == n){
            cout << "YES " << jump << el;
            return;
        }
    }
    cout << "NO" << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}