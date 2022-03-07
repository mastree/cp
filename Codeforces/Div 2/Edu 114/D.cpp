#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using plvi = pair<ll, vector<int>>;

const int N = 11;
const int M = 1e5 + 10;

int n;
vector<ll> vec[N];

int m;
map<vector<int>, bool> ban;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        int len;
        cin >> len;
        vec[i].resize(len);
        for (int j=0;j<len;j++){
            cin >> vec[i][j];
        }
    }
    cin >> m;
    for (int i=1;i<=m;i++){
        vector<int> temp;
        for (int j=0;j<n;j++){
            int a;
            cin >> a;
            temp.pb(a - 1);
        }
        ban[temp] = 1;
    }
    set<pair<ll, vector<int>>> setdah;
    {
        pair<ll, vector<int>> ftake;
        for (int i=0;i<n;i++){
            ftake.se.pb((int)vec[i].size() - 1);
            ftake.fi += vec[i].back();
        }
        setdah.insert(ftake);
    }

    while (!setdah.empty()){
        auto cur = *setdah.rbegin();
        setdah.erase(cur);
        if (!ban[cur.se]){
            for (auto& x : cur.se){
                cout << x + 1 << ' ';
            }
            cout << el;
            return 0;
        }
        for (int i=0;i<n;i++){
            if (cur.se[i]){
                plvi nx = cur;
                nx.fi -= vec[i][nx.se[i]];
                nx.se[i]--;
                nx.fi += vec[i][nx.se[i]];
                setdah.insert(nx);
            }
        }
    }
    for (int i=0;i<n;i++){
        cout << vec[i].size() << ' ';
    }
    cout << el;

    return 0;
}