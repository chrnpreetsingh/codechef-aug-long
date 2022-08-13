for i in range(int(input())):
    N = int(input())
    S = list(map(int, input().split()))
    S.insert(0,0)
    a = 0
    b = 0
    for i in range(N):
        a = a + (S[i])
        if a >= b:
            b = a + S[i]
        elif a < b:
            b = b + S[i]
        
    print(b)
        
    
    
