#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int q;
int n;
int ar[N];

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    set<int> setdah;
    sort(ar + 1, ar + n + 1);
    for (int i=1;i<=n;i++){
        if (setdah.find(ar[i]) != setdah.end()){
            setdah.insert(ar[i] + 1);
        } else{
            setdah.insert(ar[i]);
        }
    }
    cout << setdah.size() << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}