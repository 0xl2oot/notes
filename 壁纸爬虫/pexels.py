# coding:utf-8
import urllib2
import json
import re
import time

Header = {
    'user-agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/57.0.2986.0 Safari/537.36'
}
cnt = 300  # first photo id, use to name the file
crawl_page_num = 30  # the number of page to crawl
page = 21  # initial crawling page
width=1920
height=1080
while page <= crawl_page_num:
    page_url = 'https://www.pexels.com/search/view/?format=js&page='+ str(page) # request .js file
    req = urllib2.Request(url=page_url, headers=Header)
    try:
        html = urllib2.urlopen(req,timeout=5)
        res = html.read()
        pattern = re.compile("data-pin-media=\\\\\"(.*?)\?")
        photo_addr_list = re.findall(pattern, res)  # get the address of photoes in the page
        for each in photo_addr_list:
            time.sleep(3)
            print each
            #download
            pic_url = each
            # print pic_url
            req = urllib2.Request(url=pic_url, headers=Header)
            try:
                pic = urllib2.urlopen(req,timeout=5).read()  # download the photo
                pic_name = str(cnt) + '.jpeg'
                cnt += 1
                print 'downloading page '+ str(page) +' picture ' + pic_name + ' success.'
                file = open('./pic/' + pic_name, 'wb') # you should  create a folder named 'pic'
                file.write(pic)
                file.close()
            except:
                print 'downloading page '+ str(page) +' picture ' + str(cnt) + ' timeout!!'
        page += 1
    except:
        print 'page visit failed, tend to try again'
        time.sleep(5)
