#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <semaphore.h>
#define Maximumcustomers 30
void *barber(void *);
void *customer(void *num);
sem_t chair; //only one customer thread can access at a time
sem_t waitingroom; //fixed no. of customers can enter
sem_t pillow; //allows barber to sleep
sem_t cuttingtime; //customer waits until barber cuts hairs
int workdone=0; //flag that checks if all customers are serviced to stop barber
int main()
{
//initialising threads
pthread_t barber_thread;
pthread_t cust_thread[Maximumcustomers];
int numcustomers, numchairs, num[Maximumcustomers];
int x;
printf("	Enter number of chairs (Don't exceed 25):");
scanf("%d",&x);
numcustomers=x;
scanf("%d",&x);
numchairs=x;
if(numcustomers>Maximumcustomers)
{
printf("\n	The maximum number of customers can be: %d ",Maximumcustomers);
}
int i;
for (i=0;i<Maximumcustomers;i++ )
{
num[i]=i; //assigning numbers to each customer
}
//initialising semaphores
sem_init(&chair, 0,1);
sem_init(&waitingroom,0,numchairs);
sem_init(&pillow,0,0);
sem_init(&cuttingtime,0,0);
//creating threads
pthread_create(&barber_thread,NULL, barber, NULL);
//create customers threads
for (i = 0; i < numcustomers; i++) { 
		pthread_create(&cust_thread[i], NULL, customer, (void *)&num[i]); 
	} 
	// Join each of the threads to wait for them to finish. 
	for (i = 0; i < numcustomers; i++) { 
		pthread_join(cust_thread[i],NULL); 
	} 
	// When all of the customers are finished, kill the barber thread. 
	workdone= 1; 
	sem_post(&pillow); // Wake the barber so he will exit. 
	pthread_join(barber_thread,NULL); 
	return 0; 
}
void *barber(void *x)
{
}
void*customer(void *num)
{
}
