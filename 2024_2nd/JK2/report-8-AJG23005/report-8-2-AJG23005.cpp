//AJG23005 中 天花
//講義や課題に関するコメント
//数当てゲームのように、ゲーム形式になっている課題の方がプログラミングをしていて楽しいと感じた。

#include <iostream>
using namespace std;

int ans;
int square;
int token = 0;
int digit[9];

int main(){
    for (int i=10000; i<40000; i++) {
        ans = i * i;
        square = ans;
        if (99999999 < square && square < 1000000000) {
            for (int j=0; j<9; j++) {
                digit[j] = square % 10;
                square /= 10;
            }
            token = 0;
            for (int j=0; j<9; j++) {
                if (digit[j] == 0){
                    token = 1;
                    break;
                }
            }
            for (int j=0; j<9; j++) {
                for (int k=j+1; k<9; k++) {
                    if (digit[j] == digit[k]) {
                        token = 1;
                        break;
                    }
                }
                if (token == 1) {
                    break;
                }
            }
            if (token == 0) {
                cout << "自乗した数: " << i << endl;
                cout << "小町数: " << ans << endl;
                cout << endl;
            }
            token = 0;
        }
    }
    return 0;
}
