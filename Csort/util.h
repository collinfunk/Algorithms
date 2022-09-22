#ifndef _UTIL_H_
#define _UTIL_H_

void write_unsorted_file(const char *filename, int n);
int *read_file(const char *filename, int *n);
double time_sort(int n);


#endif /* _UTIL_H_ */