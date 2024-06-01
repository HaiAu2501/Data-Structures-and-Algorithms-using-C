#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int deadline;
    int profit;
} Job;

int compare(const void *a, const void *b)
{
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobB->profit - jobA->profit; // Sắp xếp giảm dần theo profit
}

int findSlot(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return parent[i] = findSlot(parent, parent[i]);
}

int scheduleJobs(Job jobs[], int n)
{
    qsort(jobs, n, sizeof(Job), compare);

    int *parent = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++)
    {
        parent[i] = -1; // Khởi tạo tất cả các slot là trống
    }

    int totalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        int availableSlot = findSlot(parent, jobs[i].deadline);
        if (availableSlot > 0)
        {                                              // Nếu có slot trống trước deadline
            parent[availableSlot] = availableSlot - 1; // Đánh dấu slot này và trước đó là đã sử dụng
            totalProfit += jobs[i].profit;
        }
    }

    free(parent);
    return totalProfit;
}

int main()
{
    int n;
    scanf("%d", &n);
    Job *jobs = (Job *)malloc(n * sizeof(Job));
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
    }

    printf("%d\n", scheduleJobs(jobs, n));
    free(jobs);
    return 0;
}
