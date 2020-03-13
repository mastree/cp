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

const int N = 2e5 + 7;
int ar[N], n;
int le[19][N], ri[19][N];
priority_queue <pii> pq;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        le[0][i] = ar[i];
        ri[0][i] = ar[i];
    }
    for (int i=1;i<19;i++){
        for (int j=1;j<=n;j++){
            int l;
            l = j - (1 << i) + 1;
            if (l <= 0){
                continue;
            }
            le[i][j] = min(le[i-1][j], le[i-1][j - (1 << (i-1))]);
        }
    }

    for (int i=1;i<19;i++){
        for (int j=1;j<=n;j++){
            int r;
            r = j + (1 << i) - 1;
            if (r > n){
                continue;
            }
            ri[i][j] = min(ri[i-1][j], ri[i-1][j + (1 << (i-1))]);
        }
    }

    for (int i=1;i<=n;i++){
        int res = 0, id, best;
        best = id = i;
        for (int j=18;j>=0;j--){
            if (ri[j][id] >= ar[i]){
                id += (1 << j);
                best = id-1;
            }
        }
        res += best - i + 1;
        // cout << best << " ";
        best = id = i;
        for (int j=18;j>=0;j--){
            if (le[j][id] >= ar[i]){
                id -= (1 << j);
                best = id+1;
            }
        } 
        res += i - best;
        pq.push(mp(ar[i], res));
    }
    // cout << el;
    for (int i=1;i<=n;i++){
        while (pq.top().se < i){
            pq.pop();
        }
        cout << pq.top().fi << " ";
    }
    cout << el;

    return 0;
}