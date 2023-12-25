#include <pthread.h>
#include <stdio.h>

pthread_spinlock_t lock;

void lockandunlock()
{
  int i = 10000;
  int count = 0;
  while ( i  > 0 )
  {
    if ( pthread_spin_trylock( &lock ) )
    {
      i--;
      pthread_spin_unlock( &lock );
    }
    else
    {
      count++;
    }
  }
  printf( "Failed tries = %i\n", count );
}

void main()
{
  pthread_spin_init( &lock, PTHREAD_PROCESS_PRIVATE );
  lockandunlock();
  pthread_spin_destroy( &lock );
}
