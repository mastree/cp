#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using psi = pair<string, int>;

const int N = 1e5 + 10;

int n;
vector<psi> vec;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        string s;
        int a;
        cin >> s >> a;
        vec.pb(mp(s, a));
    }
    sort(vec.begin(), vec.end(), [&](const psi& a, const psi& b)->bool{
        if (a.fi[0] != b.fi[0]) return a.fi[0] < b.fi[0];
        return a.se < b.se;
    });
    for (auto& x : vec){
        cout << x.fi << el;
    }

    return 0;
}