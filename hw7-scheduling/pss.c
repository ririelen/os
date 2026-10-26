#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

struct proc {
	int pid;
	int arrival_time;
	int burst_time;
	int turnaround_time;
	int waiting_time;
	int response_time;
};

// helper method
void swap (struct proc *p1, struct proc *p2) {
	struct proc temp = *p1;
	*p1 = *p2;
	*p2 = temp;
};

// partition only for fcfs
int part_fcfs(struct proc *p, int first, int last) {
	struct proc pivot = p[last]; // array is a pointer thank God
	// we will take the last element because i felt this way
	int i = first - 1;
	// practically this sort is in-place
	for (int j = first; j < last; j++) {
		if (p[j].arrival_time < pivot.arrival_time || (p[j].arrival_time == pivot.arrival_time && p[j].pid < pivot.pid)) {
            		i++;
            		swap(&p[i], &p[j]);
        	}
	};
	swap(&p[i + 1], &p[last]);
	return i + 1;
};

void sort_fcfs(struct proc *p, int beg, int numproc) {
	struct proc temp;
	// i will use simple quick sorting, \
	// as I feel particulary basic today :D

	// i lied, it was a bit hard or im just tired. at least not O(n^2)
	if (beg < numproc) {
        	int pivo = part_fcfs(p, beg, numproc);
		sort_fcfs(p, beg, pivo - 1);
		sort_fcfs(p, pivo + 1, numproc);
	}
};
int ganttchart(struct proc *p, int n) {
	printf("\n");
	for (int i = 0; i < n; i++) {
		int t = p[i].burst_time-1;
		printf("|");
		for (int j = 0; j < t; j++) {
			printf(" ");
		};
		printf("P%d", p[i].pid);
		for (int j = 0; j < t; j++) {
                        printf(" ");
                };
	};
	printf("|\n");
};
void printing(struct proc *p, int n) {
	double tw = 0.0;
        double tt = 0.0;
        double tr = 0.0;
	printf("\n%-8s %-8s %-8s %-8s %-8s %-8s\n", "PID", "AT", "BT", "WT", "TAT", "RT");
	// i searched how to do this online...
    	for (int i = 0; i < n; i++) {
        	printf("%-8d %-8d %-8d %-8d %-8d %-8d\n",
        		p[i].pid,
                	p[i].arrival_time,
                	p[i].burst_time,
                	p[i].waiting_time,
                	p[i].turnaround_time,
                	p[i].response_time);

	        tw += p[i].waiting_time;
        	tt += p[i].turnaround_time;
       		tr += p[i].response_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", tw / n);

    printf("Average Turnaround Time: %.2f\n", tt / n);

    printf("Average Response Time: %.2f\n", tr / n);
}

void fcfs(struct proc *inp, int numproc) {
	sort_fcfs(inp, 0, numproc);
	printf("=== First Come First Served (FCFS) ===\n");
	ganttchart(inp, numproc);
	printing(inp, numproc);
}



int main() {
	int n;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	struct proc * arr = malloc(sizeof(struct proc) * n);
	if (arr == NULL) {
		printf("Memory Allocation failed\n");
		return 1;
	}
	for (int i = 0; i < n; i++) {
		printf("\nEnter the arrival time and burst time for process %d: ", i);
		scanf("%d", &(arr[i].arrival_time));
		printf(" ");
		scanf("%d", &(arr[i].burst_time));
	}
	printf("\n");
	for (int i = 0; i < n; i++) {}
	fcfs(arr, n);
}
