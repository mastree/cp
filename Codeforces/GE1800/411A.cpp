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

int len;
string s;
bool cek[3];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    len = s.length();
    if (len < 5){
        cout << "Too weak" << el;
        return 0;
    }

    for (int i=0;i<len;i++){
        int ch;
        ch = s[i] - 'a';
        if (ch >= 0 && ch < 26){
            cek[0] = 1;
            continue;
        }
        ch = s[i] - 'A';
        if (ch >= 0 && ch < 26){
            cek[1] = 1;
            continue;
        }
        ch = s[i] - '0';
        if (ch >= 0 && ch < 10){
            cek[2] = 1;
            continue;
        }
    }

    if (cek[0] && cek[1] && cek[2]){
        cout << "Correct" << el;
    } else {
        cout << "Too weak" << el;
    }

    return 0;
}