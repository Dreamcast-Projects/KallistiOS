/* KallistiOS ##version##

   once.c
   Copyright (C) 2009 Lawrence Sebald
*/

#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>

#include <kos/once.h>
#include <kos/recursive_lock.h>
#include <arch/irq.h>

/* The lock used to make sure multiple threads don't try to run the same routine
   at the same time. */
static recursive_lock_t *lock = NULL;

int kthread_once(kthread_once_t *once_control, void (*init_routine)(void)) {
    uint32 old;
    assert(once_control);

    /* Create the lock if needed. */
    old = irq_disable();

    if(!lock) {
        lock = rlock_create();

        if(!lock) {
            return -1;
        }
    }

    irq_restore(old);

    /* Lock the lock. */
    if(rlock_lock(lock) == -1) {
        return -1;
    }

    /* If the function has already been run, unlock the lock and return. */
    if(once_control->run) {
        rlock_unlock(lock);
        return 0;
    }

    /* Run the function, set the control, and unlock the lock. */
    init_routine();
    once_control->run = 1;
    rlock_unlock(lock);

    return 0;
}