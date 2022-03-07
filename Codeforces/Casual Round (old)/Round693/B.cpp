#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int q;
int n;
int cnt[3];

void solve(){
    cin >> n;
    cnt[1] = cnt[2] = 0;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    if (cnt[2] % 2 == 0){
        if (cnt[1] % 2 == 0){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    } else{
        if (cnt[1] >= 2 && cnt[1] % 2 == 0){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
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