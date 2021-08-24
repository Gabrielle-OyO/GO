######九九乘法表########

for i in range(1,10):
    for j in range(1,i+1):
        if(j==i):
            print("%d*%d=%d"%(i,j,i*j),end(\n))
        else:
            print("%d*%d=%d"%(i,j,i*j),end(\t))