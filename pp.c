#include<stdio.h>
#include<conio.h>
#include <string.h>
#include<stdlib.h>
int main(){

    //p is job, pt is burst time, pp is priority  
    int x,p[10],pp[10],pt[10],w[10],t[10],awt,atat,i;
    int n=0;  //no of processes
    FILE* file = fopen("input.txt", "r"); 

    if(!file){
        printf("\n Unable to open : %s ", "input.txt");
    }

    char line[500];
    

    while (fgets(line, sizeof(line), file)) {
        printf("%s\n", line); 
         // Returns first token
        char *token = strtok(line, " ");
   
        // Keep printing tokens while one of the
        // delimiters present in str[].
        int j=0;
        int inputs[3];
        while (token != NULL)
        {
            //printf("%s\n", token);
            int y = atoi(token); // Using atoi()
            inputs[j]=y;
            token = strtok(NULL, " ");
            j=j+1;
        }
        //printf("%s\n",inputs[0]);
        p[n]=inputs[0];
        pp[n]=inputs[1];
        pt[n]=inputs[2];
        n=n+1;
    }
    fclose(file);



   
   
  for(i=0;i<n-1;i++)
   {
     for(int j=i+1;j<n;j++)
     {
       if(pp[i]<pp[j])
       {
         x=pp[i];
         pp[i]=pp[j];
         pp[j]=x;
         x=pt[i];
         pt[i]=pt[j];
         pt[j]=x;
         x=p[i];
         p[i]=p[j];
         p[j]=x;
      }
   }
}
w[0]=0;
awt=0;
t[0]=pt[0];
atat=t[0];
for(i=1;i<n;i++)
 {
   w[i]=t[i-1];
   awt+=w[i];
   t[i]=w[i]+pt[i];
   atat+=t[i];
 }
printf("\n\n Job \t Burst Time \t Wait Time \t Turn Around Time   Priority \n");
for(i=0;i<n;i++)
  printf("\n %d \t\t %d  \t\t %d \t\t %d \t\t %d \n",p[i],pt[i],w[i],t[i],pp[i]);
awt/=n;
atat/=n;
printf("\n Average Wait Time : %d \n",awt);
printf("\n Average Turn Around Time : %d \n",atat);
//getch();
return 0;

}
