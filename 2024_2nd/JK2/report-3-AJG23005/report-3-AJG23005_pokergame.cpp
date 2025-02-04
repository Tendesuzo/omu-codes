//AJG23005 中 天花

#include <iostream>
#include "report-3-AJG23005_pokergame.h"
using namespace std;

PokerGame::PokerGame(int _possession_money, int _max_money, int _betting_money) : Poker(){
    possession_money = _possession_money;
    max_money = _max_money;
    betting_money = _betting_money;
}

void PokerGame::possession_money_setting(int _possession_money){
        possession_money = _possession_money;
}

int PokerGame::get_current_possession_money(){
    return possession_money;
}

void PokerGame::max_money_setting(int _max_money){
        max_money = _max_money;
}

void PokerGame::betting_money_setting(int _betting_money){
        betting_money = _betting_money;
}

int PokerGame::calculate_initial_possession_money(int possession_money, int betting_money){
        return possession_money - betting_money;
}

void PokerGame::draw_cards(){
    for(int i=0; i<52; i++){
        cards[i] = i;
    }
    srand((unsigned int)time(NULL));

    for(int i=0; i<10; i++){
        int j = rand() % 52;
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }

    for(int i=0; i<10; i++){
        mark[i] = cards[i]/13;
        number[i] = cards[i]%13 + 1;
    }

    for (int i=0; i<10; i++){
    switch(mark[i]){
        case 0: mark_char[i] = 'S'; break;
        case 1: mark_char[i] = 'H'; break;
        case 2: mark_char[i] = 'D'; break;
        case 3: mark_char[i] = 'C'; break;
    }
    }

    for (int i = 0; i < 5; i++) {
    printf("-%d-  ", (i+1));
    }
    printf("\n");

    for (int i = 0; i < 5; i++) {
    printf("%c", mark_char[i]);
    printf("%2d  ", number[i]);
    }
    printf("\n");
}

void PokerGame::change_cards() {
    for(int i=0; i<5; i++){
        cout << i+1 << "番目のカードを交換しますか？ (0:交換する 1:交換しない)" << endl;
        cin >> change[i];
        if(change[i] == 0){
            cards[i] = cards[i+5];
        }
        mark[i] = cards[i]/13;
        number[i] = cards[i]%13 + 1;
        switch(mark[i]){
        case 0: mark_char[i] = 'S'; break;
        case 1: mark_char[i] = 'H'; break;
        case 2: mark_char[i] = 'D'; break;
        case 3: mark_char[i] = 'C'; break;
        }
    }

    for (int i = 0; i < 5; i++) {
    printf("-%d-  ", (i+1));
    }

    printf("\n");

    for (int i = 0; i < 5; i++) {
    printf("%c", mark_char[i]);
    printf("%2d  ", number[i]);
    }

    printf("\n");
}

int PokerGame::flush() { // フラッシュ判定 return 1:フラッシュ return 0:フラッシュでない

  for (int i = 1; i < 5; i++) {
    if (mark[0] != mark[i]) { // 1枚でもマークが違えばフラッシュでない
      return 0;
    }
  }

  // マークが違うカードが1枚も無ければフラッシュ
  return 1;
}

int PokerGame::straight() { // ストレート判定 return 1:ストレート return 0:ストレートでない

  if (number[0] == 1 && number[1] == 10 && number[2] == 11
      && number[3] == 12 && number[4] == 13) { // 数字が連続しないパターンを先に判定
    return 1;
  }

  for (int i = 0; i < 4; i++) {
    if (number[i] + 1 != number[i+1]) { // 1つでも数字が連続しなければストレートでない
      return 0;
    }
  }

  return 1;
}

int PokerGame::pair() { // 同一数字に関係するハンドを判定
  // return 1:ワンペア 2:ツーペア 3:スリーカード 4:フルハウス 5:フォーカード 0:該当なし

  // 5:フォーカード
  for (int i = 0; i < 2; i++) {
    // 数字がソートされているためnumber[0]またはnumber[4]のみの数字が異なる
    if (number[i] == number[i+3]) {
      return 5;
    }
  }

  // 4:フルハウス
  if (number[0] == number[2] && number[3] == number[4]
      || number[0] == number[1] && number[2] == number[4]) {

    return 4;
  }

  // 3:スリーカード
  for (int i = 0; i < 3; i++) {
    if (number[i] == number[i+2]) {
      return 3;
    }
  }

  // 2:ツーペア
  for (int i = 0; i < 2; i++) {
    if (number[i] == number[i + 1]) {
      for (int j = i + 2; j < 4; j++) {
        if (number[j] == number[j + 1]) {
          return 2;
        }
      }
    }
  }

  // 1:ワンペア
  for (int i = 0; i < 4; i++) {
    if (number[i] == number[i+1]) {

    // 6: 新しいハンド Jacks or Better (J以上のワンペア)
    if (number[i] >= 11) {
      return 6;
    } else {

      // ワンペア
      return 1;
    }
    }
  }

  return 0;
} // int pair()

int PokerGame::decision() { // ハンドを判定

  int decision1, decision2, tmp;

  // 数が小さい順に並べ替え
  for (int i = 0; i < 5; i++) {
    for (int j = i+1; j < 5; j++) {
      if(number[i] > number[j]) {
        tmp = number[i];
        number[i] = number[j];
        number[j] = tmp;
      }
    }
  }

  decision1 = flush();
  decision2 = straight();

  if (decision1 == 1 && decision2 == 1) {
  // 数字がソートされているため最小1その次最小10で該当
    if (number[0] == 1 && number[1] == 10) {
      printf("ロイヤルストレートフラッシュ\n");
      return 10;

    } else {
      printf("ストレートフラッシュ\n");
      return 9;
    }
  } else if (decision1 == 1) {
    printf("フラッシュ\n");
    return 6;

  } else if (decision2 == 1) {
    printf("ストレート\n");
    return 5;
  }

  decision1 = pair();

  if (decision1 == 5) {
    printf("フォーカード\n");
    return 8;
  } else if (decision1 == 4) {
    printf("フルハウス\n");
    return 7;
  } else if (decision1 == 3) {
    printf("スリーカード\n");
    return 4;
  } else if (decision1 == 2) {
    printf("ツーペア\n");
    return 3;
  } else if (decision1 == 1) {
    printf("ワンペア\n");
    return 1;
  } else if (decision1 == 6) {
    printf("Jacks or Better\n");
    return 2;
  } else if (decision1 == 0) {
    printf("残念でした…\n");
  }

  return 0;
} // int decision()


int PokerGame::calculate_refund_money(int hand){
    int refund_money = betting_money;
    switch(hand){
        case 0: refund_money *= 0; break;
        case 1: refund_money *= 1.3; break;
        case 2: refund_money *= 2.0; break;
        case 3: refund_money *= 1.3; break;
        case 4: refund_money *= 1.4; break;
        case 5: refund_money *= 1.5; break;
        case 6: refund_money *= 1.6; break;
        case 7: refund_money *= 1.7; break;
        case 8: refund_money *= 1.8; break;
        case 9: refund_money *= 1.9; break;
        case 10: refund_money *= 2.0; break;
    }
    return refund_money;
}

int PokerGame::update_possession_money(int possession_money, int refund){
    return possession_money = possession_money + refund;
    cout << possession_money << " " << refund << endl;
}
