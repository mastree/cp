#include <bits/stdc++.h>

#define el '\n'

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

int q;
int n, k;

void solve(){
    cin >> n >> k;
    vector<int> vec(n);
    for (int i=0;i<n;i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), greater<int>());
    int tot = 0;
    int i = -1;
    if (k){
        for (i=0;i<n;i++){
            tot += vec[i];
            if (tot >= k) break;
        }
    }
    if (tot >= k) cout << i + 1 << el;
    else cout << -1 << el;
}

int main(){
    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}