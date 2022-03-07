#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e5 + 10;
const int DIG = 65;
const int M = DIG * DIG;

string allchar = "";
int alen;

int n;
string ar[N];
int getval[300];
char idchar[DIG];

int getId(const string& s){
    int ret = 0;
    for (auto x : s){
        ret = ret * alen + getval[x];
    }
    if (s.size() == 2) return ret + N - 10000;
    return ret;
}
string getName(int id){
    string ret;
    if (id >= N - 10000){
        id -= N - 10000;
        ret += idchar[id / alen];
        ret += idchar[id % alen];
    } else{
        ret += idchar[id / (alen * alen)];
        id %= alen * alen;
        ret += idchar[id / alen];
        ret += idchar[id % alen];
    }
    return ret;
}

vector<int> adj[N], in[N];
vector<int> path;
string ans;
unordered_map<string, int> ada;

bool bisa(){
    int od = 0;
    for (int i=0;i<N;i++){
        int a = adj[i].size();
        int b = in[i].size();
        if (abs(a - b) == 1){
            od++;
        } else if (a != b) return false;
    }
    return (od & 1 ^ 1);
}
bool check(){
    for (int i=0;i<n;i++){
        string temp;
        for (int j=0;j<3;j++){
            temp.pb(ans[i + j]);
        }
        if (ada[temp]) ada[temp]--;
        else return 0;
    }
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<26;i++){
        allchar.pb(char('a' + i));
    }
    for (int i=0;i<26;i++){
        allchar.pb(char('A' + i));
    }
    for (int i=0;i<10;i++){
        allchar.pb(char('0' + i));
    }
    alen = allchar.size();
    for (int i=0;i<alen;i++){
        getval[allchar[i]] = i;
        idchar[i] = allchar[i];
    }
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        ada[ar[i]]++;
        int a = getId(ar[i].substr(0, 2));
        int cur = getId(ar[i]);
        int b = getId(ar[i].substr(1, 2));
        adj[a].pb(cur);
        in[cur].pb(a);
        adj[cur].pb(b);
        in[b].pb(cur);
    }
    if (!bisa()){
        cout << "NO" << el;
        return 0;
    }
    stack<int> st;
    for (int i=0;i<N;i++){
        int a = adj[i].size();
        int b = in[i].size();
        if (a > b && a - b == 1){
            st.push(i);
            break;
        }
    }
    if (st.empty()){
        for (int i=N - 10000;i<N;i++){
            if (adj[i].size()){
                st.push(i);
                break;
            }
        }
    }
    while (!st.empty()){
        auto node = st.top();
        if (adj[node].empty()){
            path.pb(node);
            st.pop();
        } else{
            auto nnode = adj[node].back();
            adj[node].pop_back();
            st.push(nnode);
        }
    }
    int len = path.size();
    if (len == 0){
        cout << "NO" << el;
        return 0;
    }
    reverse(path.begin(), path.end());
    ans = getName(path[0]);
    for (int i=1;i<len;i+=2){
        if (path[i] >= N - 10000) break;
        ans += getName(path[i])[2];
    }
    if ((int)ans.size() == n + 2 && check()){
        cout << "YES" << el;
        cout << ans << el;
    } else{
        cout << "NO" << el;
    }

    return 0;
}