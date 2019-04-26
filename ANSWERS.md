**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

The possible states of a process, or it's life cycle, can be summarized into 5 general states: Start, Ready, Running, Waiting, and Terminated/Exit.

Start is simply the initial state of the process when it is first created

Ready is when the process is waiting to be assigned to a processor, usually be a CPU scheduler/OS. This state can occur after the Start state when the process
is interrupted by the scheduler to give those resources allocated to the interrupted process to some other process.

Running is ... well, the state where the process is running, and the processor executes the process's instructions.

Waiting is not the same as the Ready state; it's when the process is waiting for some resource, like a user's input or some file, to be inputed/become available.

Terminated/Exit is the state a process is moved to when its instructions are fufilled and the data allocated to it is waiting to be removed from the main memory.

**2. What is a zombie process?**

A zombie process is simply a process that is done executing and is ready to be terminated, but isn't killed off yet(happens a lot to child processes in Exit mode).

**3. How does a zombie process get created? How does one get destroyed?**

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
