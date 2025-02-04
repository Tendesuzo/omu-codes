import random

count_1 = 0
count_2 = 0
count_3 = 0
count_4 = 0
count_5 = 0
count_6 = 0

for i in range(1, 10000):
    dice_roll = random.randint(1, 6)
    if dice_roll == 1:
        count_1 += 1
    elif dice_roll == 2:
        count_2 += 1
    elif dice_roll == 3:
        count_3 += 1
    elif dice_roll == 4:
        count_4 += 1
    elif dice_roll == 5:
        count_5 += 1
    else:
        count_6 += 1

count_1_rate = count_1/10000*100
count_2_rate = count_2/10000*100
count_3_rate = count_3/10000*100
count_4_rate = count_4/10000*100
count_5_rate = count_5/10000*100
count_6_rate = count_6/10000*100

print("1:" + str(count_1) + "回" + str(count_1_rate) + "%")
print("2:" + str(count_2) + "回" + str(count_2_rate) + "%")
print("3:" + str(count_3) + "回" + str(count_3_rate) + "%")
print("4:" + str(count_4) + "回" + str(count_4_rate) + "%")
print("5:" + str(count_5) + "回" + str(count_5_rate) + "%")
print("6:" + str(count_6) + "回" + str(count_6_rate) + "%")
