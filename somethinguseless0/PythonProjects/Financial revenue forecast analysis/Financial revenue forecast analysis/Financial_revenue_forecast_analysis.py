# -*- coding: utf-8 -*-

###############################################################################
#######################           任务实现             #######################
###############################################################################


#-*- coding: utf-8 -*-

def GM11(x0): #自定义灰色预测函数
  import numpy as np
  x1 = x0.cumsum() #1-AGO序列
  z1 = (x1[:len(x1)-1] + x1[1:])/2.0 #紧邻均值（MEAN）生成序列
  z1 = z1.reshape((len(z1),1))
  B = np.append(-z1, np.ones_like(z1), axis = 1)
  Yn = x0[1:].reshape((len(x0)-1, 1))
  [[a],[b]] = np.dot(np.dot(np.linalg.inv(np.dot(B.T, B)), B.T), Yn) #计算参数
  f = lambda k: (x0[0]-b/a)*np.exp(-a*(k-1))-(x0[0]-b/a)*np.exp(-a*(k-2)) #还原值
  delta = np.abs(x0 - np.array([f(i) for i in range(1,len(x0)+1)]))
  C = delta.std()/x0.std()
  P = 1.0*(np.abs(delta - delta.mean()) < 0.6745*x0.std()).sum()/len(x0)
  return f, a, b, x0[0], C, P #返回灰色预测函数、a、b、首项、方差比、小残差概率






# 代码 8-1     求解Pearson相关系数（求取企业所得随各特征间的相关系数
import numpy as np
import pandas as pd
inputfile = 'C:\\Users\\18377\\Desktop\\百宝箱\\Python数据分析与应用\\第8章\\任务程序\\data\\data.csv' ## 输入的数据文件
data = pd.read_csv(inputfile) ## 读取数据
## 输出Pearson相关系数，并保留两位小数
print('相关系数矩阵为：',np.round(data.corr(method = 'pearson'), 2))



# 代码 8-2      使用Lasso回归进行特征选取
import numpy as np
import pandas as pd
from sklearn.linear_model import Lasso
inputfile = 'C:/Users/18377/Desktop/百宝箱/Python数据分析与应用/第8章/任务程序/data/data.csv' #输入的数据文件
data = pd.read_csv(inputfile) #读取数据
lasso = Lasso(1000)  #调用Lasso()函数，设置λ的值为1000
lasso.fit(data.iloc[:,0:13],data['y'])
print('相关系数为：',np.round(lasso.coef_,5))  #输出结果，保留五位小数

## 计算相关系数非零的个数
print('相关系数非零个数为：',np.sum(lasso.coef_ != 0))

mask = lasso.coef_ != 0  #返回一个相关系数是否为零的布尔数组
print('相关系数是否为零：',mask)

outputfile = '‪C:/Users/18377/Desktop/百宝箱/Python数据分析与应用/第8章/任务程序/tmp/new_reg_data.csv'  #输出的数据文件
new_reg_data = data.iloc[:, mask,True]  #返回相关系数非零的数据
mask = np.append(mask,True)
new_reg_data.to_csv(outputfile)  #存储数据
print('输出数据的维度为：',new_reg_data.shape)  #查看输出数据的维度


# 代码 8-3       使用灰色预测和SVR构建财政收入预测模型
import numpy as np
import pandas as pd
from GM11 import GM11 ## 引入自编的灰色预测函数
inputfile = '‪C:/Users/18377/Desktop/百宝箱/Python数据分析与应用/第8章/任务程序/tmp/new_reg_data.csv' ##输入的数据文件
inputfile1 = 'C:/Users/18377/Desktop/百宝箱/Python数据分析与应用/第8章/任务程序/data/data.csv' ## 输入的数据文件
new_reg_data = pd.read_csv(inputfile) ## 读取经过特征选择后的数据
data = pd.read_csv(inputfile1) ##读取总的数据
new_reg_data.index = range(1994, 2014)
new_reg_data.loc[2014] = None
new_reg_data.loc[2015] = None
l = ['x1', 'x3', 'x4', 'x5', 'x6', 'x7', 'x8', 'x13']
for i in l:
  f = GM11(new_reg_data.loc[range(1994, 2014),i].as_matrix())[0]
  new_reg_data.loc[2014,i] = f(len(new_reg_data)-1)#2014年预测结果
  new_reg_data.loc[2015,i] = f(len(new_reg_data)) ##2015年预测结果
  new_reg_data[i] = new_reg_data[i].round(2) ## 保留两位小数
outputfile = '‪C:\\Users\\18377\\Desktop\\百宝箱\\Python数据分析与应用\\第8章\\任务程序\\tmp\\new_reg_data_GM11.xls' ## 灰色预测后保存的路径
y = list(data['y'].values) ## 提取财政收入列，合并至新数据框中
y.extend([np.nan,np.nan])
new_reg_data['y'] = y
new_reg_data.to_excel(outputfile) ## 结果输出
print('预测结果为：',new_reg_data.loc[2014:2015,:]) ##预测结果展示



# 代码 8-4   财政收入灰色预测
import pandas as pd
import numpy as np
from sklearn.svm import LinearSVR
import matplotlib.pyplot as plt
from sklearn.metrics import explained_variance_score,\
mean_absolute_error,mean_squared_error,\
median_absolute_error,r2_score
inputfile = '‪C:\\Users\\18377\\Desktop\\百宝箱\\Python数据分析与应用\\第8章\\任务程序\\tmp\\new_reg_data_GM11.xls' #灰色预测后保存的路径
data = pd.read_excel(inputfile) #读取数据
feature = ['x1', 'x3', 'x4', 'x5', 'x6', 'x7', 'x8', 'x13'] 
data_train = data.loc[range(1994,2014)].copy()#取2014年前的数据建模
data_mean = data_train.mean()
data_std = data_train.std()
data_train = (data_train - data_mean)/data_std #数据标准化
x_train = data_train[feature].as_matrix() #特征数据
y_train = data_train['y'].as_matrix() #标签数据
linearsvr = LinearSVR()   #调用LinearSVR()函数
linearsvr.fit(x_train,y_train)
x = ((data[feature] - data_mean[feature])/ \
data_std[feature]).as_matrix()  #预测，并还原结果。
data[u'y_pred'] = linearsvr.predict(x) * \
data_std['y'] + data_mean['y']
## SVR预测后保存的结果
outputfile = '‪C:\\Users\\18377\\Desktop\\百宝箱\\Python数据分析与应用\\第8章\\任务程序\\tmp\\new_reg_data_GM11_revenue.xls'
data.to_excel(outputfile)
print('真实值与预测值分别为：',data[['y','y_pred']])

print('预测图为：',data[['y','y_pred']].plot(subplots = True,
      style=['b-o','r-*']))


