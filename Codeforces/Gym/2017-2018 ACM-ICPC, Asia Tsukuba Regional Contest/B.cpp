#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 16;

int n;
vector<pii> pts;
vector<bool> taken;
unordered_map<pii, int> grad;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        pts.emplace_back(a, b);
    }


    return 0;
}