from datetime import datetime
now = datetime.now()

def rinput(t): 
    ts=(now.strftime('%I:%M:%S'))
    print(t)
    r=input()
    return ts,t,r
f=open("logs.txt","w+")
f.write(str(rinput("Enter a digit")))