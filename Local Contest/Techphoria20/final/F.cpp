#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int M = 26;

string conv = "A***3**HIL**M*O***2TUVWXY5O1SE*Z**8*";

int getid(char c){
    if ('A' <= c && c <= 'Z') return c - 'A';
    return c - '0' + 26;
}
void solve(string& s){
    bool pal = 1;
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j){
        if (s[i] != s[j]){
            pal = 0;
            break;
        }
        i++;
        j--;
    }
    string rs = s;
    reverse(rs.begin(), rs.end());
    for (auto& x : rs){
        int id = getid(x);
        if (id < conv.size()){
            x = conv[id];
        } else x = '*';
    }
    bool reflect = 1;
    for (int i=0;i<n;i++){
        if (s[i] != rs[i]){
            reflect = 0;
            break;
        }
    }
    cout << s << " -- ";
    if (!pal && !reflect){
        cout << "bukan palindrom";
    } else if (pal && !reflect){
        cout << "palindrom biasa";
    } else if (!pal && reflect){
        cout << "string refleksi";
    } else{
        cout << "palindrom refleksi";
    }
    cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    while (cin >> s){
        solve(s);
    }

    return 0;
}