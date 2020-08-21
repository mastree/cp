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

int n;
int ar[N];
int ans;
ll tot = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        tot += (ll)ar[i];
    }
    sort(ar + 1, ar + n + 1);
    tot -= (ll)ar[n];
    if (((ll)ar[n]) > tot){
        ans = ar[n] - (int)tot;
    } else{
        tot += (ll)ar[n];
        ans = (int)(tot & 1);
    }
    cout << ans << el;

    return 0;
}