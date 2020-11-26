#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10, M = 3;
const int INF = 1e9;

int n;
int ar[N];
int cnt[M];
vector<int> perm{0, 1, 2};
void next_perm(){
    perm = {1, 0, 2};
}
int solve(){
    int pos[M];
    for (int i=0;i<M;i++){
        pos[i] = cnt[perm[i]];
        if (i) pos[i] += pos[i - 1];
    }
    int isi[N];
    for (int i=0;i<n;i++){
        if (i < pos[0] && cnt[perm[0]]){
            isi[i] = perm[0];
        } else if (i < pos[1] && cnt[perm[1]]){
            isi[i] = perm[1];
        } else{
            isi[i] = perm[2];
        }
    }
    int cur = 0;
    for (int i=0;i<n;i++){
        if (ar[i] != isi[i]){
            cur++;
        }
    }
    int ret = INF;
    ret = min(ret, cur);
    for (int i=1;i<n;i++){
        int awal[3] = {0, pos[0], pos[1]};
        for (auto& x : awal){
            x = (x + i) % n;
        }
        for (int j=0;j<M;j++){
            if (!cnt[perm[j]]) continue;
            int id = (awal[j] - 1 + n) % n;
            int id2 = (awal[j] - i + n) % n;
            if (ar[id] != isi[id2]){
                cur--;
            }
            int id3 = (id2 - 1 + n) % n;
            if (ar[id] != isi[id3]){
                cur++;
            }
        }
        ret = min(ret, cur);
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    {
        string s;
        cin >> s;
        for (int i=0;i<n;i++){
            ar[i] = s[i] - 'A';
            cnt[ar[i]]++;
        }
    }
    int ans = INF;
    ans = min(ans, solve());
    next_perm();
    ans = min(ans, solve());
    cout << ans << el;

    return 0;
}