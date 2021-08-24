
#导入库、加载数据
import pandas as pd
import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
from  sklearn.preprocessing import  MinMaxScaler,OneHotEncoder
from sklearn.metrics import silhouette_score  # 导入轮廓系数指标
from sklearn.cluster import KMeans  # KMeans模块

#%matplotlib inline
plt.show()
## 设置属性防止中文乱码
mpl.rcParams['font.sans-serif'] = [u'SimHei']
mpl.rcParams['axes.unicode_minus'] = False

#读取数据
raw_data = pd.read_table('../ad_performance.txt', delimiter='\t')
raw_data.head()