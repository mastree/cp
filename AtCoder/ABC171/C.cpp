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

ll n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<char> v;
    // cout << 26 * 26 << el;
    while (n > 26){
        ll dig = (n - 1LL) % 26LL;
        v.pb(char((int)dig + 'a'));
        n = (n - 1LL) / 26LL;
    }
    ll dig = (n - 1LL) % 26LL;
    v.pb(char((int)dig + 'a'));
    reverse(v.begin(), v.end());
    for (auto x : v) cout << x;
    cout << el;

    return 0;
}