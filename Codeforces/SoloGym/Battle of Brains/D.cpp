#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll MX = 1e9 + 10;

int q;
ll n;

void solve(){
    cin >> n;
    if (n <= 9){
        cout << n << el;
        return;
    }
    cout << n;
    string temp = to_string(n);
    temp.pop_back();
    reverse(temp.begin(), temp.end());
    cout << temp << el;
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