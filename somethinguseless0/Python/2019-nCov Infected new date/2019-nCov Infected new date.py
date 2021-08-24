# -*- coding: utf-8 -*-
"""
Created on Sun Jan 10 15:20:58 2021

@author: 18377
"""

# ===============================
# 新型冠状病毒肺炎疫情新闻数据的评分系统
# ===============================
# 一、获取网页源代码
# 1.引入所需库
import requests
import re
import time
import csv
# 2.请求头
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.100 Safari/537.36'}
# 3.需要挖取新闻数据的机场
companys = ['中国肺炎疫情实时动态','石家庄肺炎疫情实时动态',
            '河北肺炎疫情实时动态','浙江肺炎疫情实时动态',
            '上海肺炎疫情实时动态','北京肺炎疫情实时动态']
# 4.建立挖取某机场新闻的函数，获得该网页的源代码
def baidu(i,company):
    num = (i-1)*10
    url = 'https://www.baidu.com/s?tn=news&rtt=4&bsst=1&cl=2&wd=' + company + '&medium=0&x_bfe_rqs=03E80&tngroupname=organic_news&newVideo=12&rsv_dl=news_b_pn&pn=' + str(num)
    res = requests.get(url, headers=headers).text

# 二、提取信息并清洗数据
# 1.提取源代码中所需的网址、标题、新闻来源和发布日期的正则表达式
    p_href = '<h3 class="news-title_1YtI1"><a href="(.*?)"'
    href = re.findall(p_href, res, re.S)
    p_title = '<h3 class="news-title_1YtI1"><.*?>(.*?)<!--/s-text--></a></h3>'
    title = re.findall(p_title, res, re.S)
    p_date = '<span class="c-color-gray2 c-font-normal">(.*?)</span>'
    date = re.findall(p_date, res, re.S)
    p_source = '<span class="c-color-gray c-font-normal c-gap-right">(.*?)</span>'
    source = re.findall(p_source, res, re.S)

# 2.清洗标题及发布日期中的干扰信息
    for i in range(len(href)):
        title[i] = title[i].strip()
        title[i] = re.sub('<.*?>', '', title[i])
        date[i] = date[i].split(' ')[0]
        date[i] = re.sub('年', '-', date[i])
        date[i] = re.sub('月', '-', date[i])
        date[i] = re.sub('日', '', date[i])
        if ('小时' in date[i]) or ('分钟' in date[i]):
            date[i] = time.strftime("%Y-%m-%d")
        else:
            date[i] = date[i]


# 三、对新闻标题和新闻正文进行评分
    score = []
    keywords1 = ['疫情', '肺炎', '增加', '病例', '感染', '例', '恢复', '实时', '宣布', '状态', '防控']
    keywords2 = ['确诊', '感染者', '无症状', '阻碍', '接触']
    for i in range(len(title)):
        num = 0
        # 1.获取新闻正文
        try:
            article = requests.get(href[i], headers=headers, timeout=10).text
        except:
            article = '新闻爬取失败'
        # 2.解决新闻正文中可能出现的乱码问题
        try:
            article = article.encode('ISO-8859-1').decode('utf-8')  # 解码为UTF-8
        except:
            try:
                article = article.encode('ISO-8859-1').decode('gbk')  # 解码为GBK
            except:
                article = article  # 保持本身的编码
        # 3.筛选新闻正文中真正的正文内容，忽略旁边的滚动新闻的内容
        p_article = '<p>(.*?)</p>'
        article_main = re.findall(p_article, article)  # 获取<p>标签里的正文信息，结果是一个列表
        article = ''.join(article_main)  # 将列表转换成为字符串
        for k in keywords1:
            if (k in article) or (k in title[i]):
                num += 5
        score.append(num)
        
        for L in keywords2:
            if (L in article) or (L in title[i]):
                num -= 5
        score.append(num)
        

# 1. 创建文件对象
    f = open('2019-nCov.csv','a',encoding='utf-8')

# 2. 基于文件对象构建 csv写入对象
    csv_writer = csv.writer(f)

# 3. 构建列表头
    csv_writer.writerow(["地区","标题","网址","来源","日期","对新闻标题和内容评分"])
    for i in range(len(title)):
            csv_writer.writerow([company, title[i], href[i], source[i], date[i], score[i]])
    print("yes")
# 5. 关闭文件
#    f.close()

#    l=open('2019-nCov.doc','a',encoding='utf-8')
#    csv_writer=csv.writer(l)
#    csv_writer.writerow([article])
#    print("ok!")

# 四、将数据存入MySQL数据库
#    for i in range(len(title)):
#        db = pymysql.connect(host='localhost', port=3306, user='root', password='180609lz', database='pachong', charset='utf8')
#        cur = db.cursor()
#        sql = 'INSERT INTO article(company,title,href,source,date,score) VALUES (%s,%s,%s,%s,%s,%s)'
#        cur.execute(sql, (company, title[i], href[i], source[i], date[i], score[i]))
#        db.commit()
#
#        cur.close()
 #       db.close()

# 五、批量爬取7个机场每个机场5页共35页百度网的数据并存入MySQL数据库
for company in companys:
   for i in range(5):
       baidu(i, company)
       print(company + '第' + str(i+1) + "页爬取成功")
