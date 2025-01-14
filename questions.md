Exercise 1 - Theory questions
-----------------------------

### Concepts

What is the difference between *concurrency* and *parallelism*?
> *Your answer here*
Concurrency is a programs ability to do 2 tasks intertwined, not at the same time but with overlap. Paralellism on the other hand is when the program solves 2 or more tasks at the same time. In the incrementing program we got errors when the 2 functions were paralell, but it worked when they were concurrent.

What is the difference between a *race condition* and a *data race*? 
> *Your answer here* 
A race condition is when two threads try to acsess the same data at the same time, that can lead to complications.
The race data is the data that are being accsessed by both threads when the race condition happenes.
 
*Very* roughly - what does a *scheduler* do, and how does it do it?
> *Your answer here* 
scheduler is the part of a system that schedules how threads wil be runed on the available resources.

### Engineering

Why would we use multiple threads? What kinds of problems do threads solve?
> *Your answer here*
we can use multiple threads when we need multiple prosesses to run at the same time.

Some languages support "fibers" (sometimes called "green threads") or "coroutines"? What are they, and why would we rather use them over threads?
> *Your answer here*
they are threads that are not dependent on the operatingsystem. this gives less overhead and less restrictions and could build more scalable systems.

Does creating concurrent programs make the programmer's life easier? Harder? Maybe both?
> *Your answer here*
both, it can be more difficult to spot bugs and race conditions, but it makes it possible to make mutch more versitile code that can handle many more scenarios.

What do you think is best - *shared variables* or *message passing*?
> *Your answer here*
shared variables are easier to implement, but message passing are more scalable.
