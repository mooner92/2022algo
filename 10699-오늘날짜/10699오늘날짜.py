import time
t = time.time()
today = time.strftime("%Y-%m-%d", time.gmtime(t))
print( today )

#from datetime import datetime
#today = datetime.today().strftime('%Y-%m-%d')
#print( today )


#strftime = 원하는 서식으로 날짜 형식 변경 가능#
#ex %Y = 2020 %y = 20#