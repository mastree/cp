#include <bits/stdc++.h>
using namespace std;
    
string s;
vector<int> ve;
    
bool isVowel(char a) {
    int pos = a - 'a';
    return (pos == 0 || pos == 4 || pos == 8 || pos == 14 || pos == 20);
}
    
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> s;
    int tot = 0, vow = 0;
    for(int i = 0; i < (int)s.length(); i++) {
        if(isVowel(s[i])) {
            vow++;
            ve.push_back(tot);
            tot = 0;
        } else {
            tot++;
        }
    }
    ve.push_back(tot);
    
    if(vow == 0) {
        cout << 1 << "\n";
        return 0;
    }
    
    if(ve[0] > 0) {
        cout << 0 << "\n";
        return 0;
    }
    
    int pos = (vow + 1) / 2;
    cout << ve[pos] + 1 << "\n";
    return 0;
}