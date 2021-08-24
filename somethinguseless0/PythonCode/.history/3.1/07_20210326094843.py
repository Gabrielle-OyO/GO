print("输入年份，判断是否为闰年")
temp=input()
year=int(temp)

if(year/4==0):
    if(year/100==0)and(year/400==0):
        print(str(year)+"为闰年")
    elif(year/100!=0):
        print(str(year)+"为闰年")
else:
    print(str(year)+"不是闰年")
