#!/usr/bin/python3
# -*- coding: UTF-8 -*-

import pymysql
import re
import urllib.request
import urllib
import json
import sys
import importlib
import json


response = urllib.request.urlopen('https://baike.baidu.com/item/%E5%9B%BD%E5%AE%B6%E4%B8%80%E7%BA%A7%E5%8D%9A%E7%89%A9%E9%A6%86')

result = response.read().decode('utf-8')
#print(result)

matchObj = re.findall(r'(<td)(.*?)(">)(?P<name>\S*)(博物馆|博物院|技术馆|纪念馆|陈列馆|博物总馆|汉画馆|研究院)(.*?)(</td|</a)', result)
i = 1
for museum in matchObj:
	print(i, museum[3]+museum[4])
	url = "http://api.map.baidu.com/place/v2/search?"
	data={}
	data['query'] = museum[3]+museum[4]
	data['region'] = '中国'
	data['output'] = 'json'
	data['ak'] = 'RLG3lvrSWPQPc6cnDkH3BtOezfeNSjeR'
	url_parame=urllib.parse.urlencode(data)
	url=url+url_parame
	response = urllib.request.urlopen(url)
#	response = response.read()
#	print(response)
	data = json.load(response)
	print(response.status, response.reason)  
	if data['results'] and 'location' in data['results'][0].keys():
		print(data['results'][0]['name'],data['results'][0]['location']['lat'],data['results'][0]['location']['lng'])
	else:
		print('没有此博物馆信息')
	i+=1



# 打开数据库连接
db = pymysql.connect("localhost", "root", "", "museumtest", charset='utf8')

# 使用 cursor() 方法创建一个游标对象 cursor
cursor = db.cursor()
sql = "SELECT * FROM museum"
cursor.execute(sql)
try:
	# 执行SQL语句
	cursor.execute(sql)
	# 获取所有记录列表
	results = cursor.fetchall()
	for row in results:
		id = row[0]
		name = row[1]
		introduce = row[2]
		open_time = row[3]
		edu_activity = row[4]
		collection = row[5]
		academic = row[6]
		lng = row[7]
		lat = row[8]
		# 打印结果
		print ("id=%s, name=%s" % (id, name))
except:
	print ("Error: unable to fetch data")	
	
# 关闭数据库连接
db.close()

'''

# SQL 插入语句
sql = "INSERT INTO EMPLOYEE(FIRST_NAME, \
		 LAST_NAME, AGE, SEX, INCOME) \
		 VALUES ('%s', '%s', '%d', '%c', '%d' )" % \
		 ('Mac', 'Mohan', 20, 'M', 2000)
try:
	# 执行sql语句
	cursor.execute(sql)
	# 执行sql语句
	db.commit()
except:
	# 发生错误时回滚
	db.rollback()

# SQL 查询语句
sql = "SELECT * FROM EMPLOYEE \
		 WHERE INCOME > '%d'" % (1000)"
try:
	# 执行SQL语句
	cursor.execute(sql)
	# 获取所有记录列表
	results = cursor.fetchall()
	for row in results:
		fname = row[0]
		lname = row[1]
		age = row[2]
		sex = row[3]
		income = row[4]
		 # 打印结果
		print ("fname=%s,lname=%s,age=%d,sex=%s,income=%d" % \
				 (fname, lname, age, sex, income ))
except:
	print ("Error: unable to fetch data	)
	
# SQL 更新语句
sql = "UPDATE EMPLOYEE SET AGE = AGE + 1 WHERE SEX = '%c'" % ('M')
try:
	# 执行SQL语句
	cursor.execute(sql)
	# 提交到数据库执行
	db.commit()
except:
	# 发生错误时回滚
	db.rollback()
	
	
# SQL删除记录语句
sql = "DELETE FROM EMPLOYEE WHERE AGE > '%d'" % (20)
try:
	# 执行SQL语句
	cursor.execute(sql)
	# 向数据库提交
	db.commit()
except:
	# 发生错误时回滚
	db.rollback()	
	
'''