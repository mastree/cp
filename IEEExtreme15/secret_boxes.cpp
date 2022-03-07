#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9 + 7;

int ask(vector<int> vec){
    assert(vec.size() == 4);
    cout << "? " << vec[0] << " " << vec[1] << " " << vec[2] << " " << vec[3] << endl;
    char res;
    cin >> res;
    if (res == '<') return -1;
    else if (res == '=') return 0;
    return 1;
}
int ask(int a, int b, int c, int d){
    return ask(vector<int>{a, b, c, d});
}
vector<vector<int>> urutan = {
    {0, 1, 2, 3},
    {0, 2, 1, 3},
    {0, 3, 1, 2}
};
vector<int> bf4(vector<int> vec){
    assert(vec.size() == 4);
    vector<int> ret(4, 0);
    for (auto& urut : urutan){
        vector<int> temp;
        for (auto& x : urut) temp.pb(vec[x]);
        int res = ask(temp);
        if (res == -1){
            for (int i=0;i<4;i++){
                if (i < 2) ret[urut[i]]--;
                else ret[urut[i]]++;
            }
        } else if (res == 1){
            for (int i=0;i<4;i++){
                if (i < 2) ret[urut[i]]++;
                else ret[urut[i]]--;
            }
        }
    }
    return ret;
}
vector<int> bf5(vector<int> vec){ // length = 5
    vector<int> ret(5, 0);
    vector<vector<int>> higher(5, vector<int>(5, 0));
    for (int ex=0;ex<5;ex++){
        vector<int> tvec, id;
        for (int i=0;i<5;i++){
            if (i == ex) continue;
            tvec.pb(vec[i]);
            id.pb(i);
        }
        auto temp = bf4(tvec);
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                if (i == j) continue;
                if (temp[i] > temp[j]) higher[id[i]][id[j]] = 1;
                if (temp[j] > temp[i]) higher[id[j]][id[i]] = 1;
            }
        }
    }
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            ret[i] += higher[i][j];
        }
    }
    return ret;
}
vector<int> find_min(vector<int> vec, vector<int> cnt){
    vector<pii> temp;
    int n = vec.size();
    for (int i=0;i<n;i++){
        temp.emplace_back(cnt[i], vec[i]);
    }
    sort(temp.begin(), temp.end());
    return {temp[0].se, temp[1].se, temp[2].se};
}
vector<int> find_max(vector<int> vec, vector<int> cnt){
    vector<pii> temp;
    int n = vec.size();
    for (int i=0;i<n;i++){
        temp.emplace_back(cnt[i], vec[i]);
    }
    sort(temp.begin(), temp.end());
    return {temp[n - 1].se, temp[n - 2].se, temp[n - 3].se};
}
vector<int> find_max_min(const vector<int>& vec, const vector<int>& cnt, bool mx){
    if (mx) return find_max(vec, cnt);
    return find_min(vec, cnt);
}

int q;
int n;
void msort(vector<int>& vec, int l, int r, int a, int b){
    if (l >= r) return;
    int m = (l + r) / 2;
    msort(vec, l, m, a, b);
    msort(vec, m + 1, r, a, b);

    int i = l;
    int j = m + 1;
    vector<int> temp;
    while (i <= m && j <= r){
        if (vec[i] == a || vec[i] == b){
            if (vec[j] == a || vec[j] == b){
                if (vec[i] == a) temp.pb(vec[i++]);
                else temp.pb(vec[j++]);
            } else{
                temp.pb(vec[i++]);
            }
        } else if (vec[j] == a || vec[j] == b){
            temp.pb(vec[j++]);
        } else{
            auto res = ask(vec[i], b, vec[j], a);
            if (res <= 0) temp.pb(vec[i++]);
            else temp.pb(vec[j++]);
        }
    }
    while (i <= m){
        temp.pb(vec[i++]);
    }
    while (j <= r){
        temp.pb(vec[j++]);
    }
    for (int i=l;i<=r;i++){
        vec[i] = temp[i - l];
    }
}
void answer(vector<int> vec){
    vector<int> ans(n);
    for (int i=0;i<n;i++){
        ans[vec[i] - 1] = i + 1;
    }
    cout << "! ";
    for (auto& x : ans) cout << x << ' ';
    cout << endl;
    string res;
    cin >> res;
}
bool is_in(int a, vector<int>& vec){
    for (auto& x : vec) if (x == a) return 1;
    return 0;
}
void solve(){
    vector<int> vec;
    for (int i=1;i<=n;i++){
        vec.pb(i);
    }
    vector<int> carry;
    // cari 3 minimum
    for (int i=0;i<n;i++){
        if (i == 0){
            vector<int> cur;
            for (int j=0;j<4;j++){
                cur.pb(vec[i + j]);
            }
            carry = find_max_min(cur, bf4(cur), 0);
            i += 3;
        } else{
            vector<int> cur = carry;
            for (int j=0;j<1;j++){
                if (i + j >= n) break;
                cur.pb(vec[i + j]);
            }
            while (cur.size() < 4){
                for (int j=0;j<n;j++){
                    bool ok = 1;
                    for (auto& x : cur){
                        if (vec[j] == x){
                            ok = 0;
                            break;
                        }
                    }
                    if (ok){
                        cur.pb(vec[j]);
                        break;
                    }
                }
            }
            carry = find_max_min(cur, bf4(cur), 0);
        }
    }
    int a = carry[0];
    int b = carry[1];
    int c = carry[2];
    {
        vector<int> sisa;
        for (int i=0;i<n;i++){
            if (is_in(vec[i], carry)) continue;
            sisa.pb(vec[i]);
        }
        // find 4
        int len = sisa.size();
        for (int i=0;i<len;i++){
            vector<int> cur = carry;
            cur.pb(sisa[i]);
            auto temp = bf4(cur);
            if (temp[3] == 2){
                carry.pb(sisa[i]);
                break;
            }
        }
        // find 5
        pii pos = mp(INF, -1);
        for (int i=0;i<len;i++){
            if (is_in(sisa[i], carry)) continue;
            vector<int> cur = {carry[0], carry[1], carry[3]};
            cur.pb(sisa[i]);
            auto temp = bf4(cur);
            pos = min(pos, mp(temp[3], sisa[i]));
        }
        carry.pb(pos.se);
    }
    {
        vector<int> cur = carry;
        auto temp = bf5(cur);
        vector<pii> ans;
        for (int i=0;i<5;i++){
            ans.emplace_back(temp[i], cur[i]);
        }
        sort(ans.begin(), ans.end());
        a = ans[0].se;
        b = ans[1].se;
    }
    msort(vec, 0, n - 1, a, b);
    answer(vec);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q >> n;
    while (q--){
        solve();
    }

    return 0;
}