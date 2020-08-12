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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        ll a, b;
        cin >> a >> b;
        if (a * 2 <= b){
            cout << a << " " << a * 2 << el;
        } else{
            cout << -1 << " " << -1 << el;
        }
    }

    return 0;
}