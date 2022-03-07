// #pragma gcc optimize ("O2")
// #pragma gcc optimize ("unroll-loops")

// #include <bits/stdc++.h>


// #define fi first
// #define se second
// #define pb(a) push_back(a)
// #define mp(a, b) make_pair(a, b)
// #define el '\n'

// using namespace std;
// using ll = long long;
// using pii = pair<int, int>;

// const int N = 1e5 + 10;
// const int INF = 1e9 + 10;

// int S, L, n;
// map<string, int> getid;
// string getname[N];
// bool isadj[201][201];
// int ar[N];

// pii t[4 * N];
// int lazy[4 * N];

// pii merge(pii a, pii b){
//     if (a.fi < b.fi) return a;
//     else if (b.fi < a.fi) return b;
//     if (ar[a.se] < ar[b.se]) return a;
//     return b;
// }

// void setnode(int v, int tl, int tr, int pos, int val){
//     if (tr < pos || pos < tl) return;
//     if (tl == tr){
//         t[v] = mp(val, pos);
//         return;
//     }
//     int tm = (tl + tr) / 2;
//     setnode(v * 2, tl, tm, pos, val);
//     setnode(v * 2 + 1, tm + 1, tr, pos, val);
//     t[v] = merge(t[v * 2], t[v * 2 + 1]);
// }

// void init(){
//     for (int i=1;i<=S;i++){
//         int cur = 0;
//         for (int j=1;j<=n;j++){
//             if (ar[j] == i){
//                 cout << j << " " << j - cur << el;
//                 setnode(1, 1, n, j, j - cur);
//                 cur++;
//             } else{
//                 if (isadj[i][ar[j]]) cur++;
//             }
//         }
//     }
// }

// void push(int v){
//     if (lazy[v]){
//         t[v * 2].fi += lazy[v];
//         t[v * 2 + 1].fi += lazy[v];
//         lazy[v * 2] += lazy[v];
//         lazy[v * 2 + 1] += lazy[v];
//         lazy[v] = 0;
//     }
// }
// void update(int v, int tl, int tr, int l, int r, int val){
//     if (l > r || tr < l || r < tl) return;
//     else if (l <= tl && tr <= r){
//         lazy[v] += val;
//         t[v].fi += val;
//         return;
//     }
//     push(v);
//     int tm = (tl + tr) / 2;
//     update(v * 2, tl, tm, l, r, val);
//     update(v * 2 + 1, tm + 1, tr, l, r, val);
//     t[v] = merge(t[v * 2], t[v * 2 + 1]);
// }
// pii ask(int v, int tl, int tr, int l, int r){
//     if (l > r || tr < l || r < tl) return mp(INF, -1);
//     else if (l <= tl && tr <= r){
//         return t[v];
//     }
//     push(v);
//     int tm = (tl + tr) / 2;
//     return merge(ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r));
// }

// int main () {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> S >> L >> n;
//     for (int i=1;i<=S;i++){
//         string temp;
//         cin >> temp;
//         getid[temp] = 1;
//     }    
//     {
//         int tempid = 0;
//         for (auto& x : getid){
//             x.se = ++tempid;
//             getname[tempid] = x.fi;
//         }
//     }
//     for (int i=1;i<=L;i++){
//         string temp1, temp2;
//         cin >> temp1 >> temp2;
//         int id1 = getid[temp1];
//         int id2 = getid[temp2];
//         isadj[id1][id2] = 1;
//         isadj[id2][id1] = 1;
//     }
//     for (int i=1;i<=n;i++){
//         string temp;
//         cin >> temp;
//         ar[i] = getid[temp];
//     }
//     init();
//     vector<int> ans;
//     for (int i=1;i<=n;i++){
//         auto res = ask(1, 1, n, 1, n);
//         ans.pb(ar[res.se]);
//         update(1, 1, n, res.se, res.se, INF);
//         update(1, 1, n, res.se + 1, n, -1);
//     }
//     for (auto& x : ans){
//         cout << getname[x] << " ";
//     }
//     cout << el;

//     return 0;
// }
// #pragma gcc optimize ("O2")
// #pragma gcc optimize ("unroll-loops")

// #include <bits/stdc++.h>


// #define fi first
// #define se second
// #define pb(a) push_back(a)
// #define mp(a, b) make_pair(a, b)
// #define el '\n'

// using namespace std;
// using ll = long long;
// using pii = pair<int, int>;

// const int N = 1e5 + 10;
// const int INF = 1e9 + 10;

// int S, L, n;
// map<string, int> getid;
// string getname[N];
// bool isadj[201][201];
// int ar[N];

// pii t[4 * N];
// int lazy[4 * N];

// pii merge(pii a, pii b){
//     if (a.fi < b.fi) return a;
//     else if (b.fi < a.fi) return b;
//     if (ar[a.se] < ar[b.se]) return a;
//     return b;
// }

// void setnode(int v, int tl, int tr, int pos, int val){
//     if (tr < pos || pos < tl) return;
//     if (tl == tr){
//         t[v] = mp(val, pos);
//         return;
//     }
//     int tm = (tl + tr) / 2;
//     setnode(v * 2, tl, tm, pos, val);
//     setnode(v * 2 + 1, tm + 1, tr, pos, val);
//     t[v] = merge(t[v * 2], t[v * 2 + 1]);
// }

