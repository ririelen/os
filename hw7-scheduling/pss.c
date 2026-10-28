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
	int i = first;
	// practically this sort is in-place
	for (int j = first; j < last; j++) {
		if (p[j].arrival_time < pivot.arrival_time || (p[j].arrival_time == pivot.arrival_time && p[j].pid < pivot.pid)) {
            		swap(&p[i], &p[j]);
			i++;
        	}
	};
	swap(&p[i], &p[last]);
	return i;
};

void sort_fcfs(struct proc *p, int start, int end) {
	// i will use simple quick sorting, \
	// as I feel particulary basic today :D
	// i lied, it was a bit hard or im just tired. at least not O(n^2)
	if (start < end) {
        	int pivo = part_fcfs(p, start, end);
		sort_fcfs(p, start, pivo - 1);
		sort_fcfs(p, pivo + 1, end);
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
void stats(struct proc *p, int n) {
	int time = p[0].arrival_time;
	for (int i = 0; i < n; i++) {
		// the process has arrived
		p[i].waiting_time = (time > p[i].arrival_time) ? (time - p[i].arrival_time) : (0);
		p[i].response_time = p[i].waiting_time;	// as non-preemptive
		time = time + p[i].burst_time + ((p[i].arrival_time > time) ? (p[i].arrival_time - time) : (0));
		p[i].turnaround_time = time - p[i].arrival_time;
	}
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
    };

    printf("\nAverage Waiting Time: %.2f", tw / n);
    printf("\nAverage Turnaround Time: %.2f", tt / n);
    printf("\nAverage Response Time: %.2f\n", tr / n);
};

void fcfs(struct proc *inp, int numproc) {
	sort_fcfs(inp, 0, numproc-1);
	stats(inp, numproc);
	printf("=== First Come First Served (FCFS) ===\n");
	ganttchart(inp, numproc);
	printing(inp, numproc);
};

// now functions for sjf -- sorting is also the Quick sort
// to implement sorting by burst time, and then by arrival time, we will just do complete comparison
// immediately. quick sort is unstable :(

int part_sjf(struct proc *p, int first, int last) {
        struct proc pivot = p[last]; // array is a pointer thank God
        // we will take the last element because i felt this way
        int i = first;
        // practically this sort is in-place
        for (int j = first; j < last; j++) {
                if (p[j].burst_time < pivot.burst_time || (p[j].burst_time == pivot.burst_time && (p[j].arrival_time < pivot.arrival_time || (p[j].arrival_time == pivot.arrival_time && p[j].pid < pivot.pid)))) {
                        swap(&p[i], &p[j]);
                        i++;
                }
        };
        swap(&p[i], &p[last]);
        return i;
};
void sort_sjf(struct proc *p, int start, int end) {
        if (start < end) {
                int pivo = part_sjf(p, start, end);
                sort_sjf(p, start, pivo - 1);
                sort_sjf(p, pivo + 1, end);
        }
};

void sjf(struct proc *inp, int numproc) {
        sort_sjf(inp, 0, numproc-1);
        stats(inp, numproc);
        printf("=== Shortest Job First (SJF) ===\n");
        ganttchart(inp, numproc);
        printing(inp, numproc);
};

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
		printf("Enter the arrival time and burst time for process %d: ", i);
		scanf("%d", &(arr[i].arrival_time));
		// printf(" ");
		scanf("%d", &(arr[i].burst_time));
		arr[i].pid = i;
	}
	printf("\n");
	fcfs(arr, n);
	// we don't need to copy the array and can reuse the old one :)
	printf("\n");
	sjf(arr, n);
};
