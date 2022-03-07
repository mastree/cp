#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 20;

int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> mat[i][j];
        }
    }
    for (int j=0;j<n;j++){
        int ans = 0;
        int last = -1;
        for (int i=0;i<n;i++){
            if (mat[i][j] > last){
                last = mat[i][j];
                ans++;
            }
        }
        cout << ans << ' ';
    }
    cout << el;
    for (int i=0;i<n;i++){
        int ans = 0;
        int last = -1;
        for (int j=0;j<n;j++){
            if (mat[i][j] > last){
                last = mat[i][j];
                ans++;
            }
        }
        cout << ans << el;
    }

    return 0;
}