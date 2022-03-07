#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string a, b;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    getline(cin, a);
    getline(cin, b);
    map<char, int> cnt;
    for (auto& x : b){
        if (x == ' ') continue;
        cnt[x]++;
    }
    for (auto& x : a){
        if (x == ' ') continue;
        cnt[x]--;
    }
    bool ok = 1;
    for (auto& x : cnt){
        if (x.se > 0) ok = 0;
    }
    if (ok) cout << "Bisa" << el;
    else cout << "Tidak Bisa" << el;

    return 0;
}