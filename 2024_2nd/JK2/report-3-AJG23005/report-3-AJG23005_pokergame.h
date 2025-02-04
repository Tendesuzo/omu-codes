//AJG23005 中 天花

#include "report-3_poker.h"
class PokerGame : public Poker {
    private:
    int possession_money; //所持金
    int max_money; //所持金の最大金額
    int betting_money; //かけ金
    int cards[52]; //カードを格納する配列
    int mark[10]; //カードのマークを格納する配列
    char mark_char[10]; //カードのマークを文字で格納する配列
    int number[10]; //カードの番号を格納する配列
    int change[10]; //カードを交換するかどうかを記憶させる配列 0:交換する 1:交換しない
    int hand; //勝ち手
    int escape; //whileループを抜けるかどうかを決定 0:抜ける 1:抜けない

    public:
    PokerGame(int possession_money, int max_money, int betting_money); //コンストラクタ

    void possession_money_setting(int possession_money); //所持金を設定

    int get_current_possession_money(); // 所持金を取得

    void max_money_setting(int max_money); // 所持金の上限を設定

    void betting_money_setting(int betting_money); // かけ金を設定

    int calculate_initial_possession_money(int possession_money, int betting_money); //ゲーム開始時の所持金を計算

    void draw_cards(); // 5枚のカードを乱数を用いて自動で引く関数

    void change_cards(); //カードを交換するかどうかを決めて、その操作を行う

    int flush(); // フラッシュ判定

    int straight(); // ストレート判定

    int pair(); // 同一数字に関するハンドを判定

    int decision(); // ハンドを判定

    int calculate_refund_money(int hand);  //払い戻し金額を計算

    int update_possession_money(int possession_money, int refund); // 所持金を更新
};
