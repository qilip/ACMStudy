r[9999];main(i){for(i=1;i<9994;i++){r[i+i%10+i/10%10+i/100%10+i/1000%10]=1;if(!r[i])printf("%d\n",i);}}