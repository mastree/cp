#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e4 + 10, X = 110;

int w, s;
int x, y;
int ar[N][X];
int rem[X];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> s;
    cin >> x >> y;
    for (int i=1;i<=w;i++){
        for (int j=1;j<=x;j++){
            cin >> ar[i][j];
        }
    }
    for (int i=1;i<=s;i++){
        for (int j=1;j<=x;j++){
            int a;
            cin >> a;
            rem[j] = max(rem[j], a);    
        }
    }
    for (int i=1;i<=w;i++){
        for (int j=1;j<=x;j++){
            int cur = min(y - rem[j], ar[i][j]);
            cout << cur << " ";
        }
        cout << el;
    }

    return 0;
}