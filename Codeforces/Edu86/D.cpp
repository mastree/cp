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

const int N = 2e5 + 10;
const int INF = 1e9;

int n, k;
int cr[N];
int mn[N];

int cnt[N];
set<int> setdah;

vector<int> ans[N];
int alen;

int find_mn(int cur){
    int low = 0, high = k;
    while (low < high){
        int mid = (low + high + 1) / 2;
        if (mn[mid] > cur){
            low = mid;
        } else{
            high = mid - 1;
        }
    }
    return low;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        cnt[a]++;
        setdah.insert(a);
    }
    mn[0] = INF;
    for (int i=1;i<=k;i++){
        cin >> mn[i];
    }
    // for (int i=1;i<=k;i++){
    //     mn[i] = min(cr[i], mn[i - 1]);
    // }

    while (!setdah.empty()){
        alen++;
        auto it = setdah.end();
        it--;
        int cur = 0;
        // vector<int> hapus;
        while (1){
            int now = *it;
            bool hapus = 0;
            while (mn[now] > cur){
                ans[alen].pb(now);
                cnt[now]--;
                cur++;
                if (cnt[now] == 0){
                    hapus = 1;
                    break;
                }
            }
            if (hapus) setdah.erase(now);
            int nx = find_mn(cur);
            if (nx == 0) break;
            it = setdah.upper_bound(nx);
            if (it == setdah.begin()) break;
            it--;
        } 
    }
    cout << alen << el;
    for (int i=1;i<=alen;i++){
        cout << ans[i].size() << " ";
        for (auto x : ans[i]){
            cout << x << " ";
        }
        cout << el;
    }

    return 0;
}