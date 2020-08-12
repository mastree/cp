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

ll n, a, b;
ll lcm;

ll hitung(ll x){
    return x / a + x / b - x / lcm;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;
    lcm = a * b / __gcd(a, b);
    ll low = 1, high = INF;
    ll best = -1;
    while (low <= high){
        ll mid = (low + high) / 2;
        if (hitung(mid) >= n){
            best = mid;
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }
    cout << best << el;

    return 0;
}