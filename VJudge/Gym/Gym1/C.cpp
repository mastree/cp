#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 26;

string player = "LMW";

int n;
ll ar[N][3];
ll tot[3];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<3;j++){
            cin >> ar[i][j];
            tot[j] += ar[i][j];
            ar[i][j] = -ar[i][j];
        }
    }
    

    return 0;
}