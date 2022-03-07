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
const int INF = 1e9;

int n;
int ar[N][N];

vector<int> di = {0, 0, -1, 1};
vector<int> dj = {-1, 1, 0, 0};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<=n + 1;i++){
        fill(ar[i], ar[i] + n + 2, INF);
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> ar[i][j];
        }
    }
    pii cur = {(n + 1) / 2, (n + 1) / 2};
    int awal = ar[cur.fi][cur.se];
    while (1){
        pii mn = {INF, -1};
        for (int i=0;i<4;i++){
            mn = min(mn, mp(ar[cur.fi + di[i]][cur.se + dj[i]], i));
        }
        if (mn.se == -1 || mn.fi >= ar[cur.fi][cur.se]) break;
        cur = mp(cur.fi + di[mn.se], cur.se + dj[mn.se]);
    }
    if ((cur.fi == 1 || cur.fi == n) || (cur.se == 1 || cur.se == n)){
        cout << "bahaya ";
    } else{
        cout << "aman ";
    }
    cout << awal - ar[cur.fi][cur.se] << el;

    return 0;
}