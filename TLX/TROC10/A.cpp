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

string s, t;
int n;
bool sama = 1;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    n = s.length();

    for (int i=0;i<n;i++){
        int dig1;
        if ((s[i] - 'a') < 26 && (s[i] - 'a') >= 0){
            dig1 = (s[i] - 'a');
        } else{
            dig1 = (s[i] - 'A');
        }
        int dig2;
        if ((t[i] - 'a') < 26 && (t[i] - 'a') >= 0){
            dig2 = (t[i] - 'a');
        } else{
            dig2 = (t[i] - 'A');
        }

        if (dig1 != dig2){
            sama = 0;
            break;
        }
    }
    if (sama){
        cout << "20/20" << el;
    } else{
        cout << "x_x" << el;
    }

    return 0;
}