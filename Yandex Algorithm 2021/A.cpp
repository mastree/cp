#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<int> to_vec(const string& s){
    vector<int> ret;
    int i = 0;
    int len = s.size();

    while (i < len){
        if (s[i] == 'o'){
            ret.pb(1);
            i += 3;
        } else{
            ret.pb(0);
            i += 4;
        }
    }
    return ret;
}

vector<int> vec[2];
string s[2];


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s[0] >> s[1];
    for (int i=0;i<2;i++){
        vec[i] = to_vec(s[i]);
    }
    if (vec[0].size() != vec[1].size()){
        if (vec[0].size() > vec[1].size()){
            cout << '>' << el;
        } else{
            cout << '<' << el;
        }
        return 0;
    }
    int len = vec[0].size();
    for (int i=0;i<len;i++){
        if (vec[0][i] != vec[1][i]){
            if (vec[0][i] > vec[1][i]){
                cout << '>' << el;
            } else{
                cout << '<' << el;
            }
            return 0;
        }
    }
    cout << '=' << el;

    return 0;
}