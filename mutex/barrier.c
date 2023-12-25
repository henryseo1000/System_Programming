#include <pthread.h>
#include <stdio.h>

pthread_barrier_t barrier;

void * work( void* param)
{
  int id=(int)param;
  printf("Thread arrived %i\n", id );
  pthread_barrier_wait( &barrier );
  printf("Thread departed %i\n", id );
}

void main()
{
  pthread_t threads[10];
  pthread_barrier_init( &barrier, 0, 10 );
  for ( int i=0; i<10; i++ )
  {
    pthread_create( &threads[i], 0, work, (void*)i );
  }
  for ( int i=0; i<10; i++ )
  {
    pthread_join( threads[i], 0 );
  }
  pthread_barrier_destroy( &barrier );
}
