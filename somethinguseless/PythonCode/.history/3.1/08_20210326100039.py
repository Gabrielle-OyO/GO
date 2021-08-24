######九九乘法表########

for i in range(1,9):
    for j in range(1,i+1):
        if(j==i):
            print("%d*%d=%d"%(i,j,i*j),str("\n"))