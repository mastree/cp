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

const int N = 5e5 + 10;

int n;
int ans[N];
vector<int> st[N];
bool hapus[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    fill(ans, ans + n + 2, 1);
    int id = n / 2;
    for (int i=2;i<=id;i++){
        for (int j=i + i;j<=n;j+=i){
            st[i].pb(j);
        }
    }
    int cur = n;
    while (id > 1){
        ans[cur] = id;
        cur--;
        while(id > 1 && hapus[st[id][st[id].size() - 1]]){
            st[id].pop_back();
            if (st[id].empty()){
                id--;
            }
        }
        hapus[st[id][st[id].size() - 1]] = 1;
        st[id].pop_back();
        if (st[id].empty()) id--;
    }
    for (int i=2;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << el;

    return 0;
}