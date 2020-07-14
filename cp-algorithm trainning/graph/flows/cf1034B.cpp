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

ll n, m;

ll solve(ll a, ll b){
    if (a < b) swap(a, b);
    // a > b
    if (a < 4){
        if (a == 3 && b == 3) return 8;
        if (a == 3) return 2 * b;
        return 0;
    }
    ll ret = 0;
    ll aper = a / 4LL;
    a %= 4LL;
    ret += 4LL * aper * b;
    return ret + solve(a, b);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cout << solve(n, m) << el;

    return 0;
}