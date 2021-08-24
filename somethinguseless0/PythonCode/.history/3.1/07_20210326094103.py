temp=input("输入年份，判断是否为闰年")
year=int(temp)

while(year/4==0):
    if(year/100==0)and(year/400==0):
        print(year+"为闰年")
    else if(year/100!=0)
