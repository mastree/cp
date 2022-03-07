#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n,0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

string rem(string s) {
    int len = s.size();
    if (s.back() == '0') {
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == '0') {
                s[i] = '9';
            } else {
                s[i]--;
                break;
            }
        }
        return s;
    } else {
        s[len - 1]--;
        return s;
    }
}

string remove_leading0(string s){
    string ret;
    bool udh = 0;
    for (auto& x : s){
        if (x != '0') udh = 1;
        if (udh){
            ret.push_back(x);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, p;
    cin >> s >> p;
    s = remove_leading0(s);
    p = remove_leading0(p);
    vector<int> v = prefix_function(p);
    int n = s.size(), m = p.size();
    int len = m - v.back();
    string ans = p;
    string add = p.substr(v.back());
    string radd = p.substr(0, len);
    string dep = "";

    int mxocc = 1;
    vector<int> mxsuff(n + 1, 0);
    if (s.substr(n - m) >= p) mxsuff[n - m] = 1;
    while ((int) ans.size() < n) {
        if ((int) ans.size() + len < n) {
            int lastlen = ans.size();
            int lastid = n - lastlen;

            if (mxsuff[lastid] != mxocc){
                mxsuff[lastid] = mxocc + 1;
                for (int i=lastid - 1;i>=lastid - len;i--){
                    mxsuff[i] = mxsuff[lastid] + 1;
                }
            } else{
                for (int i=lastid - 1;i>=lastid - len;i--){
                    mxsuff[i] = mxsuff[lastid];
                }
            }
            int res = 0;
            {
                for (int i=0;i<len;i++){
                    if (s[lastid - len + i] == radd[i]) continue;
                    if (s[lastid - len + i] > radd[i]){
                        res = 1;
                        break;
                    } else{
                        res = -1;
                        break;
                    }
                }
                if (res > 0){
                    mxsuff[lastid - len] = mxocc + 1;
                } else if (res == 0){
                    if (mxsuff[lastid] == mxocc) mxsuff[lastid - len]++;
                }
            }

            ans += add;
            mxocc++;
        } else if ((int) ans.size() + len == n) {
            string cur = ans + add;
            if (cur > s) {
                dep = s.substr(0, n - (int) ans.size());
                cur = dep + ans;
                if (cur > s) {
                    dep = remove_leading0(rem(dep));
                }
                break;
            } else {
                ans += add;
                mxocc++;
                cout << dep + ans << '\n';
                return 0;
            }
        } else {
            dep = s.substr(0, n - (int) ans.size());
            string cur = dep + ans;
            if (cur > s) {
                dep = remove_leading0(rem(dep));
            }
            break;
        }
    }
    for (int i=n - m - 1;i>=0;i--){
        int tam = 0;
        int clen = n - i - 1;
        if (mxsuff[i + 1] < (clen - m) / len + 1) tam = 1;
        mxsuff[i] = max(mxsuff[i], mxsuff[i + 1] + tam);
        if (tam) mxsuff[i + 1]++;
    }
    cout << mxocc << '\n';
    for (auto &x : mxsuff){
        cout << x << " ";
    }
    cout << '\n';
    // cout << dep + ans << '\n';
    {
        vector<int> ret(n, -1);
        int last = - n - n;
        for (int i=0;i<n;i++){
            // if (i != n - 1){
                if (mxsuff[i] != mxsuff[i + 1]){
                    last = i;
                }
            // }
            // if (i - last >= m) ret[i] = s[i] - '0';
            ret[i] = p[i - last] - '0';
        }
        bool butuh = 0;
        for (int i=n - 1;i>=0;i--){
            if (ret[i] == -1){
                if (butuh){
                    if (s[i] == '0'){
                        ret[i] = 9;
                    } else{
                        ret[i] = s[i] - '1';
                        butuh = 0;
                    }
                } else{
                    ret[i] = s[i] - '0';
                }
            } else{
                butuh = (ret[i] > s[i]);
            }
        }
        bool udh = 0;
        for (int i=0;i<n;i++){
            if (ret[i] > 0) udh = 1; 
            if (udh) cout << ret[i];
        }
        cout << '\n';
    }
 
    return 0;
}