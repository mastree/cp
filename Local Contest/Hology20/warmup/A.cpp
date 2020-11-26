#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string vocalup = "AUEO";
string vocallow = "aueo";

string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    getline(cin, s);
    for (auto& x : s){
        for (auto y : vocalup){
            if (x == y){
                x = 'I';
            }
        }
        for (auto y : vocallow){
            if (x == y){
                x = 'i';
            }
        }
    }
    cout << s << el;

    return 0;
}