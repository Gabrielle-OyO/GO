import tushare as ts
import pandas as pd
ts.set_token('4c562465125a1b5822095898168cd21a8870bac2dbbee0ed24fce68f')  # 输入token码
# 初始化pro接口
pro = ts.pro_api()
pro = ts.pro_api('4c562465125a1b5822095898168cd21a8870bac2dbbee0ed24fce68f')  # 如果上一步骤ts.set_token('your token')无效或不想保存token到本地，也可以在初始化接口里直接设置token
# 一、获取交易日历信息
df = pro.trade_cal(exchange='', start_date='20200102', end_date='20200913', fields='exchange,cal_date,is_open,pretrade_date', is_open='0')
pd.set_option('display.max_columns', None)  # 显示DataFrame所有列
print(df)

# 二、获取当前所有正常上市交易的股票列表
import tushare as ts
pro = ts.pro_api()
data = pro.stock_basic(exchange='', list_status='L', fields='ts_code,symbol,name,area,industry,list_date')
print(data)

# 三、获取上市公司基础信息
import tushare as ts
pro = ts.pro_api()
df = pro.stock_company(exchange='SZSE', fields='ts_code,chairman,manager,secretary,reg_capital,setup_date,province')
print(df)

# 四、获取上市公司高管数据
#import tushare as ts
#pro = ts.pro_api()
#df1 = pro.stk_managers(ts_code='000001.SZ')  # 获取单个公司高管全部数据
#df2 = pro.stk_managers(ts_code='000001.SZ,600000.SH')  # 获取多个公司高管全部数据
#print(df1)
#print(df2)

# 五、上证行情数据
#import tushare as ts
#pro = ts.pro_api()
#df = ts.pro_bar(ts_code='000004.SH', asset='I', start_date='20200101', end_date='20200911')
#df.head()

# 六、均线数据
#import tushare as ts
#pro = ts.pro_api()
#df = ts.pro_bar(ts_code='000001.SZ', start_date='20200101', end_date='20200911', ma=[5, 20, 50])
#df.head()

# 七、换手率数据
#import tushare as ts
#pro = ts.pro_api()
#df = ts.pro_bar(ts_code='000001.SZ', start_date='20180101', end_date='20181011', factors=['tor', 'vr'])
#df.head()

# 八、行情数据
import tushare as ts
pro = ts.pro_api()
# 1.日线数据
df1 = pro.daily(ts_code='002547', start_date='20200701', end_date='20200912')
print(df1)
#限售股解禁
df2 = pro.share_float(ts_code='000001.SZ', start_date='20200701', end_date='20200718',ann_date="20200701",float_date="20200701")
print(df2)


# 2.周线数据
#df2 = pro.weekly(ts_code='000004.SZ', start_date='20200101', end_date='20200901', fields='ts_code,trade_date,open,high,low,close,vol,amount')
# 3.月线数据
#df3 = pro.monthly(ts_code='000004.SZ', start_date='20200101', end_date='20200901', fields='ts_code,trade_date,open,high,low,close,vol,amount')
# 4.获取每日涨跌停股票统计
# 4.1 获取单日统计数据
#df4 = pro.limit_list(trade_date='20190925')
# 4.2 获取某日涨停股票，并指定字段输出
#df5 = pro.limit_list(trade_date='20190925', limit_type='U', fields='ts_code,close,first_time,last_time')
# 4.3 获取时间段统计信息
#df6 = pro.limit_list(start_date='20190920', end_date='20190925')

# 九、财务指标数据
#import tushare as ts
#pro = ts.pro_api()
#df = pro.fina_indicator(ts_code='600004.SH')
#pd.set_option('display.max_columns', None)  # 显示DataFrame所有列
#print(df)
