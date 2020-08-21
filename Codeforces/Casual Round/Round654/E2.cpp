#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;
const int INF = 1e9 + 10;

int n;
int p;
int ar[N];
int cnt[N];
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
    for (int i=2;i<N;i++){
        cnt[i] += cnt[i - 1];
    }
    set<pii> setdah;
    for (int i=1;i<=n;i++){
        if (cnt[i]){
            setdah.insert(mp((cnt[i] - i + 1) % p, i));
        } else break;
    }
    for (int i=1;i<=n;i++){
        int sisa = (p - i + 1) % p;
        auto temp = setdah.lower_bound(mp(sisa, 0));
        if (temp == setdah.end() || temp->fi != sisa){
            gud[i] = 1;
        }
        setdah.erase(mp((cnt[i] - i + 1) % p, i));
        setdah.insert(mp((cnt[i + n] - (i + n) + 1) % p, i + n));
    }
    vector<int> ans;
    for (int i=1;i<=n;i++){
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