#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_spinlock_t lock;

void lockandunlock()
{
  int i = 10000;
  while ( i>0 )
  {
    pthread_spin_lock( &lock );
    i--;
    pthread_spin_unlock( &lock );
  }
}

void main()
{
  pthread_spin_init( &lock, PTHREAD_PROCESS_PRIVATE );
  lockandunlock();
  pthread_spin_destroy( &lock );
}
