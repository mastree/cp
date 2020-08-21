#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;
const int INF = 1e9 + 10;

int n;
int ar[N];
vector<int> req[N];
vector<pii> ans;

void push_pair(int a, int b){
    // cout << a << " " << b << el;
    ans.pb(mp(a, b));
    swap(ar[a], ar[b]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=i + 1;j<=n;j++){
            if (ar[i] > ar[j]) req[i].pb(j);
        }
    }
    for (int i=1;i<=n;i++){
        if (req[i].empty()) continue;
        vector<pii> temp;
        unordered_map<int, int> getid;
        unordered_map<int, bool> udh;
        int tempid = 0, id = req[i][0];
        for (auto x : req[i]) if (ar[x] < ar[id]) id = x;
        // temp.pb(mp(ar[i], i));
        // getid[i] = tempid++;
        for (auto x : req[i]){
            // if (x == id) continue;
            temp.pb(mp(ar[x], x));
            getid[x] = tempid++;
        }
        sort(temp.begin(), temp.end(), greater<pii>());
        // for (auto x : temp) cout << x.fi << " " << x.se << el;
        int cntvis = 0;

        stack<int> st;
        st.push(id);
        int cur = getid[id];
        udh[cur] = id;
        int len = temp.size();
        while (cntvis < len - 1){
            while (udh[cur]) cur--;
            cntvis++;
            st.push(temp[cur].se);
            cur = getid[temp[cur].se];
        }
        while (!st.empty()){
            int tp = st.top();
            st.pop();
            push_pair(i, tp);
        }
    }
    bool ok = 1;
    for (int i=1;i<n;i++){
        if (ar[i] > ar[i + 1]){
            ok = 0;
            break;
        }
    }
    if (!ok){
        cout << -1 << el;
        return 0;
    }
    cout << ans.size() << el;
    for (auto x : ans) cout << x.fi << " " << x.se << el;

    return 0;
}