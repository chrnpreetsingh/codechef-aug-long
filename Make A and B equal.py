for i in range(int(input())):
    a = list(map(int , input().split()))
    a.sort()
    while a[0] < a[1]:
        a[0] = a[0] * 2
    
    if a[0] == a[1]:
        print("YES")
    else:
        print("NO")
