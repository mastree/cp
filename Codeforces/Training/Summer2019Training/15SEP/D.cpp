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

const string win1="Monocarp";
const string win2="Bicarp";

int n;
string s;
int lsisa,rsisa,ltot,rtot;

int selisih(){
    return ltot-rtot;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i=0;i<n;i++){
        if (s[i]=='?'){
            if (i<n/2) lsisa++;
            else rsisa++;
            continue;
        }

        if (i<n/2) ltot+=(int)(s[i]-'0');
        else rtot+=(int)(s[i]-'0');
    }

//    cout << lsisa << " " << rsisa << " " << ltot << " " << rtot << el;

    if ((lsisa+rsisa)&1){
        cout << win1 << el;
        return 0;
    }

    if (lsisa<rsisa){
        swap(lsisa,rsisa);
        swap(ltot,rtot);
    }

    int dsisa=lsisa-rsisa,dtot=-selisih();
//    cout << dtot << " " << dsisa << el;
    if (dtot!=dsisa/2*9){
        cout << win1 << el;
    } else cout << win2 << el;

    return 0;
}