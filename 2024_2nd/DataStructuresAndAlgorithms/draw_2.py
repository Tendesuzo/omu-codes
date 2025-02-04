# import matplotlib.pyplot as plt
# import numpy as np

# # サンプルデータ（単語数とそれに対応する処理時間のリスト）
# word_counts = np.array([10, 100, 1000, 2000, 4000, 6000, 8000, 10000])
# select_sort = np.array([0.0000058, 0.0000782, 0.0049882, 0.0174722, 0.0466084, 0.087749, 0.1394548, 0.201427])

# # 処理時間を N^2 に対してプロット
# plt.figure(figsize=(10, 6))
# plt.scatter(word_counts ** 2, select_sort, color='blue', label='Select Sort')

# # 軸ラベルとタイトル
# plt.xlabel('N^2 (Number of Words squared)')
# plt.ylabel('Sort Time (seconds)')
# plt.title('Sort Time vs N^2')
# plt.legend()

# # グラフを表示
# plt.grid(True, which="both", ls="--")
# plt.show()

import matplotlib.pyplot as plt
import numpy as np

# サンプルデータ（単語数とそれに対応する処理時間のリスト）
word_counts = np.array([10, 100, 1000, 2000, 4000, 6000, 8000, 10000])
select_sort = np.array([0.0000058, 0.0000782, 0.0049882, 0.0174722, 0.0466084, 0.087749, 0.1394548, 0.201427])

# N^2に対する処理時間
word_counts_squared = word_counts ** 2

# 線形回帰を適用
coefficients = np.polyfit(word_counts_squared, select_sort, 1)
polynomial = np.poly1d(coefficients)

# 散布図を作成
plt.figure(figsize=(10, 6))
plt.scatter(word_counts_squared, select_sort, color='blue', label='Select Sort')

# 近似直線を描く
plt.plot(word_counts_squared, polynomial(word_counts_squared), color='red', label='Fit Line')

# 軸ラベルとタイトル
plt.xlabel('N^2 (Number of Words squared)')
plt.ylabel('Sort Time (seconds)')
plt.title('Sort Time vs N^2 with Fit Line')
plt.legend()

# グラフを表示
plt.grid(True, which="both", ls="--")
plt.show()
