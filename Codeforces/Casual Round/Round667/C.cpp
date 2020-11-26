#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 100;

int q;
int n, x, y;

void solve(){
    cin >> n >> x >> y;
    int sel = y - x;

    int pi = -1;
    for (int i=1;i<=sel;i++){
        if (sel % i == 0){
            if (sel / i + 1 <= n){
                pi = i;
                break;
            }
        }
    }
    assert(pi != -1);
    deque<int> ans;
    for (int i=x;i<=y;i+=pi){
        ans.pb(i);
    }
    while (ans.size() < n){
        if (ans.front() - pi >= 1){
            ans.push_front(ans.front() - pi);
        } else{
            ans.pb(ans.back() + pi);
        }
    }
    for (int i=1;i<=n;i++){
        cout << ans.front() << " ";
        ans.pop_front();
    }
    cout << el;
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