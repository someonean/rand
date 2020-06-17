#include <stdio.h>
#include <signal.h>

char cont;

void stop(int s)
{
	cont = 0;
}

int main(int argc, char **argv)
{
	long num, lower, higher;

	if(argc < 2)
	{
		printf("Enter lower boundary: ");
		scanf("%ld", &lower);
	}
	else lower = atol(argv[1]);
	if(argc < 3)
	{
		printf("Enter higher boundary: ");
		scanf("%ld", &higher);
	}
	else higher = atol(argv[2]);
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
