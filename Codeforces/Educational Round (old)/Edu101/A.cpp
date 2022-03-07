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
void solve(){
    string s;
    cin >> s;
    int len = s.size();
    if (len & 1){
        cout << "NO" << el;
        return;
    }
    int a = -1, b = -1;
    for (int i=0;i<len;i++){
        if (s[i] == '(') a = i;
        else if (s[i] == ')') b = i;
    }
    if (b == 0 || a == len - 1){
        cout << "NO" << el;
    } else{
        cout << "YES" << el;
    }
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