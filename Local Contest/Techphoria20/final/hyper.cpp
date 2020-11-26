#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 60;

int q;
int n, m;
string s[N];

bool is_valid(int i, int j){
    return 0 <= i && i <= n && 0 <= j && j <= m;
}

void solve(){
    cin >> n, m;
    for (int i=0;i<n;i++){
        cin >> s[i];
    }
    for ()
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}