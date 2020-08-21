#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 400;
const int INF = 1e9;

int q;
int n;
string s;
string aop = "|&^";

struct Bintree{
    int val; // 0, 1, 2(x), 3(X), 4(undef)
    char op;
    Bintree * l, * r;
    Bintree() : val(4), l(0), r(0), op('x') {}
    Bintree(char val) : l(0), r(0), op('x') {
        if (val == '0' || val == '1') this->val = int(val - '0');
        else if (val == 'x') this->val = 2;
        else this->val = 3;
    }
};

typedef Bintree * BP;

void baca(BP& btree, int& id){
    if (id >= n) return;
    btree = new Bintree();
    BP l, r;
    ++id;
    if (s[id] == '('){
        baca(l, id);
    } else{
        char cur = s[id];
        l = new Bintree(cur);
        ++id;
    }
    btree->l = l;
    btree->op = s[id];
    ++id;
    if (s[id] == '('){
        baca(r, id);
    } else{
        char cur = s[id];
        r = new Bintree(cur);  
        ++id;
    }
    btree->r = r;
    ++id;
}

int eval(int a, char op, int b){
    if (op == '|'){
        if (a == 1 || b == 1) return 1;
        if (a == 0) return b;
        else if (b == 0) return a;
        if (a == 4 || b == 4) return 4;
        if (a != b) return 1;
        return a;
    } else if (op == '&'){
        if (a == 0 || b == 0) return 0;
        if (a == 1) return b;
        else if (b == 1) return a;
        if (a == 4 || b == 4) return 4;
        if (a != b) return 0;
        return a;
    } else{
        if (a == 0) return b;
        else if (b == 0) return a;
        if (a == 4 || b == 4) return 4;
        if (a == b) return 0;
        if (a > b) swap(a, b);
        if (a == 1){
            if (b == 2) return 3;
            else if (b == 3) return 2;
        }
        return 1;
    }
}

vector<int> calc(BP& t){
    vector<int> ret(5, INF);
    if (!t->l && !t->r){
        for (int i=0;i<5;i++){
            ret[i] = (t->val != i);
        }
        return ret;
    }
    vector<int> l = calc(t->l);
    vector<int> r = calc(t->r);
    
    for (auto op : aop){
        int tam = (t->op != op);
        for (int i=0;i<5;i++){
            for (int j=0;j<5;j++){
                int res = eval(i, op, j);
                int cost = l[i] + r[j] + tam;
                ret[res] = min(ret[res], cost);
            }
        }
    }
    return ret;
}

void solve(){
    cin >> s;
    n = s.length();
    if (n == 1){
        if (s[0] == '0' || s[0] == '1'){
            cout << 0 << el;
        } else{
            cout << 1 << el;
        }
        return;
    }
    BP btree;
    int dummy = 0;
    baca(btree, dummy);
    vector<int> temp = calc(btree);
    int ans = min(temp[0], temp[1]);
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}