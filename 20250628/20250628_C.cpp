#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define notExists -1;

// 問題URL
// https://atcoder.jp/contests/abc412/tasks/abc412_c

int main(){
    
    int T; cin >> T;

    rep(i,T)
    {
        // testcase input
        int N; cin >> N;
        set<int> S;
        int startS;
        int endS;
        rep(i,N)
        {
            int inS; cin >> inS;
            S.insert(inS);
            if(i==0) startS = inS;
            if(i==N-1) endS = inS; 
        }

        // テストケースを解く(方針)
        // ①ドミノの終点(endS)より半分以上の大きさを持つドミノ(tgtS)を二部探索で見つける
        // ②見つからなかった場合(見つけた数がendSに等しい場合)、条件を満たす並べ方が存在しない
        // ③見つけた場合、そのtgtSをendSに置き換えて①から同様の処理
        // ④tgtSがドミノの始点(startS)以下の場合は終了
        int cnt=1;
        bool isContinue = true;
        bool isEnable = true;
        while(isContinue)
        {
            int tgtS = (endS+1) / 2;
            
            if(tgtS <= startS)
            {
                cnt++;
                isContinue = false;
                break;
            }

            auto it = S.lower_bound(tgtS);

            if (it != S.end()) {
                int val = *it;
                if(val == endS)
                {
                    isContinue = false;
                    cnt = notExists;
                    break;
                }
                cnt++;
                endS = val;
            } else {
                isContinue = false;
                cnt = notExists;
                break;
            }
        }

        cout << cnt << endl;
        

    }
    return 0;
}