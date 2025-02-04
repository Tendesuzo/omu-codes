#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <strings.h>

// 定数の定義
enum { BUFSIZE = 100, WORDLEN = 50 };
typedef char word[WORDLEN];

struct wordlist;
struct wordlist {
  word w;
  struct wordlist *next;
};
const struct wordlist initlist = {"", NULL};

typedef int (*compare_func)(const word, const word);
typedef struct wordlist (*sort_algorithm)(struct wordlist *, int, compare_func);

/**
 *  @brief 線形リストの単語を順に表示
 *  @param [in] words 表示したいリスト
 */
void printwords_list(struct wordlist *words) {
  struct wordlist *current;
  int i = 0;
  for (current = words->next; current; current = current->next) {
    printf("%s\n", current->w);
  }
}

/**
 *  @brief 線形リスト s1 を count の位置で分割し、残りの部分を戻り値とする。
 *  @param [in, out] s1 分割対象、count までの要素を切り取って返す
 *  @param count 分割後の s1 の要素数
 *  @return 分割されたリスト
 */

struct wordlist split_list(struct wordlist *s1, int count) {
    struct wordlist *current;
    current = s1;

    struct wordlist *split = (struct wordlist *)malloc(sizeof(struct wordlist));

    for (int i = 0; i < count; i++) {
      current = current->next;
    }

    if (s1 == NULL) {
        return initlist;
    }

    split->next = current->next;
    current->next = NULL;

    return *split;
}


/**
 *  @brief 2つのリストをマージ
 *  @param [in] s1 1つめのリスト
 *  @param [in] s2 2つめのリスト
 *  @param [in] func 比較関数
 *  @return マージされたリスト
 */
struct wordlist merge_list(struct wordlist *s1, struct wordlist *s2, compare_func func) {
    struct wordlist *first, *second, *result;
    struct wordlist *merge = (struct wordlist *)malloc(sizeof(struct wordlist));
    result = merge;

    first = s1;
    second = s2;

    first = first->next;
    second = second->next;

    while (first != NULL && second != NULL) {
      if (func(first->w, second->w) <= 0) {
        merge->next = first;
        first = first->next;
      } else {
        merge->next = second;
        second = second->next;
      }
      merge = merge->next;
    }

    while ((first != NULL && second == NULL) || (first == NULL && second != NULL)) {
      if (first== NULL) {
        merge->next = second;
        second = second->next;
    } else {
        merge->next = first;
          first = first->next;
    }
      merge = merge->next;
    }

    return *result;
}

/**
 *  @brief リストをマージソート
 *  @param [in] words マージソートをしたいリスト
 *  @param [in] count 要素数
 *  @param [in] func 比較関数
 *  @return マージソートされたリスト
 */
struct wordlist mergesort_list(struct wordlist *words, int count, compare_func func) {
  int split_count = count / 2;
  struct wordlist split, s1, s2;

  if (count == 1) {
    return *words;
  }

  split = split_list(words, split_count);
  s1 = mergesort_list(words, split_count, func);
  s2 = mergesort_list(&split, count - split_count, func);
  return merge_list(&s1, &s2, func);
}

/**
 *  @brief リストに単語を追加
 *  @param [in] words 単語を追加したいリスト
 *  @param [in] newword 追加したい単語
 *  @return 追加後のリスト
 */
struct wordlist addword_list(struct wordlist *words, const char *newword) {
  struct wordlist *p = (struct wordlist *)malloc(sizeof(struct wordlist));
  strncpy(p->w, newword, WORDLEN);
  p->next = words->next;
  words->next = p;
  return *words;
}

/**
 *  @brief リストを選択ソート
 *  @param [in] words 選択ソートをしたいリスト
 *  @param [in] count 要素数
 *  @param [in] func 比較関数
 *  @return 選択ソート後のリスト
 */

struct wordlist selectsort_list(struct wordlist *words, int count, compare_func func) {
    struct wordlist *i, *j, *target;
    word temp_word;

    if (words == NULL || count <= 1) {
        return *words;
    }

    for (i = words->next; i != NULL; i = i->next) {
        target = i;

        for (j = i->next; j != NULL; j = j->next) {
            if (func(j->w, target->w) < 0) {
                target = j;
            }
        }

        if (target != i) {
            strcpy(temp_word, i->w);
            strcpy(i->w, target->w);
            strcpy(target->w, temp_word);
        }
    }

    return *words;
}

/**
 *  @brief ファイルから1行ずつ文字列を取得
 *  @param [in] fp ファイル構造体
 *  @param [out] buf 取得した文字列
 *  @param [in] len 取得できる最大長
 *  @return 取得した文字列の長さ
 */
int fgetline(FILE *fp, char *buf, int len) {
  int pos = 0;
  int ch;

  while (((ch = fgetc(fp)) != EOF) && pos < len - 1) {
    if (ch == '\n') {
      break;
    }
    if (ch != '\r') {
      buf[pos++] = ch;
    }
  }
  buf[pos] = '\0';
  return pos;
}

int cmp_asc(const word a, const word b) { return strncmp(a, b, WORDLEN); }
int cmp_desc(const word a, const word b) { return -strncmp(a, b, WORDLEN); }


int cmp_ci_asc(const char *a, const char *b) {
    return strcasecmp(a, b);
}

int cmp_ci_desc(const char *a, const char *b) {
    return -strcasecmp(a, b);
}

int main(int argc, char *argv[]) {
  // ソートアルゴリズム、比較関数の一覧
  sort_algorithm algo[] = {selectsort_list, mergesort_list};
  compare_func comp[] = {cmp_asc, cmp_desc, cmp_ci_asc, cmp_ci_desc};

  if (argc < 3) {
    return -1;
  }

  // 前処理。プログラム引数からファイル名、ソートアルゴリズム、比較方法を設定
  // ちゃんとエラー処理はするべきだけど一部省略
  const char *filename = argv[1];
  int algo_num;
  if ((algo_num = strtol(argv[2], NULL, 10)) >
      (sizeof(algo) / sizeof(sort_algorithm))) {
    fprintf(stderr, "Invalid algorithm number: %d\n", algo_num);
    return -1;
  }
  int comp_num;
  if ((comp_num = strtol(argv[3], NULL, 10)) >
      (sizeof(comp) / sizeof(compare_func))) {
    fprintf(stderr, "Invalid compare number: %d\n", comp_num);
    return -1;
  }
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Cannot open file: %s\n", filename);
    return -1;
  }

  // 単語リストの作成。ファイルから単語を読み込んでリストに追加
  char buf[BUFSIZE];
  int len;
  int num_words = 0;
  struct wordlist words = initlist;
  while ((len = fgetline(fp, buf, BUFSIZE)) > 0) {
    words = addword_list(&words, buf);
    num_words++;
  }

  // ソート処理。指定したソートアルゴリズム、比較方法を用いてソート
  // ソートにかかる時間を計測
  clock_t start_time, end_time;
  double sec_clock;
  start_time = clock();
  words = algo[algo_num](&words, num_words, comp[comp_num]);
  end_time = clock();

  // 結果の表示。並び替え後の単語リストを表示し、ソートにかかった時間を表示
  printwords_list(&words);
  sec_clock = ((double)end_time - start_time) / CLOCKS_PER_SEC;
  printf("%f\n", sec_clock);
  printf("total words = %d\n", num_words);

  fclose(fp);
}
