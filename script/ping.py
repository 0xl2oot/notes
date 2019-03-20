import re
import numpy as np  
import matplotlib.pyplot as plt  

f=open('baidu.txt', 'r')
data = f.read()


times = re.findall(r'(时间=)(.*)(ms)', data)

t = []

for time in times:
	# print(time[1])
	t.append(float(time[1]))

x = []
i = 1
while(i <= len(t)):
	x.append(i)
	i+=1

print(t)

plt.figure(figsize=(80,320)) # 大小
plt.plot(x,t,"b-",linewidth=1)   #在当前绘图对象绘图（X轴，Y轴，蓝色虚线，线宽度）  
plt.xlim(0, 80) # 横坐标
plt.ylim(0, 350) # 纵坐标
plt.yticks([0,50,100, 150, 200, 250, 300]) # 纵坐标刻度
plt.xlabel("Time(s)") #X轴标签  
plt.ylabel("time")  #Y轴标签  
plt.title("ping baidu.com") #图标题  
plt.show()  #显示图  
