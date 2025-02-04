import matplotlib.pyplot as plt
import numpy as np

# サンプルデータ（単語数とそれに対応する処理時間のリスト）
word_counts = [10, 100, 1000, 2000, 4000, 6000, 8000, 10000]
select_sort = [0.0000058, 0.0000782, 0.0049882, 0.0174722, 0.0466084, 0.087749, 0.1394548, 0.201427]  # アルゴリズム1の処理時間
merge_sort = [0.0000054, 0.0000426, 0.0004798, 0.0010606, 0.0023586, 0.00337475, 0.0037108, 0.0049158]  # アルゴリズム2の処理時間

# 散布図を作成
plt.figure(figsize=(10, 6))
plt.scatter(word_counts, select_sort, color='blue', label='select sort')
plt.scatter(word_counts, merge_sort, color='red', label='merge sort')

# 軸ラベルとタイトル
plt.xlabel('Number of Words')
plt.ylabel('Sort Time (seconds)')
plt.title('Number of Words vs Sort Time')
plt.legend()

# グラフを表示
plt.grid(True, which="both", ls="--")
plt.show()
