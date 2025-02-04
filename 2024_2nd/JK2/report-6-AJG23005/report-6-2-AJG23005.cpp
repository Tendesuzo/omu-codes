// AJG23005 中 天花

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <time.h>
using namespace std;

struct sum_n {
    int n[10000];
    int num;
};

int sum_n_variable(sum_n s) {
    int sum = 0;
    for (int i = 0; i < s.num; i++) {
        sum += s.n[i];
    }
    return sum;
}

int sum_n_reference(sum_n &s) {
    int sum = 0;
    for (int i = 0; i < s.num; i++) {
        sum += s.n[i];
    }
  return sum; // 合計値を返す
}

int main(void) {
    clock_t start, end;
    sum_n s2 = {};
    double diff;
    srand(static_cast<unsigned>(time(0))); // 時刻をシードとして設定
  // 乱数を1000回生成
    for (int i = 0; i < 1000; ++i) {
        s2.n[i] = rand() % 10000 + 1;
    };
    s2.num = 1000;

    start = clock();
    int total_variable_sum = sum_n_variable(s2);
    end = clock();
    diff = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "構造体変数を仮引数とした場合の計算時間:" << diff << endl;
    cout << "計算結果：" << total_variable_sum << endl;

    start = clock();
    int total_reference_sum = sum_n_reference(s2);
    end = clock();
    diff = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "構造体の参照を仮引数とした場合の計算時間:" << diff << endl;
    cout << "計算結果：" << total_reference_sum << endl;

    return 0;
}
