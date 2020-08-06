#include<stdio.h>
#include<time.h>
void setTimeout(int milliseconds)
{
    // If milliseconds is less or equal to 0
    // will be simple return from function without throw error
    if (milliseconds <= 0) {
        fprintf(stderr, "Count milliseconds for timeout is less or equal to 0\n");
        return;
    }

    // a current time of milliseconds
    int milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;

    // needed count milliseconds of return from this timeout
    int end = milliseconds_since + milliseconds;

    // wait while until needed time comes
    do {
        milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;
    } while (milliseconds_since <= end);
}



int main(int argc, char const *argv[])
{
	 // input from user for time of delay in seconds
    int delay;
    printf("Enter delay: ");
    scanf("%d", &delay);

    // counter downtime for run a rocket while the delay with more 0
    do {
        // erase the previous line and display remain of the delay
        printf("\033[ATime left for run rocket: %d\n", delay);

        // a timeout for display
        setTimeout(1000);

        // decrease the delay to 1
        delay--;

    } while (delay >= 0);
	return 0;
}