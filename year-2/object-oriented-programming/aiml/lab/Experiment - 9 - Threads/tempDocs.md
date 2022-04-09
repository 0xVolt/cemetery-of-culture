THREADS

What is an OS?
    Manages computer hardware and software resources
    
    Interface bet user and hardware

Processes & Threads
    A program in execution
    
    Thread is a component of process
    
    It is a basic unit of CPU utilization, consists program counter, stack (for memory allocations of local vars) thread id and a set of registers
        
        CPU is the place where the program is executed

        If any process is to be executed by CPU, the prog and its associated data are first loaded into registers (of the process control block) from the memory.

        Two registers, MAR (Mem Address Reg) and MDR (Mem Data Reg)

    On modern pcs, multiple processes run at the same time. For eg: intel i3 contains 2 cores (i.e., it has two CPUs).

        At a time, only two proceses will get CPU resources and get executed for a certain amt of time

        The process of loading, processing and unloading processess is called context switching

        This happens so fast that it seems like thousands of processess run concurrently

    Multi-processing

        Process based

            Whenever a prog is to be executed, it starts a new process which then starts a new thread to execute

    Multi-threading

        Thread based

            If a process takes 1 hr to execute on one CPU

            Instead of starting a single thread, start 6 threads and each CPU (cores in i7) will handle equal load and will complete the task is 1/6th of an hour i.e., 10 mins

            Each thread has its own register and stack

    Context switching in multithreading is better than multithreading   
        Since only the register and stack need to be changed in terms of multithreading

Threads

    Thread life cycle

        When we create a thread in Java, it is going to be in a new state until started. Directly doesnt execute

            call start method changes state to running (if CPU is free) or runnable (if CPU is not and context switching is to be performed)

        If a thread is running, we use suspend, free or sleep to stop its execution

            This moves the thread to the blocked state

            resume or notify brings it back to active state

        stop() moves it to dead state

    Thread creation

        Java comes with in built support to create threads

        in other languages, we need 3rd party apps to create threads

        In Java, we create threads by doing

            i. Extend a pre defined class thread (like we do with custom exceptions):

                Extend the thread class and create a child class

                Then override run()

                    This holds the code of the task to implement in the execution of the thread

                Steps:
                
                    class MyThread extends Thread {
                        public void run() {
                            // thread body of execution
                        }
                    }

                    // create thread in new state
                    Mythread thr1 = new MyThread;

                    // put thread in running state
                    thr1.start();

                    // combining above steps
                    new MyThread().start();

            ii. By implementing runnable interface

                Declare a class implementing this interface and then override run() method in the class

                Steps:
                    
                    class MyThread implements Runnable {
                        public void run() {
                            // body of exe
                        }
                    }

                    // Create an object of MyThread
                    MyThread obj = new MyThread();

                    // Additional step to create a thread using Thread class to create a thread taking out object as an arg
                    Thread thr1 = new Thread(obj)

        These two methods exist since multiple inheritance is not supported in Java

    The Main/Parent thread is whats created by the JVM to run the main method in a Java program. In a program that creates child threads, the main thread (which runs the program), will then create the child thread.

    Thread Priority

        Min = 1, Max = 10, Normal = 5

        Java allows users to change the priorties of different threads, we do this using
        ThreadName.setPriority(int Thread_Priority)

        Check BB for program on priority

    Thread Sync

        Accessing same data simul may lead to loss of data integrity

        You may ahronious outputs

        Eg: Reading from database and writing that data to database
            
            When database is empty, and execute

            If read acquires first, then reads no data and throws an error

            If the write thread acquires first, only then the read thread can do its job

            We need to set the order in which the threads execute

        If multiple threads want to access a shared resource, that means at a time only one thread needs to acquire it. After its done, the resource needs to be released and then the next thread should be allowed to access the resource

        This can be done with Synchronization

        Sync can be done with the Monitor which acts as a lock

            When the resource is being accessed by one thread, the monitor locks the resource so that no other thread can access it. When its done, the lock is broken and the next thread is allowed to access it.

            Execute examples on BB

        