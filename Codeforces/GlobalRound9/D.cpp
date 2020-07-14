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

int q;
int n;
int ar[N];

int getmex(int l, int r){
    set<int> setdah;
    for (int i=l;i<=r;i++) setdah.insert(ar[i]);
    int ret = 0;
    for (auto x : setdah){
        if (x == ret) ret++;
        else return ret;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=0;i<n;i++){
            cin >> ar[i];
        }
        vector<int> ans;
        for (int i=0;i<n;i++){
            if (ar[i] == i) continue;
            if (i == n - 1 && ar[i] > n - 1) break;

            while (1){
                int mex = getmex(0, n - 1);
                if (mex == i){
                    ans.pb(i);
                    ar[i] = mex;
                    break;
                }
                if (mex > n - 1) mex = n - 1;
                if (ar[mex] != mex){
                    ans.pb(mex);
                    ar[mex] = mex;
                    continue;
                }
                for (int j=i + 1;j<n;j++){
                    if (ar[j] == i){
                        ans.pb(j);
                        ar[j] = mex;
                        break;
                    }
                }
            }
        }
        cout << ans.size() << el;
        for (auto x : ans) cout << x + 1 << " "; cout << el;
    }

    return 0;
}