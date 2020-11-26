#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string ret;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string temp;
    while (getline(cin, temp)){
        for (auto x : temp){
            if (x == ' ' || x == '\n') continue;
            ret.pb(x);
        }
    }
    cout << ret << el;

    return 0;
}