#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;
vector<pair<string, int>> vec;

bool comp(const pair<string, int>& a, const pair<string, int>& b){
    string sa = a.fi;
    string sb = b.fi;
    int len = sa.size();
    for (int i=0;i<len;i++){
        if (i & 1 ^ 1){
            if (sa[i] != sb[i]) return sa[i] < sb[i];
        } else{
            if (sa[i] != sb[i]) return sa[i] > sb[i];
        }
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        vec.pb(mp(s, i));
    }
    sort(vec.begin(), vec.end(), &comp);
    for (auto& x : vec){
        cout << x.se << ' ';
    }
    cout << el;

    return 0;
}