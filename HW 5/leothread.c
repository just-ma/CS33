#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *thread(void *yea);
int max = 0;
int count = -1;

int main(int argc, char *argv[])
{
  max = atoi(argv[1]);
  if (max < 1)
    return 0;
  void *max1 = &max;
  pthread_t tid;
  pthread_create(&tid, NULL, thread, max1);
  pthread_join(tid, NULL);
  exit(0);
}


void *thread(void *yea) {
  int ok = *((int*)yea);
  int n, no;
  count++;
  no = count;
  if (ok < 2){
    printf("[%d]\n", no);
  }
  else {
    printf("(%d\n", no);
    pthread_t tid;
    for (n = 0; n < 2; n ++){
      ok -= 1;
      yea = &ok;
      pthread_create(&tid, NULL, thread, yea);
      pthread_join(tid, NULL);
    }
    ok += 2;
    printf("%d)\n", no);
  }
  return NULL;
}
