#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110, MX = 101;

int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        int dum;
        cin >> dum;
    }
    string ans;
    ans.pb('G');
    for (int i=0;i<50;i++){
        ans.pb('R');
        ans.pb('G');
    }
    assert(ans.size() == 101);
    cout << ans.size() << el;
    cout << ans << el;

    return 0;
}