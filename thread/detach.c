#include <pthread.h>
#include <stdio.h>

void* child_routine( void * param )
{
  int id = (int)param;
  printf( "I'm thread %d\n", id );
  pthread_exit(0);
}

int main()
{
  pthread_t thread[10];
  void* return_value[10];
  for (int i = 0; i < 10; i++)
  {
    pthread_create( &thread[i], 0, child_routine, (void*)i );
  }
  for ( int i = 0; i < 10; i++ )
  {
    pthread_join(&thread[i], 0);
  }
}
