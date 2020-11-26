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

int n;
bool ada[N], down[N];

vector<int> vada;

void proc(string s){
    int yy = stoi(s);
    int mm;
    int dd;
    {
        int i = 0;
        for (i=0;i<s.size();i++){
            if (s[i] == '-') break;
        }
        i++;
        mm = (s[i] - '0') * 10 + s[i + 1] - '0';
        for (;i<s.size();i++){
            if (s[i] == '-') break;
        }
        i++;
        dd = (s[i] - '0') * 10 + s[i + 1] - '0';
    }
    if (mm < 2 || (mm == 2 && dd <= 28)){
        down[yy] = 1;
    }
    ada[yy] = 1;
}
string make(int yy, int mm, int dd){
    string syy = to_string(yy);
    string smm = to_string(mm);
    if (smm.size() == 1) smm = "0" + smm;
    string sdd = to_string(dd);
    if (sdd.size() == 1) sdd = "0" + sdd;
    return syy + "-" + smm + "-" + sdd;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    n++;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        proc(s);
    }
    vector<int> ans;
    for (int i=1;i<N;i++){
        if (ada[i]) vada.pb(i);
    }
    int len = vada.size();
    for (int i=0;i<len - 1;i++){
        int a = vada[i];
        int b = vada[i + 1];
        for (int j=b;j>a;j--){
            if (down[j]) continue;
            ans.pb(j);
        }
    }
    cout << ans.size() << el;
    for (auto x : ans){
        cout << make(x, 1, 1) << el;
    }

    return 0;
}