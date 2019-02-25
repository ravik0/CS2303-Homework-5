#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "sort.h"

/** Program which takes an array of integers, prints it,
 * sorts it, prints it again, and reports how long the sorting took.
 * @param a Array of integers.
 * @param count Number of integers in the array.
 * @param func The sort function to use, either sort, sort2, or sort3.
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

void timesort (int a[], int count, char* func) {

  struct timeval start_time; // time stamps for start and end of sorting
  struct timeval end_time;
  struct timeval sort_time; // Elapsed time while sorting

  printf("Unsorted array:\n");
  print_int_array(a, count);

  gettimeofday(&start_time, NULL); // Get timestamp
  if(strcmp(func, "sort") == 0) sort_descending(a, count);
  else if (strcmp(func, "sort2") == 0) sort_descending2(a,count);
  else if (strcmp(func, "sort3") == 0) sort_descending3(a,count);
  else {
	  printf("Unknown sorting function! Exiting!\n");
	  return;
  }
  gettimeofday(&end_time, NULL); // Get timestamp

  printf("Sorted array (descending order):\n");
  print_int_array(a, count);

  printf("Timestamp before sorting: ");
  print_timeval(start_time); 
  printf("Timestamp after sorting: ");
  print_timeval(end_time);
  sort_time = timediff(start_time, end_time);
  printf("Time spent sorting: ");
  print_timeval(sort_time); 
}
