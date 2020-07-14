#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e4 + 10;

int n, t;
int cost[N], time[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("journey.in", "r", stdin);
    freopen("journey.out", "w", stdout);

    cin >> n >> t;
    for (int i=1;i<n;i++){ // cost for card of range i
        cin >> cost[i];
    }
    for (int i=n - 2;i>=1;i++){
        cost[i] = min(cost[i], cost[i + 1]);
    }
    for (int i=2;i<n;i++){ // time to reenter station i
        cin >> time[i];
    }
    t -= n - 1;


    return 0;
}