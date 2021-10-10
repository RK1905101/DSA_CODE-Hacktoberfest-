#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void Activity(int start[], int finish[], int n)
{
    printf("The Selected activities are:\n");
    int j = 0;
    printf("%d ", j);
    int i;
    for (i = 1; i < n; i++)
    {
        if (start[i] >= finish[j])
        {
            printf("%d ", i);
            j = i;
        }
    }
}
int main()
{
    clock_t start = clock();
    int limit;
    printf("Enter the number of activities\n");
    scanf("%d", &limit);
    int starting[limit], finishing[limit];
    for (int i = 0; i < limit; i++)
    {
        starting[i] = (rand() % (5 - 0 + 1)) + 0;
        finishing[i] = (rand() % (6 - 4 + 1)) + 2;
        printf("Starting time =%d Finishing time =%d\n", starting[i], finishing[i]);
    }
    int n = sizeof(starting) / sizeof(starting[0]);
    Activity(starting, finishing, n);
    clock_t end = clock();
    clock_t timereq;
    timereq = (double)(end - start);
    printf("\nProcessor time taken :%f\n", (double)timereq);
    return 0;
}
