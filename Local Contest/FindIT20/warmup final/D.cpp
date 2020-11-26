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
pair<ll, ll> ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
    }
    sort(ar + 1, ar + n + 1);
    ll tot = 0, last = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (int i=1;i<=n;i++){
        while (!pq.empty() && last < ar[i].fi){
            auto tp = pq.top();
            pq.pop();
            last += tp.fi;
            tot += last - tp.se;
        }
        last = max(last, ar[i].fi);
        pq.push(mp(ar[i].se, ar[i].fi));
    }
    while (!pq.empty()){
        auto tp = pq.top();
        pq.pop();
        last += tp.fi;
        tot += last - tp.se;
    }
    cout << tot / ((ll)n) << el << el;

    return 0;
}