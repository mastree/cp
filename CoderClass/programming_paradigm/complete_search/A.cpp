#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, q;
map<string, int> cek;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        cek[s] = i;
    }
    while (q--){
        string s;
        cin >> s;
        if (cek.count(s)){
            cout << cek[s] << el;
        } else{
            cout << -1 << el;
        }
    }

    return 0;
}