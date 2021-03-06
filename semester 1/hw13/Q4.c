#include <stdio.h>
#include <string.h>

#define ARR_LENGTH 17
#define MAX_RANGE 256

void countingSort(int arr[ARR_LENGTH]);

int main(void)
{
    int arr[ARR_LENGTH] = {0};
    int i = 0;

    printf("Enter 17 numbers: \n");
    for (i = 0; i < ARR_LENGTH; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Before: \n");
    for (i = 0; i < ARR_LENGTH; i++)
    {
        printf("%d " , arr[i]);
    }
    printf("After:\n");
    countingSort(arr);
    return 0;
}

void countingSort(int arr[ARR_LENGTH])
{
    int i = 0;
    int max = 0;
    int min = 9999;
    int helpArr[MAX_RANGE] = {0};
    int finalArr[ARR_LENGTH] = {0};

    for (i = 0; i < ARR_LENGTH; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    for (i = 0; i < ARR_LENGTH; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    for (i = 0; i < ARR_LENGTH; i++)
    {
        helpArr[arr[i] - min]++;
    }

    for (i = 0; i < MAX_RANGE; i++)
    {
        helpArr[i + 1] += helpArr[i];
    }

    for (i = 0; i < ARR_LENGTH; i++)
    {
        finalArr[helpArr[arr[i] - min] - 1] = arr[i];
        helpArr[arr[i] - min]--;
    }

    for (i = 0; i < ARR_LENGTH; i++)
    {
        printf("%d ", finalArr[i]);
    }
}

