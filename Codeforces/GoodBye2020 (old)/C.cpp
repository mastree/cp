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

int finddif(set<int>& setdah){
    for (int i=0;i<26;i++){
        if (setdah.find(i) != setdah.end()) continue;
        return i;
    }
    return 26;
}
bool is_valid(int x){
    return 1 <= x && x <= n;
}

void solve(){
    {
        string s;
        cin >> s;
        n = s.size();
        for (int i=1;i<=n;i++){
            ar[i] = s[i - 1] - 'a';
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (i < n){
            if (ar[i] == ar[i + 1]){
                set<int> temp;
                for (int j=i - 1;j<=i + 3;j++){
                    if (is_valid(j) && j != i + 1){
                        temp.insert(ar[j]);
                    }
                }
                ar[i + 1] = finddif(temp);
                ans++;
            }
        } 
        if (i < n - 1){
            if (ar[i] == ar[i + 2]){
                set<int> temp;
                for (int j=i;j<=i + 4;j++){
                    if (is_valid(j) && j != i + 2){
                        temp.insert(ar[j]);
                    }
                }
                ar[i + 2] = finddif(temp);
                ans++;
            }
        }
    }
    cout << ans << el;
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