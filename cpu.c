#include <stdio.h>
struct process{
        int at,bt,rem,completed,tt,wt,ct,pid,prio;
}p[10],temp;
int i,j,total;
void fcfs(){
        total=0;
        int n;
        printf("Enter the number of processes\n");
        scanf("%d",&n);
        printf("Enter the arrival time\n");
        for(i=0;i<n;i++){
                p[i].pid=i+1;
                printf("Process %d:",i+1);
                scanf("%d",&p[i].at);
                printf("\n");
        }
        printf("Enter the burst time\n"); 
        for(i=0;i<n;i++){
                printf("Process %d:",i+1);
                scanf("%d",&p[i].bt);
                printf("\n"); 
        }
        for(i=0;i<n-1;i++){
                for(j=0;j<n-i-1;j++){
                        if(p[j].at>p[j+1].at){
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                        }
                }
        }
        float avg_tt=0,avg_wt=0;
        for(i=0;i<n;i++){
                while(total<p[i].at){
                        total++;
                }
                p[i].ct=total+p[i].bt;
                total=p[i].ct;
                p[i].tt=p[i].ct-p[i].at;
                p[i].wt=p[i].tt-p[i].bt;
                avg_tt+=p[i].tt;
                avg_wt+=p[i].wt;
        }

        printf("PID | ARR | BURST | COMP | TURN | WAIT\n");
        for(i=0;i<n;i++){
                printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
        }
        printf("Avg waiting time=%f\nAvg turnaround time=%f\n",avg_wt/n,avg_tt/n);
}

void sjf(){
        total=0;
        int n;
        printf("Enter the number of processes\n");
        scanf("%d",&n);
        printf("Enter the arrival time\n");
        for(i=0;i<n;i++){
                p[i].pid=i+1;
                printf("Process %d:",i+1);
                scanf("%d",&p[i].at);
                printf("\n");
        }
        printf("Enter the burst time\n"); 
        for(i=0;i<n;i++){
                printf("Process %d:",i+1);
                scanf("%d",&p[i].bt);
                printf("\n"); 
        }
         for(i=0;i<n-1;i++){
                for(j=0;j<n-i-1;j++){
                        if(p[j].at>p[j+1].at){
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                        }
                }
        }
        printf("Hello1\n");
        for(i=0;i<n-1;i++){
                for(j=0;j<n-i-1;j++){
                        if(p[j].at==p[j+1].at && p[j].bt>p[j+1].bt){
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                        }

                }
        }
        printf("Hello 2\n");
        int totalburst=0;
        for(i=0;i<n;i++){
                p[i].completed=0;
                totalburst+=p[i].bt;
        }
        printf("HELLO3\n");
        int completed=0;
        float avg_wt=0,avg_tt=0;
        while(completed!=n){
                int min_index=-1;
                int min=totalburst;
                for(i=0;i<n;i++){
                        if(p[i].at<=total && p[i].completed==0){
                                if(p[i].bt<min){
                                        min=p[i].bt;
                                        min_index=i;
                                }
                                if(p[i].bt==min){
                                        if(p[i].at<p[min_index].at){
                                                min=p[i].bt;
                                                min_index=i;
                                        }
                                }
                        }
                }
                if(min_index==-1){
                        total++;
                }
                else{
                        p[min_index].ct=total+p[min_index].bt;
                        p[min_index].tt=p[min_index].ct-p[min_index].at;
                        p[min_index].wt=p[min_index].tt-p[min_index].bt;
                        p[min_index].completed=1;
                        completed++;
                        total=p[min_index].ct;
                        avg_tt+=p[min_index].tt;
                        avg_wt+=p[min_index].wt;

                }
        }
        printf("HELLO 4\n");
         printf("PID | ARR | BURST | COMP | TURN | WAIT\n");
        for(i=0;i<n;i++){
                printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
        }

        printf("Avg waiting time=%f\nAvg turnaround time=%f\n",avg_wt/n,avg_tt/n);

}

