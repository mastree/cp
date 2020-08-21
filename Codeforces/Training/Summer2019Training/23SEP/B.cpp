#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

int n,k;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> s;

    if (n==1){
        if ((s[0]-'0')>0){
            if (k){
                cout << 0 << el;
                return 0;
            }else{
                cout << s << el;
                return 0;
            }
        } else{
            cout << s << el;
            return 0;
        }
    }


    for (int i=0;i<n;i++){
        if ((s[i]-'0')>0){
            if (i==0){
                if (s[i]=='1') continue;
                else if (k){
                    s[i]='1';
                    k--;
                }
            } else{
                if (k){
                    s[i]='0';
                    k--;
                }
            } 
        }
    }

    cout << s << el;

    return 0;
}