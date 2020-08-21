#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e6 + 10;
const int INF = 1e9;

int n;
vector <pii> v; // minimum-prefix, surplus;
vector <pii> tempv;
pii last = mp(INF, INF);
int cur;
int sisa;

stack <int> st[N];
pii t[4 * N]; // max-surplus, pos

pii proc(string s){
    pii ret = mp(0, 0);
    for (auto c : s){
        if (c == '('){
            ret.fi++;
        } else{
            ret.fi--;
        }
        ret.se = min(ret.fi, ret.se);
    }
    return ret;
}

void build(int v, int tl, int tr){
    if (tl == tr){
        t[v] = mp(st[tl].top(), tl);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1 , tr);
    if (t[v * 2].fi >= t[v * 2 + 1].fi){
        t[v] = t[v * 2];
    } else{
        t[v] = t[v * 2 + 1];
    }
}

void update(int v, int tl, int tr, int pos){
    if (pos < tl || tr < pos) return;
    else if (tl == tr){
        st[tl].pop();
        t[v] = mp(st[tl].top(), tl);
        return;
    }
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, pos);
    update(v * 2 + 1, tm + 1, tr, pos);
    if (t[v * 2].fi >= t[v * 2 + 1].fi){
        t[v] = t[v * 2];
    } else{
        t[v] = t[v * 2 + 1];
    }
}

pii query(int v, int tl, int tr, int l, int r){
    if (l > r) return mp(-INF, -1);
    else if (l <= tl && tr <= r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    pii temp1 = query(v * 2, tl, tm, l, min(tm, r));
    pii temp2 = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    if (temp1.fi >= temp2.fi){
        return temp1;
    } else{
        return temp2;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        pii temp = proc(s);
        if (s[s.length() - 1] == ')' && temp.fi <= temp.se){
            if (last.fi > temp.fi){
                last = temp;
            }
        }
        tempv.pb(temp);
    }
    bool ambil = 0;
    for (auto x : tempv){
        if (x != last || ambil){
            v.pb(mp(-x.se, x.fi));
        } else{
            ambil = 1;
        }
    }
    sisa = (int) v.size();
    sort(v.begin(), v.end());
    for (int i=0;i<N;i++){
        st[i].push(-INF);
    }
    for (auto x : v){
        st[x.fi].push(x.se);
    }
    build(1, 0, N - 1);

    while (sisa){
        pii temp = query(1, 0, N - 1, 0, cur);

        if (temp.fi + cur >= 0){
            cur += temp.fi;
            sisa--;
            update(1, 0, N - 1, temp.se);
        } else{
            break;
        }
    }
    if (sisa){
        cout << "No" << el;
    } else{
        if (cur + last.fi == 0){
            cout << "Yes" << el;
        } else{
            cout << "No" << el;
        }
    }

    return 0;
}