// void init(){
//     for (int i=1;i<=S;i++){
//         int cur = 0;
//         for (int j=1;j<=n;j++){
//             if (ar[j] == i){
//                 cout << j << " " << j - cur << el;
//                 setnode(1, 1, n, j, j - cur);
//                 cur++;
//             } else{
//                 if (isadj[i][ar[j]]) cur++;
//             }
//         }
//     }
// }

// void push(int v){
//     if (lazy[v]){
//         t[v * 2].fi += lazy[v];
//         t[v * 2 + 1].fi += lazy[v];
//         lazy[v * 2] += lazy[v];
//         lazy[v * 2 + 1] += lazy[v];
//         lazy[v] = 0;
//     }
// }
// void update(int v, int tl, int tr, int l, int r, int val){
//     if (l > r || tr < l || r < tl) return;
//     else if (l <= tl && tr <= r){
//         lazy[v] += val;
//         t[v].fi += val;
//         return;
//     }
//     push(v);
//     int tm = (tl + tr) / 2;
//     update(v * 2, tl, tm, l, r, val);
//     update(v * 2 + 1, tm + 1, tr, l, r, val);
//     t[v] = merge(t[v * 2], t[v * 2 + 1]);
// }
// pii ask(int v, int tl, int tr, int l, int r){
//     if (l > r || tr < l || r < tl) return mp(INF, -1);
//     else if (l <= tl && tr <= r){
//         return t[v];
//     }
//     push(v);
//     int tm = (tl + tr) / 2;
//     return merge(ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r));
// }

// int main () {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> S >> L >> n;
//     for (int i=1;i<=S;i++){
//         string temp;
//         cin >> temp;
//         getid[temp] = 1;
//     }    
//     {
//         int tempid = 0;
//         for (auto& x : getid){
//             x.se = ++tempid;
//             getname[tempid] = x.fi;
//         }
//     }
//     for (int i=1;i<=L;i++){
//         string temp1, temp2;
//         cin >> temp1 >> temp2;
//         int id1 = getid[temp1];
//         int id2 = getid[temp2];
//         isadj[id1][id2] = 1;
//         isadj[id2][id1] = 1;
//     }
//     for (int i=1;i<=n;i++){
//         string temp;
//         cin >> temp;
//         ar[i] = getid[temp];
//     }
//     init();
//     vector<int> ans;
//     for (int i=1;i<=n;i++){
//         auto res = ask(1, 1, n, 1, n);
//         ans.pb(ar[res.se]);
//         update(1, 1, n, res.se, res.se, INF);
//         update(1, 1, n, res.se + 1, n, -1);
//     }
//     for (auto& x : ans){
//         cout << getname[x] << " ";
//     }
//     cout << el;

//     return 0;
// }
#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int S, L, n;
map<string, int> getid;
string getname[N];
bool isadj[201][201];

vector<int> vec;
void solve(int id){
    int len = vec.size();
    // cout << id << " => " << el;
    {
        vector<int> nvec;
        vector<int> simp;
        for (int i=0;i<len;i++){
            if (vec[i] == id){
                nvec.pb(vec[i]);
            } else{
                if ((simp.size() || vec[i] > id) && isadj[id][vec[i]]){
                    simp.pb(vec[i]);
                } else{
                    for (auto& x : simp){
                        nvec.pb(x);
                    }
                    simp.clear();
                    nvec.pb(vec[i]);
                }
            }
        }
        for (auto& x : simp){
            nvec.pb(x);
        }
        vec.swap(nvec);
    }
    // for (auto x : vec) cout << x << " "; cout << el;
    {
        vector<int> nvec;
        vector<int> simp;
        for (int i=len - 1;i>=0;i--){
            if (vec[i] == id){
                if (simp.empty()){
                    nvec.pb(vec[i]);
                } else{
                    if (simp.back() > vec[i]){
                        for (auto& x : simp){
                            nvec.pb(x);
                        }
                        simp.clear();
                    } 
                    nvec.pb(vec[i]);
                }
            } else{
                if (isadj[id][vec[i]]){
                    simp.pb(vec[i]);
                } else{
                    for (auto& x : simp){
                        nvec.pb(x);
                    }
                    simp.clear();
                    nvec.pb(vec[i]);
                }
            }
        }
        for (auto& x : simp){
            nvec.pb(x);
        }
        reverse(nvec.begin(), nvec.end());
        vec.swap(nvec);
    }
    // for (auto x : vec) cout << x << " "; cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> S >> L >> n;
    for (int i=1;i<=S;i++){
        string temp;
        cin >> temp;
        getid[temp] = 1;
    }    
    {
        int tempid = 0;
        for (auto& x : getid){
            x.se = ++tempid;
            getname[tempid] = x.fi;
        }
    }
    for (int i=1;i<=L;i++){
        string temp1, temp2;
        cin >> temp1 >> temp2;
        int id1 = getid[temp1];
        int id2 = getid[temp2];
        isadj[id1][id2] = 1;
        isadj[id2][id1] = 1;
    }
    for (int i=1;i<=n;i++){
        string temp;
        cin >> temp;
        vec.pb(getid[temp]);
    }
    for (int i=S;i>=1;i--){
        solve(i);
    }
    for (auto& x : vec){
        cout << getname[x] << " ";
    }
    cout << el;

    return 0;
}