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

const int N = 500;

// struct hue {
//     bool ev, zero, div3;
// };

int n;
// hue ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        int len = s.length();
        int tot=0;
        bool zero = 0, ev = 0, div3 = 0;
        for (int j=0;j<len;j++){
            int dig = (int)(s[j]-'0');
            if (s[j]=='0'){
                if (zero) ev=1;
                zero = 1;
            } else if (dig%2==0){
                ev=1;
            }
            // cout << dig << el;
            // cout << " => " << ev << el;
            tot+=dig;
        }
        div3=(tot%3==0);

        if (div3 && zero && ev) cout << "red" << el;
        else cout << "cyan" << el;
    }

    return 0;
}