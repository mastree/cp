#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e3 + 10;
const int INF = 1e9 + 10;

int n;
int p;
int ar[N];
int cnt[2 * N];
bool gud[N];

bool bisa(int mid){
    for (int i=1;i<=n;i++){
        if (ar[i] <= mid) mid++;
        else return 0;
    }
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;
    int mxm = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        mxm = max(mxm, ar[i]);
    }
    sort(ar + 1, ar + n + 1);
    int low = 1, high = mxm;
    while (low < high){
        int mid = (low + high) / 2;
        if (bisa(mid)){
            high = mid;
        } else{
            low = mid + 1;
        }
    } 
    for (int i=1;i<=n;i++){
        ar[i] = max(1, ar[i] - low + 1);
        cnt[ar[i]]++;
    }
    for (int i=2;i<2 * N;i++){
        cnt[i] += cnt[i - 1];
    }
    for (int i=1;i<N;i++){
        ll cur = 1;
        for (int j=1;j<=n;j++){
            int kur = j - 1;
            int id = i + j - 1;
            cur *= (ll)(cnt[id] - kur);
            cur %= p;
            if (cur == 0){
                break;
            }
        }
        gud[i] = (cur != 0);
    }
    vector<int> ans;
    for (int i=1;i<N;i++){
        if (gud[i]){
            ans.pb(low + i - 1);
        }
    }
    cout << ans.size() << el;
    for (auto x : ans){
        cout << x << " ";
    }
    cout << el;

    return 0;
}