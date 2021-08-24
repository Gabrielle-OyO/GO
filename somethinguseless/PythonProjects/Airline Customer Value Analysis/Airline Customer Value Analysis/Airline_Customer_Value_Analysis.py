# -*- coding: utf-8 -*-

###############################################################################
#######################           任务实现             ########################
###############################################################################

# 代码 7-1

#库的导入
import numpy as np      
import pandas as pd

#数据预处理#

#导入航空客户数据
airline_data = pd.read_csv("C:\\Users\\18377\\Desktop\\百宝箱\\Python数据分析与应用\\第7章\\任务程序\\data\\air_data.csv",
                           encoding="gb18030") 
print('原始数据的形状为：',airline_data.shape)


#①
#去除票价为空的记录
exp1 = airline_data["SUM_YR_1"].notnull()
exp2 = airline_data["SUM_YR_2"].notnull()
exp = exp1 & exp2
airline_notnull = airline_data.loc[exp,:]
print('删除缺失记录后数据的形状为：',airline_notnull.shape)
#pandas的notnull函数，用于返回非空值的集合。
#loc函数：通过行索引 "Index" 中的具体值来取行数据（如取"Index"为"A"的行）
#iloc函数：通过行号来取行数据（如取第二行的数据）


#②
#只保留票价非零的，或者平均折扣率不为0且总飞行公里数大于0的记录。
index1 = airline_notnull['SUM_YR_1'] != 0
index2 = airline_notnull['SUM_YR_2'] != 0
index3 = (airline_notnull['SEG_KM_SUM']> 0) & \
    (airline_notnull['avg_discount'] != 0)  
airline = airline_notnull[(index1 | index2) & index3]
print('删除异常记录后数据的形状为：',airline.shape)



# 代码 7-2

#③
## 选取需求特征
airline_selection = airline[["FFP_DATE","LOAD_TIME","FLIGHT_COUNT","LAST_TO_END","avg_discount","SEG_KM_SUM"]]
#根据航空公司客户价值LRFMC模型，筛选确定认为有价值的数据类型


## 构建L特征

#观测窗口期的 月数L=结束时间-加入时间
L = pd.to_datetime(airline_selection["LOAD_TIME"]) - \
    pd.to_datetime(airline_selection["FFP_DATE"])
L = L.astype("str").str.split().str[0]
L = L.astype("int")/30
## 合并特征
airline_features = pd.concat([L,
    airline_selection.iloc[:,2:]],axis = 1)
print('构建的LRFMC特征前5行为：\n',airline_features.head())



# 代码 7-3
#3、标准化LRFMC模型的特征
from sklearn.preprocessing import StandardScaler
data = StandardScaler().fit_transform(airline_features)
np.savez('C:\\Users\\18377\\Desktop\\百宝箱\\Python数据分析与应用\\第7章\\任务程序\\tmp\\airline_scale.npz',data)
print('标准化后LRFMC五个特征为：\n',data[:5,:])


#代码 7-4
#4、客户价值分析K-Means聚类分析代码
import numpy as np
import pandas as pd
from sklearn.cluster import KMeans #导入kmeans算法
airline_scale = np.load('C:\\Users\\18377\\Desktop\\百宝箱\\Python数据分析与应用\\第7章\\任务程序\\tmp\\airline_scale.npz')['arr_0']


#构建模型

#有什么方法，不使用低版本python成功进行模型训练吗

k = 5 ## 确定聚类中心数
kmeans_model = KMeans(n_clusters = k,n_jobs=4,random_state=123)
fit_kmeans = kmeans_model.fit(airline_scale)   #模型训练
kk=kmeans_model.cluster_centers_ #查看聚类中
cc_exp = np.savetxt('C:\\Users\\18377\\Desktop\\百宝箱\\Python数据分析与应用\\第7章\\任务程序\\data\\cc.txt',kk,fmt="%.18e")
kmeans_model.cluster_centers_ #查看聚类中心

kmeans_model.labels_  #查看样本的类别标签

#统计不同类别样本的数目
r1 = pd.Series(kmeans_model.labels_).value_counts()
print('最终每个类别的数目为：\n',r1)


