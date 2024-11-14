# System Programming - PseudoThread


## Description
We simulate a user-thread library by using `longjmp()`, `setjmp()`, etc. For simplicity, we use a function to represent a thread. In other words, you'll have to "context switch" between functions. To do this, you need to do non-local jumps between functions, which is arranged by a `scheduler()`: each time a function needs to "context switch" to another, it needs to jump back to `scheduler()`, and `scheduler()` will schedule next function to be executed, thus jump to it. Since non-local jump won't store local variables, we define a data structure for each function to store data needed for computing, which is called `TCB_NODE`. All the `TCB_NODE`s will formulate a circular linked-list. As `scheduler()` schedules functions, it also needs to make sure `Current` pointer points to correct `TCB_NODE` for functions to output correct result.






