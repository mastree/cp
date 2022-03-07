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

int tc;
int n, m;

void solve(){
    cin >> n;
    unordered_map<string, int> conv;
    vector<string> rconv(n + 1);
    for (int i=1;i<=n;i++){
        string a;
        cin >> a;
        conv[a] = i;
        rconv[i] = a;
    }
    cin >> m;
    vector<vector<int>> rdep(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i=0;i<m;i++){
        string s;
        cin >> s;
        auto pos = s.find(",");
        int len = s.size();
        int a = conv[s.substr(0, pos)];
        int b = conv[s.substr((int)pos + 1, len - ((int)pos + 1))];
        assert(a != 0);
        assert(b != 0);
        rdep[b].pb(a);
        indeg[a]++;
    }
    int qcnt;
    cin >> qcnt;
    while (qcnt--){
        vector<int> sim_indeg = indeg;

        vector<bool> carry(n + 1, 0), root(n + 1, 0);
        int flen;
        cin >> flen;
        for (int i=0;i<flen;i++){
            string s;
            cin >> s;
            int temp = conv[s];
            root[temp] = 1;
        }
        queue<int> q;
        for (int i=1;i<=n;i++){
            if (indeg[i] == 0){
                q.push(i);
            }
        }
        while (!q.empty()){
            int node = q.front();
            q.pop();
            for (auto& x : rdep[node]){
                if (carry[node] || root[node]) carry[x] = 1; 
                if (--indeg[x] == 0){
                    q.push(x);
                }
            }
        }
        vector<string> ans;
        for (int i=1;i<=n;i++){
            if (root[i] && !carry[i]){
                ans.pb(rconv[i]);
            }
        }
        int olen = ans.size();
        cout << olen << ' ';
        for (int i=0;i<olen;i++){
            cout << ans[i];
            if (i < olen - 1) cout << ' ';
        }
        cout << el;
        indeg.swap(sim_indeg);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--){
        solve();
    }    

    return 0;
}