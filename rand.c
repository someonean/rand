#include <stdio.h>
#include <signal.h>

char cont;

void stop(int s)
{
	cont = 0;
}

int main()
{
	long num, lower, higher;

	printf("Enter lower boundary: ");
	scanf("%ld", &lower);
	printf("Enter higher boundary: ");
	scanf("%ld", &higher);
	printf("Press control+C to get a random number.\n");
	signal(SIGINT, stop);
	cont = 1;
	num = lower;
	while(cont)
	{
		num++;
		if(num > higher) num = lower;
	}
	printf("%ld\n", num);
	return 0;
}
