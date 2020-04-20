#include<stdio.h>	 	 
#include<conio.h>	 	 
#include <stdlib.h>	//system functions
#define N 100	 	 
int ct=0;	//for number of processes entered in the second queue
int ppt=0;	//for struct2 tracking
int nk=100;	 	 
int tick=0;	 	 
struct process{	//for queue 1 scheduling
int at,bt,prt,pid,copy_array[N],cbt;
};
struct process2{ //for queue 2 scheduling using Round Robin int at2,bt2,prt2,pid2;
int wt,ta; int flage,at2,prt2,pid2,bt2;
}proc2[N];
void copyfun(struct process record){ //copying the info of queue2 process that has entered
proc2[ppt].bt2=record.bt;
proc2[ppt].at2=record.at;
proc2[ppt].prt2=record.prt;
proc2[ppt].pid2=record.pid;
ppt++;
}
//-------------------------------------------------------
void RR(){ //RoundRobin implementation algorithm_source:os_officials
int i, limit, total = 0, x, counter = 0, time_quantum;
int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
float average_wait_time, average_turnaround_time; limit=ct;
x = limit;
for(i = 0; i <limit ; i++)
{
arrival_time[i]=proc2[i].at2; burst_time[i]=proc2[i].bt2;
temp[i] = burst_time[i];
}
printf("\n\n"); printf("\nEnter Time Quantum:\t");
scanf("%d", &time_quantum);
printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
for(total = 0, i = 0; x != 0;)
{
if(temp[i] <= time_quantum && temp[i] > 0)
{
total = total + temp[i]; temp[i] = 0;
counter = 1;
}
else if(temp[i] > 0)
{
temp[i] = temp[i] - time_quantum; total = total + time_quantum;
}
if(temp[i] == 0 && counter == 1)
{
x--;
printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", proc2[i].pid2, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
wait_time = wait_time + total - arrival_time[i]-burst_time[i];
turnaround_time = turnaround_time + total-arrival_time[i];
counter = 0;
}
if(i == limit - 1)
{
i = 0;
}
else if(arrival_time[i + 1] <= total)
{
i++;
}
else
{
i = 0;
}
}
average_wait_time = wait_time * 1.0 / limit;
average_turnaround_time = turnaround_time * 1.0 / limit;
printf("\n\nAverage Waiting Time for queue2 only:\t%f", average_wait_time);
printf("\nAvg Turnaround Time for queue2 only:\t%f\n", average_turnaround_time);
}
//-----------------------------------------------------
int main(){
int nump,j=0,k=1,count=0,flag=0,time; 
printf("Enter the number of processes :"); 
scanf("%d",&nump);
struct process proc[nump]; for(int i=0;i<nump;i++)
{printf("Enter the process id here\n "); scanf("%d",&proc[i].pid);
printf("Enter the arrival time of %d :",proc[i].pid); scanf("%d",&proc[i].at);
printf("Enter the burst time of %d :",proc[i].pid); scanf("%d",&proc[i].bt); proc[i].cbt=proc[i].bt;
printf("Enter the priority time of %d :",proc[i].pid); scanf("%d",&proc[i].prt);
system("cls");//clears the screen
}
int fl=0; int i=0,btd;
for( i;i<nump;i++){ //1.1 Loop for individual process processing
int btd=proc[i].cbt;
int scale=0; k=1;
for(int j=0;j<btd;j++){
//1.2 loop for processing through the burstime untill the new process arrives
if(i==0 && proc[i].at!=0){
for(int l=0;l<proc[i].at;l++){
count++	;
 	}
time=proc[i].at;
printf("\n");
printf("\n%d ----%d---- %d",0,0,time);
}
else if(i==0 && proc[i].at==0 && scale==0){
for(int l=0;l<proc[i+1].at;l++){
count++;
proc[i].bt--;
}
fl=1;
printf("\n");
printf("\n%d ----process[%d]-----%d",proc[i].at,proc[i].pid,count);
time=proc[i].at+count;
}
if(i==(nump-1)){if(tick==1);
for(int m=0;m<proc[i].bt;m++){ count++; //proc[i].bt--;
}
printf("\n");
printf("\n%d ----process[%d]-----%d",time,proc[i].pid,count);
break;}
if( count!=0 && ((count%2)==0) && (proc[k+i].prt>proc[i].prt)){
printf("\n");
printf("\n%d ----process[%d]-----%d",time,proc[i].pid,count);
time=count;
count++;
proc[i].bt--;
flag++;
k++;
scale=1;
continue;
}
else if( count!=0 && ((count%2)==0) && (proc[i+k].prt < proc[i].prt)){
if(k==2){
printf("\n");
printf("\n%d ----process[%d]-----%d",time,proc[i].pid,count);
ct++;
copyfun(proc[i+1]);
i=i+1;
scale=1;
time=count;
count++;
proc[i+1].bt--;
tick=1;
break;
}
if(fl!=1){
printf("\n");
printf("\n%d ----process[%d]-----%d",time,proc[i].pid,count);//printing the first quque
}fl=0;
if(proc[i].bt>0){
ct++;
copyfun(proc[i]);}
scale=1;
time=count;
count++;
proc[i+1].bt--;tick=1;
break;
}
else
{
flag++; proc[i].bt--;count++; scale=1;
}
}
}
RR();
}
