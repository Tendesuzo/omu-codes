//AJG23005 中 天花

#include <iostream>
#include "report-3-AJG23005_pokergame.h"
using namespace std;

int main() {
    //コンストラクタ
    Poker poker;
    PokerGame game(0,0,0);

    //所持金を設定する
    cout << "最初の所持金を設定してください" << endl;
    int possession_money;
    cin >> possession_money;
    game.possession_money_setting(possession_money);

    //最大金額を設定する
    cout << "最大金額を設定してください" << endl;
    int max_money;
    cin >> max_money;
    game.max_money_setting(max_money);

    //ゲーム終了までループ
    while (possession_money > 0 && possession_money <= max_money) {
         //賭け金を設定する
        cout << "賭け金を設定してください" << endl;
        int betting_money;
        cin >> betting_money;
        game.betting_money_setting(betting_money);

        //デバック用
        cout << "所持金：" << possession_money << endl;
        cout << "賭け金：" << betting_money << endl;

        //ゲーム開始時の所持金を計算
        possession_money = game.calculate_initial_possession_money(possession_money, betting_money);

        //デバック用
        cout << "ゲーム開始時の所持金：" << possession_money << endl;

        //カードを引く
        game.draw_cards();

        //カードを交換するかどうかを決めて、その操作を行う
        game.change_cards();

        //ハンドを判定
        int hand = game.decision();

        //払い戻し金を計算
        int refund = game.calculate_refund_money(hand);

        //所持金を更新
        possession_money = game.update_possession_money(possession_money, refund);

        //払い戻し金と現在の所持金を表示
        cout << "払い戻し金："  << refund << endl;
        cout << "現在の所持金: " << possession_money << endl;
    }

    //ゲーム終了メッセージ
    cout << "ゲームを終了します" << endl;

    return 0;
}
