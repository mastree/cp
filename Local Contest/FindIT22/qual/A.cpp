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

int solve(int n, const vector<int>& vec) {
    int ret = 0;
    for (int i = 1; i < n; i++) {
        if (vec[i] > vec[i - 1]) ret++;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto& x : vec) {
        cin >> x;
    }

    cout << solve(n, vec) << '\n';

    return 0;
}