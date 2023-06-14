# operating-system-project
Project Description:
In this operating system project, the goal is to create a simulation of the
Sleeping Barber problem using a multithreaded approach. The simulation
should have the following components:
1. A barber thread that sleeps when there are no customers and wakes up
when a customer arrives.
2. A customer thread that arrives at random intervals and checks for an
available chair.
3. A waiting room that has a limited number of chairs, and customers
cannot enter the shop if there are no available chairs.
4. A queue data structure to manage the order of customers waiting for
their turn.
The project should implement a solution that prevents race conditions and
deadlocks, and ensures that the barber is always either cutting hair or
sleeping when there are no customers, and that customers are always either
getting a haircut or waiting for a chair when the barber is busy.
