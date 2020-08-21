#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e3 + 10;

int q;
int n;
string s;

void solve(){
    cin >> s;
    n = s.length();
    int cnt = 0;
    for (int i=1;i<n;i++){
        cnt += s[i] == 'B';
    }
    if (cnt == n - 1){
        cout << "N\n";
        return;
    }
    n--;
    if (cnt >= (n + 1) / 2){
        cout << "Y\n";
    } else{
        cout << "N\n";
    }
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