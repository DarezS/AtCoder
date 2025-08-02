#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    string S; cin >> S;

    bool flg = true;

    string T = "";

    rep(i, S.size())
    {
        if(S[i] == '#')
        {
            T += '#';
            flg = true;
        }
        else
        {
            if(flg == true)
            {
                T += 'o';
                flg = false;
            }
            else
            {
                T += '.';
            }
        }
    }

    cout << T << endl;

    return 0;
}