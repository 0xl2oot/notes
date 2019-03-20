import re
import urllib.request
import json

f=open('traceroute.txt', 'r')
data = f.read()

print(data)

ips = re.findall(r"\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\b", data)

print(ips)

for ip in ips:
	url = 'http://ip.taobao.com/service/getIpInfo.php?ip='+ip
	res = urllib.request.urlopen(url)
	res = res.read()
	res = json.loads(res.decode())
	print(res['data']['ip'], res['data']['country'], res['data']['region'], res['data']['city'], res['data']['isp'])