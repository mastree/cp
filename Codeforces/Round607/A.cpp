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

int q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        string s;
        cin >> s;

        int len = s.length();
        if (len>=2){
            string ph = s.substr(len-2, 2);
            // cout << ph << el;
            if (ph=="po"){
                cout << "FILIPINO" << el;
                continue;
            }
        }

        if (len>=4){
            string ph = s.substr(len-4, 4);
            if (ph == "desu" || ph == "masu"){
                cout << "JAPANESE" << el;
                continue;
            }
        } 

        if (len>=5){
            string ph = s.substr(len-5, 5);
            if (ph == "mnida"){
                cout << "KOREAN" << el;
                continue;   
            }
        }
    }

    return 0;
}