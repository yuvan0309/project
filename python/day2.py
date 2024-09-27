def entry(n,val1,arr):
    x,y,z=0,0,0
    for i in range(n):
        if arr[i]<val1:
            x+=1
        elif arr[i]==val1:
            y+=1
        else:
            z+=1
    print(x,y,z)
entry(5,6,[2,4,6,8,10])
