#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int sum = 0;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        sum += a;
        cout << "angka ke-" << i << " = " << a << el;
    }
    cout << "sum: " << sum << el;

    return 0;
}