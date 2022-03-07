#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 62;

vector<char> ch;
vector<char> vec;

char ask(const char& s){
    char ret;
    cout << s << endl;
    cin >> ret;
    return ret;
}
char ask(const string& s){
    char ret;
    cout << s << endl;
    cin >> ret;
    return ret;
}
bool lower_than(char a, char b){
    string s = "";
    s += a;
    s += b;
    char temp = ask(s);
    if (temp == 'Y' || temp == 'C'){
        if (temp == 'C') exit(0);
        return 1;
    }
    return 0;
}
void solve(int l, int r){
    if (l == r) return;
    int m = (l + r) / 2;
    solve(l, m);
    solve(m + 1, r);
    vector<char> svec;
    int ll = l;
    for (int i=m + 1;i<=r;i++){
        while (l <= m && lower_than(vec[l], vec[i])){
            svec.push_back(vec[l++]);
        }
        svec.push_back(vec[i]);
    }
    while (l <= m) svec.push_back(vec[l++]);
    for (int i=ll;i<=r;i++){
        vec[i] = svec[i - ll];
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (char i='a';i<='z';i++){
        ch.push_back(i);
    }
    for (char i='A';i<='Z';i++){
        ch.push_back(i);
    }
    for (char i='0';i<='9';i++){
        ch.push_back(i);
    }
    // cout << ch.size() << el;
    for (auto& x : ch){
        char temp = ask(x);
        if (temp == 'Y' || temp == 'C'){
            vec.push_back(x);
            if (temp == 'C') return 0;
        }
    }
    solve(0, (int)vec.size() - 1);
    for (auto& x : vec){
        cout << x;
    }
    cout << endl;
    char temp;
    cin >> temp;

    return 0;
}