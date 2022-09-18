n=eval(input())
b=input()
a=input()
e=0;
if n%2==0:
    if not b==a:e=1 
else:
    for x,y in zip(b, a):
        if x==y:
            e=1
            break
print("Deletion succeeded") if e == 0 else print("Deletion failed")
