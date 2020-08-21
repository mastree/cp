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
string s;
int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> s;
        cin >> n;
        if (s[0] == 'p') n = (n + 1) % 100;
        else n = (n - 1 + 100) % 100;
        cout << n << el;
    }

    return 0;
}