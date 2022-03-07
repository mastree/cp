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
int n, tot;

void solve(){
    tot = 0;
    cin >> n;
    for (int i=0;i<4;i++){
        int a;
        cin >> a;
        tot += a;
    }
    if (n + 1 <= tot * 2){
        cout << "Yes" << el;
    } else{
        cout << "No" << el;
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