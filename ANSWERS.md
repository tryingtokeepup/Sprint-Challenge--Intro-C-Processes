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

Zombie processes are typically created when a process, especially a child process, is done excecuting its commands, and is waiting to be terminated by the parent process. In this state, the child process is unkillable, even with the `kill` command. The parent would need to finish its proceedures and instructions, and start cleaning up its forked child processes. In that span of time, the child process would be a zombie, until it is destroyed.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

The big difference of this is in the idea behind interpreted versus compiled. For example, in Python and Javascript, you need those as middlemen to run your python and javascript scripts and programs; for C, it is directly compiled into machine code and fed into the CPU, bypasses any middleman and thus running much faster than other languages. Add on to this the fact that C is incredibly terse and light-weight, and you have a blazing fast language that you can work with.
