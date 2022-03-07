#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = (2 << 16) + 10;

int n;
vector<int> vec;
vector<int> pos[N];

int ask_xor(int i, int j){
    cout << "XOR " << i << " " << j << endl;
    int ret;
    cin >> ret;
    return ret;
}
int ask_and(int i, int j){
    cout << "AND " << i << " " << j << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vec.resize(n + 1);
    for (int i=2;i<=n;i++){
        vec[i] = ask_xor(1, i);
        pos[vec[i]].pb(i);
    }
    if (pos[0].size()){
        vec[1] = ask_and(1, pos[0][0]);
    } else{
        int cur;
        for (cur=0;cur<n;cur++){
            if (pos[cur].size() >= 2) break;
        }
        if (cur < n){
            vec[1] = (vec[pos[cur][0]] ^ ask_and(pos[cur][0], pos[cur][1]));
        } else{
            for (cur=1;cur<=n;cur++){
                if (cur != 1 && cur != pos[n - 1][0]) break;
            }
            vec[1] = (vec[cur] ^ (ask_and(1, cur) + ask_and(pos[n - 1][0], cur)));
        }
    }
    cout << "! " << vec[1];
    for (int i=2;i<=n;i++){
        cout << " " << (vec[i] ^ vec[1]);
    }
    cout << endl;

    return 0;
}