void priority(){
        total=0;
          int n;
        printf("Enter the number of processes\n");
        scanf("%d",&n);

printf("Enter the arrival time\n");
        for(i=0;i<n;i++){
                p[i].pid=i+1;
                printf("Process %d:",i+1);
                scanf("%d",&p[i].at);
                printf("\n");
        }
        printf("Enter the burst time\n"); 
        for(i=0;i<n;i++){
                printf("Process %d:",i+1);
                scanf("%d",&p[i].bt);
                printf("\n"); 
        }
printf("Enter the priority\n"); 
        for(i=0;i<n;i++){
                printf("Process %d:",i+1);
                scanf("%d",&p[i].prio);
                printf("\n"); 
        }
         for(i=0;i<n-1;i++){
                for(j=0;j<n-i-1;j++){
                        if(p[j].at>p[j+1].at){
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                        }
                }
        }
         // int totalburst=0;
        for(i=0;i<n;i++){
                p[i].completed=0;
       //         totalburst+=p[i].bt;
        }
        for(i=0;i<n-1;i++){
                for(j=0;j<n-i-1;j++){
                        if(p[j].prio>p[j+1].prio){
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;

                        }
                }
        }
        int completed=0;
        float avg_wt=0,avg_tt=0;
        while(completed!=n){
                int min_index=-1;
                int max=10000;
                for(i=0;i<n;i++){
                        if(p[i].at<=total && p[i].completed==0){
                                if(p[i].prio<max){
                                        max=p[i].prio;
                                        min_index=i;
                                }
                        }
                }
                if(min_index==-1){
                        total++;
                }
                else{
                        p[min_index].ct=total+p[min_index].bt;
                        p[min_index].tt=p[min_index].ct-p[min_index].at;
                        p[min_index].wt=p[min_index].tt-p[min_index].bt;
                        p[min_index].completed=1;
                        completed++;
                        total=p[min_index].ct;
                        avg_tt+=p[min_index].tt;
                        avg_wt+=p[min_index].wt;

                }
        }
         printf("PID | ARR | BURST | COMP | TURN | WAIT\n");
        for(i=0;i<n;i++){
                printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
        }

        printf("Avg waiting time=%f\nAvg turnaround time=%f\n",avg_wt/n,avg_tt/n);


}

 void rr(){
        total=0;
        int slice;
          int n;
        printf("Enter the number of processes\n");
        scanf("%d",&n);

printf("Enter the arrival time\n");
        for(i=0;i<n;i++){
                p[i].pid=i+1;
                printf("Process %d:",i+1);
                scanf("%d",&p[i].at);
                printf("\n");
        }
        printf("Enter the burst time\n"); 
        for(i=0;i<n;i++){
                printf("Process %d:",i+1);
                scanf("%d",&p[i].bt);
                printf("\n"); 
        }
        printf("Enter the time slice\n");
        scanf("%d",&slice);
         for(i=0;i<n-1;i++){
                for(j=0;j<n-i-1;j++){
                        if(p[j].at>p[j+1].at){
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                        }
                }
        }
        int remain,time,flag;
        float avg_wt=0,avg_tt=0;
        for(i=0;i<n;i++){
                p[i].rem=p[i].bt;
        }
        remain=n;
        int ready[30],count=0;
        printf("PID | ARR | BURST | COMP | TURN | WAIT\n");
        for(time=0,i=0;remain!=0;){
                if(p[i].rem<=slice && p[i].rem>0){
                        time+=p[i].rem;
                        p[i].rem=0;
                        flag=1;
                }
                else if(p[i].rem>0){
                        time=time+slice;
                        p[i].rem-=slice;
                }
                if(p[i].rem==0 && flag==1){
                        remain--;
                        flag=0;
                        avg_tt+=(time-p[i].at);
                        avg_wt+=(time-p[i].at-p[i].bt);
                        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,time,(time-p[i].at),(time-p[i].at-p[i].bt));
                }
                int m=0;
                for(j=0;j<n;j++){
                        if(p[j].at<=time && p[j].rem!=0){
                                ready[m++]=j;
                        }
                }
                if(m>0){
                        count=(count+1)%m;
                        i=ready[count];
                }
                else{
                        time++;
                }
        }
         printf("Avg waiting time=%f\nAvg turnaround time=%f\n",avg_wt/n,avg_tt/n);

} 

int main(){
        char choice;
        int option;
        do{
        printf("Enter your choice\n1-FCFS\n2-SJF\n3-PRIORITY\n4-ROUND ROBIN\n");
        scanf("%d",&option);
        switch(option){
                case 1:printf("FCFS\n");
                        fcfs();
                        break;
                case 2: printf("SJF\n");
                        sjf();
                        break;
                case 3:printf("PRIORITY\n");
                        priority();
                        break;
                case 4:printf("RR\n");
                        rr();
                        break;
                default:printf("Invalid option\n");
                        break;
        }
        printf("Do you wish to continue?\n");
        scanf(" %c",&choice);
        }while(choice=='y'||choice=='Y');
        return 0;
}
