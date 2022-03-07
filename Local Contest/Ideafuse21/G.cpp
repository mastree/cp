#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const vector<string> types = {"FIRE", "WATER", "GRASS", "GROUND", "FLYING"};
const vector<string> anst = {"not effective", "not very effective", "effective", "super effective"};
const vector<vector<int>> table {
    {1, 1, 3, 2, 2},
    {3, 1, 1, 3, 2},
    {1, 3, 1, 3, 1},
    {3, 2, 1, 2, 0},
    {2, 2, 3, 2, 2}
};

int getid(const string& s){
    int ret = 0;
    for (auto& x : types){
        if (x == s) return ret;
        ret++;
    }
    return ret;
}
int q;

void solve(){
    string sa, sb;
    cin >> sa >> sb;
    int a = getid(sa);
    int b = getid(sb);
    cout << anst[table[a][b]] << el;
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