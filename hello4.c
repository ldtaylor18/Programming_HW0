// Collatz Conjecture
// all positive integers will eventually reach 1
// even = n divide by 2
// odd = 3 * n + 1
// n stops when it is equal to 1


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{

// declaring varabiles

int n;
int pid; 
pid = fork();

//for error area for fork
if (pid == -1)
{
printf("Error Fork failed");
return 1;
}

//this area is the child process
else if
(pid == 0)
{

// user input an interger number
printf (" Enter a positive integer: ");
scanf ("%d",&n);
printf ("\n --> %d", n);

while (n>1)

if(n%2 > 0) //n is odd
{
n = 3 * n + 1;
printf("--> %d ", n);
}

else if (n%2==0) // n is even
{
n = n/2; // even number
printf("--> %d ",n);
}

}

//this area is the parent process
//the parent is waiting for the child to finish

wait(NULL);
//printf("complete");

 
return 0;

}
 
