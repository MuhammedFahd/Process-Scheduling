#include<stdio.h>
#include<conio.h>
#include <string.h>
#include<stdlib.h>
int main()
{
    //a is arrival time and b is burst time
    int a[10],b[10],x[10],p[10];
    int waiting[10],turnaround[10],completion[10];
    int i,j,smallest,count=0,time;
    double avg=0,tt=0,end;
    int n=0;

    FILE* file = fopen("input2.txt", "r"); 

    if(!file){
        printf("\n Unable to open : %s ", "input2.txt");
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
        a[n]=inputs[1];
        b[n]=inputs[2];
        n=n+1;
    }
    fclose(file);

    for(i=0; i<n; i++)
        x[i]=b[i];

    b[9]=9999;
    for(time=0; count!=n; time++)
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
                smallest=i;
        }
        b[smallest]--;

        if(b[smallest]==0)
        {
            count++;
            end=time+1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }
    printf("\n\n Process \t Burst Time \t Arrival time \t Waiting time \t Turnaround time   Completion time \n");
    for(i=0; i<n; i++)
    {
        printf("\n %d \t\t\t %d  \t\t %d \t\t %d \t\t %d \t\t %d \n",p[i],x[i],a[i],waiting[i],turnaround[i],completion[i]);
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    printf("\n Average Wait Time : %f \n",(avg/n));
    printf("\n Average Turn Around Time : %f \n",(tt/n));
    return 0;
}