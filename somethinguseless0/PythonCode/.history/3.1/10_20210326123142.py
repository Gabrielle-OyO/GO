# 计算π的值，可利用下列公式计算π的近似值，
# 直到最后一项的绝对值小于10-5为止。
# pi/4=1-1/3+1/5-1/7+1/9.....


# pi=0
# j=1
# while abs(j)<100000:
#     if j%4==1:
#         pi=pi+1/j
#     else:
#         pi=pi-1/j
#     j+=2
# else:
#     print(pi*4)


j = 1
while abs(j)<100000:
    j=j+2
    k=j
pi = 0
for i in range(1, k, 2):
    n=0
    p = pow(-1, n)*1/i
    pi = 4*(p+pi)
    i=i+2
    n=n+1
    
else:
    print(pi)




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
