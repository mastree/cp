#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int n;
int ar[N];
set<pii> setdah;
vector<int> ans[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        setdah.insert(mp(0, -i));
    }
    for (int i=1;i<=n;i++){
        auto it = setdah.lower_bound(mp(ar[i] - 1, 0));
        it--;
        pii temp = *it;
        setdah.erase(temp);
        ans[-temp.se].pb(ar[i]);
        setdah.insert(mp(ar[i], temp.se));
    }
    for (int i=1;i<=n;i++){
        if (ans[i].size()){
            for (auto x : ans[i]){
                cout << x << " ";
            }
            cout << el;
        }
    }

    return 0;
}