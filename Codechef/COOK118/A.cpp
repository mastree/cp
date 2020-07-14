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

const int N = 1e3 + 10;

int n, q;
// int ar[N];
vector<int> v[N];
int cnt[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=0;i<N;i++){
            cnt[i] = 0;
            v[i].clear();
        }
        for (int i=1;i<=n;i++){
            // cin >> ar[i];
            int a;
            cin >> a;
            v[a].pb(i);
        }
        bool bisa = 1;
        for (int i=1;i<N;i++){
            int len = v[i].size();
            if (len == 0) continue;
            if (++cnt[len] != 1){
                bisa = 0;
                break;
            }
            for (int j=1;j<len;j++){
                if (v[i][j] - v[i][j - 1] > 1){
                    bisa = 0;
                    break;
                }
            }
            if (bisa == 0) break;
        }
        if (bisa){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}