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

bool is_subseq(string& a, string& b){ // a subseq of b
    int id = 0;
    int n = a.size();
    for (auto& x : b){
        if (x == a[id]) id++;
        if (id == n) return true;
    }
    return false;
}

void solve(){
    string a, b;
    cin >> a >> b;
    if (a.size() < b.size()) swap(a, b);
    if (is_subseq(b, a)){
        cout << "BOLEH" << el;
    } else{
        cout << "JANGAN" << el;
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