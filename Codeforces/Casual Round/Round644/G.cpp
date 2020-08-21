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

const int N = 100;

int q, n, m, a, b;
int ar[N][N];

bool isi[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m >> a >> b;
        if (n * a != m * b){
            cout << "NO" << el;
            continue;
        }
        priority_queue<pii> pq;
        for (int i=1;i<=n;i++){
            fill(isi[i], isi[i] + m + 2, 0);
        }
        for (int j=1;j<=m;j++) pq.push(mp(b, j));
        for (int i=1;i<=n;i++){
            vector<pii> v;
            for (int j=0;j<a;j++){
                auto temp = pq.top();
                pq.pop();
                isi[i][temp.se] = 1;
                if (temp.fi - 1) v.pb(mp(temp.fi - 1, temp.se));
            }
            for (auto x : v) pq.push(x);
        }
        cout << "YES" << el;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cout << isi[i][j];
            }
            cout << el;
        }
    }

    return 0;
}