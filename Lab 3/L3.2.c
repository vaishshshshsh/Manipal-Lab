#include <stdio.h>
#include <string.h>
#include <time.h>  // for clock_gettime

double get_time_in_seconds() {
  return (double)clock() / CLOCKS_PER_SEC;
}

void brute_force_search(char *text, char *pattern) {
    int i,j;
  int n = strlen(text);
  int m = strlen(pattern);
  int op_count = 0;  // Initialize operation count

  double start_time = get_time_in_seconds();

  for (i = 0; i <= n - m; i++) {
    op_count++;  // Outer loop comparison
    for (j = 0; j < m; j++) {
      op_count++;  // Inner loop comparison
      if (text[i + j] != pattern[j]) {
        break;
      }
    }

    if (j == m) {
      printf("Pattern found at index %d\n", i);
    }
  }

  double end_time = get_time_in_seconds();
  double elapsed_time = end_time - start_time;

  printf("Total operations: %d\n", op_count);
  printf("Time taken: %.6lf seconds\n", elapsed_time);
}

int main() {
  char text[100], pattern[50];

  printf("Enter the text: ");
  fgets(text, 100, stdin);  // Get input text from user
  text[strcspn(text, "\n")] = '\0';  // Remove trailing newline

  printf("Enter the pattern to search: ");
  fgets(pattern, 50, stdin);  // Get input pattern from user
  pattern[strcspn(pattern, "\n")] = '\0';  // Remove trailing newline

  brute_force_search(text, pattern);

  return 0;
}
