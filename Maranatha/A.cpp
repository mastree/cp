#include <bits/stdc++.h>
#include <string>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

string gh[3],ge[3];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    gh[0]=" .--. ";
    gh[1]="|  oo|";
    gh[2]="|/\\/\\|";

    ge[0]=" .--. ";
    ge[1]="|oo  |";
    ge[2]="|/\\/\\|";

    int n;
    cin >> n;

    for (int i=0;i<n;i++){
        if (i%2){
            for (int j=0;j<3;j++){
                for (int k=0;k<n;k++){
                    cout << ge[j];
                }cout << el;
            }
        } else{
            for (int j=0;j<3;j++){
                for (int k=0;k<n;k++){
                    cout << gh[j];
                }cout << el;
            }
        }
    }

    return 0;
}