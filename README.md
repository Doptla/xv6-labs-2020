# MIT 6.S081 2020fall

This repository contains my solution to the labs for MIT's 6.S081 operating system.

## Hints for each lab

You should do the labs on your own at first, but if you encounter some bugs or want to get some high-level hints, this part may help you.

### lab1 : util


- sleep (easy) : just follow the guidance
- pingpong (easy) : You only need to transfer any byte you want, using wait function.
- Primes (moderate/hard) : Understand Eratosthenes,and trying to turn the recursive behavior within a single process into the interaction of multiple processes, consider the behavior of transferring data versus how to implement multiple processes
- Find (moderate) : A simple multinomial tree recursion.
- xargs (moderate) : A string algorithm question, try to concatenate the original string with the expanded string in steps, create a new array of strings and don't forget to allocate memory :)

### lab2 : syscall

- sleep (moderate/hard) : Combine this with the user program trace to figure out what exactly to implement. If you haven't worked with make or vim before, this will take a long time.
- sysinfo(moderate) : Read Sections 3.2~3.6,If you are unfamiliar with the organization of memory, the process count combined with the source code and the manual will suffice
