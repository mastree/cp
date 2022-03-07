#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<char> cand;

unsigned n;
unsigned tar;

const unsigned p = 31;
const unsigned N = 20;

vector<string> ans;

unsigned gethash(string s){
    unsigned ret = 0;
    reverse(s.begin(), s.end());
    unsigned cur = 1;
    for (auto& x : s){
        ret += x * cur;
        cur *= p;
    }
    return ret;
}
bool samepref(string a, string b){
    int n = a.size();
    for (int i=0;i<n;i++){
        if (a[i] != b[i]) return 0;
    }
    return 1;
}
unsigned p31[N];
void dfs(unsigned len, unsigned hash, string& s){
    if (len == n){
        if (hash == tar) ans.pb(s);
        return;
    }
    for (auto& x : cand){
        unsigned nhash = hash + p31[len] * ((unsigned)x);
        if (nhash % p31[len + 1] == tar % p31[len + 1]){
            s.pb(x);
            dfs(len + 1, nhash, s);
            s.pop_back();
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    p31[0] = 1;
    for (unsigned i=1;i<N;i++){
        p31[i] = p31[i - 1] * p;
    }
    for (char c='a';c<='z';c++){
        cand.pb(c);
    }
    for (char c='A';c<='Z';c++){
        cand.pb(c);
    }
    cin >> n;
    cin >> tar;
    if (n <= 6){
        {
            string s;
            dfs(0, 0, s);
        }
        if (ans.empty()){
            cout << '-' << el;
            return 0;
        }
        for (auto& x : ans){
            reverse(x.begin(), x.end());
        }
        sort(ans.begin(), ans.end());
        for (auto& x : ans) cout << x << el;
    } else{
        vector<string> hehe;
        for (auto& x : cand){
            for (auto& y : cand){
                string s;
                ans.clear();
                tar -= (unsigned)p31[n - 1] * x;
                tar -= (unsigned)p31[n - 2] * y;
                n -= 2;
                dfs(0, 0, s);
                n += 2;
                for (auto& ss : ans){
                    ss.pb(y);
                    ss.pb(x);
                    reverse(ss.begin(), ss.end());
                    hehe.pb(ss);
                }
                tar += (unsigned)p31[n - 1] * x;
                tar += (unsigned)p31[n - 2] * y;
            }
        }
        if (hehe.empty()){
            cout << '-' << el;
            return 0;
        }
        sort(hehe.begin(), hehe.end());
        for (auto& x : hehe) cout << x << el;
    }

    return 0;
}