q=[int(input()) for _ in range(5)]
print(-q[0]*q[2]+q[3]+q[1]*q[4] if q[0]<0 else (q[1]-q[0])*q[4])