/*************************************************************************
    > File Name: minimum-domino-rotations-for-equal-row.cpp
    > Author: tiankonguse
    > Mail: i@tiankonguse.com
    > Created Time: Sun Mar 10 09:57:47 2019
    > desc: 1007. Minimum Domino Rotations For Equal Row
 ************************************************************************/

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<time.h>
#include "../../include/base.h"
using namespace std;


#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

const int debug = 0;
typedef unsigned uint;
typedef unsigned char uchar;
auto __ =[]() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}
();


class Solution {
    int ans;
    int DominoRotations(vector<int>& A, vector<int>& B, int value){
        int tmpAns = 0;
        for(int i=0;i<A.size();i++){
            if(A[i] == value){
            }else if(B[i] == value){
                tmpAns++;
            }else{
                return -1;
            }
        }
        return tmpAns;
    }
    void updateAns(int tmpAns){
        if(tmpAns == -1){
        }else if(ans == -1){
            ans = tmpAns;
        }else{
            ans = min(ans, tmpAns);
        }
    }

public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        ans = -1;
        updateAns(DominoRotations(A, B, A[0]));
        updateAns(DominoRotations(B, A, A[0]));
        updateAns(DominoRotations(A, B, B[0]));
        updateAns(DominoRotations(B, A, B[0]));
        return ans;
    }
};
template <class ansType, class dataType1 = int, class dataType2 = int>
void test(ansType& expectAns, dataType1& first = dataType1(), dataType2 second = dataType2()) {
    Solution work;
    ansType ans;
    ans = work.minDominoRotations(first, second);

    static int index = 0;
    index++;
    bool check = eq(ans, expectAns);
    printf("\n");
    if(!check) {
        printf("index %d: NO\n", index);
        output("first", first);
        output("second", second);
        output("ans", ans);
        output("expectAns", expectAns);
    } else {
        printf("index %d: YES\n", index);
    }
    printf("\n");

}

int main() {
    vector<int> A;
    vector<int> B;
    int expectAns;


    A = {2,1,2,4,2,2};
    B = {5,2,6,2,3,2};
    expectAns = 2;
    test(expectAns, A, B);


    A = {3,5,1,2,3};
    B = {3,6,3,3,4};
    expectAns = -1;
    test(expectAns, A, B);


    A = {2};
    B = {2};
    expectAns = 0;
    test(expectAns, A, B);
    return 0;
}
