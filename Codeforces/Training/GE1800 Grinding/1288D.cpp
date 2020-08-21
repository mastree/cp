#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 3e5 + 10, M = 10;
const int INF = 1e9 + 2;

int n, m;
int ar[N][M];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j=0;j<m;j++){
            cin >> ar[i][j];
        }
    }

    int low = 0, high = INF;
    int len = (1 << m);
    pii ans = mp(1, 1);
    while (low < high){
        int mid = (low + high + 1) / 2;
        bool bisa = 0;
        bool ada[len + 2];
        int idx[len + 2];
        fill(ada, ada + len + 2, 0);
        for (int i=1;i<=n;i++){
            int bset = 0;
            for (int j=0;j<m;j++){
                if (ar[i][j] >= mid){
                    bset += (1 << j);
                }
            }
            ada[bset] = 1;
            idx[bset] = i;
        }
        for (int i=0;i<len;i++){
            for (int j=i;j<len;j++){
                if (ada[i] && ada[j]){
                    if ((i | j) == (1 << m) - 1){
                        bisa = 1;
                        ans = mp(idx[i], idx[j]);
                        break;
                    }
                }
            }
            if (bisa) break;
        }
        if (bisa){
            low = mid;
        } else{
            high = mid - 1;
        }
    }
    cout << ans.fi << " " << ans.se << el;

    return 0;
}