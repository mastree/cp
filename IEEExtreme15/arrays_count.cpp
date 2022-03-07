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

const int LEN = 11;
const int N = (1 << 10);
const int MOD = 4;
const int XMOD = 3;

int q;
int n, k;
int pow3[LEN];
int glen[N];

int eval(vector<int>& vec){
    int ret = 0;
    for (auto& x : vec) ret |= x;
    return ret;
}
bool cek(vector<int> vec, int tar){
    reverse(vec.begin(), vec.end());
    while (!vec.empty()){
        if (eval(vec) == tar) return 1;
        int x = vec.back();
        vec.back() -= (1 << (glen[x] - 1));
        if (vec.back() <= 0){
            vec.pop_back();
        }
    }
    return 0;
}
int bintoint(string& s){
    int ret = 0;
    int len = s.size();
    for (int i=0;i<len;i++){
        if (s[i] == '1'){
            ret += (1 << (len - i - 1));
        }
    }
    return ret;
}
void solve(){
    cin >> n >> k;
    int ans = 0;
    for (int i=0;i<pow3[k] - 1;i++){
        vector<int> vec;
        int cur = i;
        for (int j=k - 1;j>=0;j--){
            vec.pb(cur / pow3[j]);
            cur %= pow3[j];
        }
        if (vec[0] != 2) continue;
        vector<string> temp;
        for (auto& x : vec){
            if (x == 2){
                temp.pb("1");
            } else{
                temp.back().pb(x + '0');
            }
        }
        {
            vec.clear();
            for (auto& x : temp) vec.pb(bintoint(x));
            if (cek(vec, (1 << n) - 1)) ans++;
        }
    }
    cout << (ans & XMOD) << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<(1 << 10);i++){
        for (int j=0;j<10;j++){
            if (i & (1 << j)) glen[i] = j + 1;
        }
    }
    pow3[0] = 1;
    for (int i=1;i<LEN;i++){
        pow3[i] = pow3[i - 1] * 3;
    }
    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}