#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e4 + 10;

int n;
vector<int> v;
int ans[N];
vector<int> sisa;

bool ada[N];

void solve(vector<int>& v){
    if (v.size() == 1){
        sisa.pb(v.back());
        return;
    }
    vector<int> nv;
    int len = v.size();
    if (len & 1){
        sisa.pb(v.back());
        len--;
    }
    for (int i=0;i<len;i += 2){
        int ni = i + 1;
        int res1, res2;
        cout << "? " << v[i] << " " << v[ni] << endl;
        cin >> res1;
        cout << "? " << v[ni] << " " << v[i] << endl;
        cin >> res2;
        if (res1 > res2){
            ans[v[i]] = res1;
            nv.pb(v[ni]);
        } else{
            ans[v[ni]] = res2;
            nv.pb(v[i]);
        }
    }
    if (nv.size()) solve(nv);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        v.pb(i);
    }
    solve(v);
    while (!sisa.empty()){
        if (sisa.size() == 1){
            for (int i=1;i<=n;i++){
                ada[ans[i]] = 1;
            }
            int temp = -1;
            for (int i=1;i<=n;i++){
                if (!ada[i]){
                    temp = i;
                    break;
                }
            }
            ans[sisa.back()] = temp;
            break;
        }
        v.swap(sisa);
        sisa.clear();
        solve(v);
    }

    cout << "! ";
    for (int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}