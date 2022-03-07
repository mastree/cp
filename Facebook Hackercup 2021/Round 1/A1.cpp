#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 8e5 + 10;

int q;
int n;
string s;

void solve(){
    cin >> n;
    cin >> s;
    vector<char> vec;
    vec.pb('F');
    for (auto& x : s){
        if (x == 'F') continue;
        if (vec.back() == x) continue;
        vec.pb(x);
    }
    cout << max((int) vec.size() - 2, 0) << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}