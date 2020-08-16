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
int ar[N];

void solve(){
    cin >> n;
    set<int> setdah;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        setdah.insert(ar[i]);
    }
    if (setdah.size() == 1){
        cout << n << el;
        return;
    }
    cout << 1 << el;
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