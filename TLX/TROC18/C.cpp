#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;

int n;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1);
    vector<int> vec[2];
    for (int i=1;i<=n;i++){
        vec[i & 1 ^ 1].pb(ar[i]);
    }
    while (!vec[1].empty()){
        vec[0].pb(vec[1].back());
        vec[1].pop_back();
    }
    for (auto& x : vec[0]){
        cout << x << " ";
    }
    cout << el;

    return 0;
}