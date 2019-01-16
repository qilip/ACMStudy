main(c,n,i){
    scanf("%d",&n);
    while(n--){scanf("%d",&i);c+=i?1:-1;}
    if(c-1>0)puts("Junhee is cute!");
    else puts("Junhee is not cute!");
}
