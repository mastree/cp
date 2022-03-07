#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    for (auto& x : s){
        if (x == '0'){
            cout << "YES" << el;
            return 0;
        }
    }
    cout << "NO" << el;

    return 0;
}