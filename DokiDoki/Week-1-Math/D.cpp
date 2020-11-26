#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
vector<int> prime;
vector<int> ans;

bool is_prime(int x){
    for (int i=2;i * i<=x;i++){
        if (x % i == 0) return 0;
    }
    return x != 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=2;i<=n;i++){
        if (is_prime(i)) prime.pb(i);
    }
    for (auto x : prime){
        int cur = 1;
        while (cur * x <= n){
            cur *= x;
            ans.pb(cur);
        }
    }
    cout << ans.size() << el;
    for (auto x : ans) cout << x << " ";
    cout << el;

    return 0;
}