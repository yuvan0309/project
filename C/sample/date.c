#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_THREADS 128
#define STRING_LENGTH 10

char *randstring(size_t len) {
  static char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *random = malloc(sizeof(char) * (len + 1));

  if (random) {
    for (size_t n = 0; n < len; n++) {
      int key = rand() % (int)(sizeof(charset) - 1);
      random[n] = charset[key];
    }

    random[len] = '\0';
  }

  return random;
}

void *thread_function(void *thread_arg) {
  int *thread_id = (int *)thread_arg;
  int c = 1;
  char HEE[STRING_LENGTH + 1];
  char HE[STRING_LENGTH + 1];

  strcpy(HE, "HELLOWORLD");

  while (1) {
    strcpy(HEE, randstring(STRING_LENGTH));

    if (strncmp(HE, HEE, STRING_LENGTH) == 0) {
      printf("Thread %d: Success at %dth attempt\n", *thread_id, c);
      printf("%s\n", HE);
      printf("%s\n", HEE);
      pthread_exit(NULL);
    }
    c++;
  }
}

int main() {
  pthread_t threads[NUM_THREADS];
  int thread_ids[NUM_THREADS];

  srand((unsigned int)time(NULL));

  for (int i = 0; i < NUM_THREADS; i++) {
    thread_ids[i] = i;
    pthread_create(&threads[i], NULL, thread_function, (void *)&thread_ids[i]);
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}