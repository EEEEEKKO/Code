#include <stdio.h>   
        #include <stdlib.h>   
        #include <math.h>   
           
        const int N=2e5+100;   
        int max(int a,int b){   
            if(a>=b){   
                return a;   
            }   
            else{   
                return b;   
            }   
        }   
        int main(){   
            int p[N],n,temp=0;   
            int s=0; 
            int i,j;  
            scanf("%d",&n);   
            for(i=1;i<=n;i++){   
                scanf("%d",&temp);   
                p[i]=0;   
            }   
            for(i=1;i<=n;i++){   
                scanf("%d",&temp);  
                p[temp]=i;   
            }  
            //printf("-%d-",flag);  
            if(p[1]){ 
             for(i=2;p[i]==p[1]+i-1;i++); 
               if(p[i-1]==n){ 
                 for(j=i;j<=n&&p[j]<=j-i;++j); 
                    //printf("#%d#",j); 
                    if(j>n){ 
                        printf("%d\n",n-i+1); 
                      return 0; 
                  }  
             } 
          }//1????  
          int sum=0; 
         for(i=1;i<=n;i++){ 
              sum=max(sum,p[i]+1+n-i); 
           }        
               printf("%d\n",sum); 
                return 0; 
          }


