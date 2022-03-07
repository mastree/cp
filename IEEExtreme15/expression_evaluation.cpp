#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int q;

bool is_operator(char c){
    return c == '+' || c == '-' || c == '*' || c == '(' || c == ')';
}
bool non_bracket_operator(char c){
    return c == '+' || c == '-' || c == '*';
}
vector<pair<char, int>> parse(string s){
    string cur;
    vector<pair<char, int>> ret;
    for (auto& x : s){
        if (is_operator(x)){
            if (!cur.empty()){
                ret.pb(mp('$', stoi(cur)));
                cur = "";
            }
            ret.pb(mp(x, 0));
        } else{
            cur.pb(x);
        }
    }
    if (!cur.empty()) ret.pb(mp('$', stoi(cur)));
    return ret;
}
int calc(vector<pair<char, int>>& vec){
    vector<ll> ret; // stack
    char lastop = '+';
    while (!vec.empty()){
        auto cur = vec.back();
        vec.pop_back();
        if (is_operator(cur.fi)){
            if (non_bracket_operator(cur.fi)){
                lastop = cur.fi;
            } else{
                if (cur.fi == '('){
                    ll temp = calc(vec); // hasil di dalam bracket
                    if (lastop == '*'){
                        ret.back() = ret.back() * temp % MOD;
                    } else if (lastop == '-'){
                        ret.pb(-temp);
                    } else{
                        ret.pb(temp);
                    }
                    lastop = '$';
                } else{
                    break;
                }
            }
        } else{
            if (lastop == '*'){
                ret.back() = ret.back() * cur.se % MOD;
            } else if (lastop == '-'){
                ret.pb(-cur.se);
            } else{
                ret.pb(cur.se);
            }
            lastop = '$';
        }
    }
    ll tot = 0;
    for (auto& x : ret){
        tot = (tot + x + MOD) % MOD;
    }
    return tot;
}
bool is_valid(vector<pair<char, int>>& vec, int l, int r){
    if (l > r) return 0;
    if (l == r) return !is_operator(vec[l].fi);
    if (vec[l].fi != '$' && vec[l].fi != '(') return 0;
    if (is_operator(vec[l].fi)){
        int id = -1;
        for (int i=r;i>=l;i--){
            if (vec[i].fi == ')'){
                id = i;
                break;
            }
        }
        if (id == -1) return 0;
        vec[id] = mp('$', 0);
        return is_valid(vec, l + 1, id - 1) && is_valid(vec, id, r);
    }
    if (!non_bracket_operator(vec[l + 1].fi)) return 0;
    return is_valid(vec, l + 2, r);
}

void solve(){
    string s;
    cin >> s;
    vector<pair<char, int>> vec = parse(s); // operator ($ == angka), bilangan 
    {
        auto temp = vec;
        if (!is_valid(temp, 0, (int)temp.size() - 1)){
            cout << "invalid" << el;
            return;
        }
    }
    reverse(vec.begin(), vec.end());
    int ans = calc(vec);
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}