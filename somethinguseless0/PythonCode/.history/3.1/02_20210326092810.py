######变量########
temp=input("猜数字")
guess=int(temp)

while guess!=8:
    if guess>8:
        print("大了")
    else:
        print("小了")

    temp=input("重来")
    guess=inp(temp)

print("猜对了")