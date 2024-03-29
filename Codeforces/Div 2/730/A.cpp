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
ll a, b;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> a >> b;
        if (a < b) swap(a, b);
        if (a == b){
            cout << "0 0" << el;
            continue;
        }
        ll dif = (a - b);
        ll temp = a % dif;
        cout << dif << " " << min(temp, dif - temp) << el;
    }

    return 0;
}