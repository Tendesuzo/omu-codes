//AJG23005 中 天花

#include <iostream>
using namespace std;

int ans = 2951; //正解
int check_ans = ans;
int ans_v[4];
int guess = 0; //予想した数値を代入
int check_guess;
int guess_v[4];
int judge = 0; //0:不正解, 1:正解
int hit;
int blow;

int main() {
    while (judge == 0){
        cout << "予想する数字を入力してください：";
        cin >> guess; //入力を受け取る
        check_guess = guess;
        check_ans = ans;
        if (guess == ans) {
            judge = 1;
            cout << "正解です" << endl;
        }
        else {
            for (int i=0; i<4; i++) {
            ans_v[i] = check_ans % 10;
            check_ans /= 10;
            guess_v[i] = check_guess % 10;
            check_guess /= 10;
            }
            hit = 0;
            blow = 0;
            for (int i=0; i<4; i++) {
                if (ans_v[i] == guess_v[i]) {
                    hit++;
                }
                else {
                    for (int j=0; j<4; j++) {
                        if (ans_v[i] == guess_v[j]) {
                            blow++;
                            break;
                        }
                    }
                }
            }
            cout << "ヒット数: " << hit << " " << "ブロー数: " << blow << endl;
        }

    }
}
