# 计算π的值，可利用下列公式计算π的近似值，
# 直到最后一项的绝对值小于10-5为止。
# pi/4=1-1/3+1/5-1/7+1/9.....

# pi=0
# i=0
# j=1
# b=1
# while(abs(pi)>1e-6):
#     i+=2
#     pi=pi+j
#     b=-b
#     j=b/i
# pi=4*pi
# print(pi)

# pi=0
# j=1
# while abs(pi)<10:
#     if j%4==1:
#         pi=pi+1/j
#     else:
#         pi=pi-1/j
#     j+=2
# else:
#     print(pi*4)