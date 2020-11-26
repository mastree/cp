#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10, M = 60;

int n;
ll ar[N];
ll tot;

ll calc(ll a, ll b){
    bool bebas = 0;
    ll ret = 0;
    for (int i=M;i>=0;i--){
        ll bit = (1LL << i);
        if (a & bit){
            if (b & bit){
                bebas = 1;
                ret += bit;
            } else{
                ret += bit;
            }
        } else{
            if (bebas){
                ret += bit;
            } else{
                if (b & bit) ret += bit;
            }
        }
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        tot ^= ar[i];
    }
    ll ans = 0;
    for (int i=1;i<=n;i++){
        ans = max(ans, calc((tot ^ ar[i]), ar[i]));
    }
    cout << ans << el;

    return 0;
}