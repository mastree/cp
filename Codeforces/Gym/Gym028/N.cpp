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
int slot[4];
int ar[7];

void solve(){
    for (int i=1;i<=3;i++){
        cin >> slot[i];
    }
    for (int i=1;i<=5;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=3;i++){
        slot[i] -= ar[i];
        if (slot[i] < 0){
            cout << "NO" << el;
            return;
        }
    }
    int temp1 = min(slot[1], ar[4]);
    int temp2 = min(slot[2], ar[5]);
    ar[4] -= temp1;
    ar[5] -= temp2;
    if (ar[4] + ar[5] <= slot[3]){
        cout << "YES" << el;
        return;
    }
    cout << "NO" << el;
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