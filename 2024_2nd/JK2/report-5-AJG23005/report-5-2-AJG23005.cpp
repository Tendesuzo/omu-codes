//AJG23005 中 天花

#include <iostream>
using namespace std;

//約数の合計を計算する関数
int sum_of_divisors(int num) {
    int sum = 0;
    for (int j = 1; j < num; j++) {
        if (num % j == 0) {
            sum += j;
        }
    }
    return sum;
}

int main(){
    cout << "友愛数：";
    for (int i=2; i<2001; i++){
        int candidate_num = i; //候補となる数
        int candidate_divisor_sum = sum_of_divisors(candidate_num); //約数の合計
        int counterpart_num = candidate_divisor_sum; //候補と対応する数
        int counterpart_divisor_sum = sum_of_divisors(counterpart_num); //候補と対応する数の約数の合計
        if (candidate_num == counterpart_divisor_sum && candidate_num < counterpart_num){
            cout << "(" << candidate_num << ", " << counterpart_num << ") ";
        }
    }
    cout << endl;
    return 0;
};
