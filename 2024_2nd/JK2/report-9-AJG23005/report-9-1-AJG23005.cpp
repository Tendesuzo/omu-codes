//AJG23005 中 天花
//講義・課題に関するコメント
//vectorを用いると、配列の扱いがとても簡単になると感じた。

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int n; //乱数の個数

int main(){
    cout << "生成する乱数の個数を入力してください: ";
    cin >> n;

    vector<int> s;

    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i=0; i<n; i++) {
        s.push_back(rand() % 101);
    }

    // 標本平均を求める
    double sum = 0;
    for (int i=0; i<n; i++) {
        sum += s[i];
    }
    double mean = sum / n;
    cout << "標本平均: " << mean << endl;

    // 標本分散を求める
    double variance = 0;
    for (int i = 0; i < n; i++) {
        variance += (s[i] - mean)*(s[i] - mean);
    }
    variance /= (n - 1);
    cout << "標本分散: " << variance << endl;

    // 最大値を求める
    int max_value = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] > max_value) {
            max_value = s[i];
        }
    }
    cout << "最大値: " << max_value << endl;

    // 最小値を求める
    int min_value = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] < min_value) {
            min_value = s[i];
        }
    }
    cout << "最小値: " << min_value << endl;

    // 最頻値を求める
    sort(s.begin(), s.end());
    int current_count = 1;
    int max_count = 0;
    vector<int> modes;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            current_count++;
        } else {
            if (current_count > max_count) {
                max_count = current_count;
                modes.clear();
                modes.push_back(s[i - 1]);
            } else if (current_count == max_count) {
                modes.push_back(s[i - 1]);
            }
            current_count = 1;
        }
    }
    if (current_count > max_count) {
        max_count = current_count;
        modes.clear();
        modes.push_back(s[n - 1]);
    } else if (current_count == max_count) {
        modes.push_back(s[n - 1]);
    }
    cout << "最頻値: ";
    for (int i = 0; i < modes.size(); i++) {
    cout << modes[i] << " ";
    }
    cout << endl;

    //中央値を求める
    double median;
    if (n % 2 == 1) {
        median = s[n / 2];
    } else {
        median = (s[n / 2 - 1] + s[n / 2]) / 2.0;
    }
    cout << "中央値: " << median << endl;

    return 0;
}
