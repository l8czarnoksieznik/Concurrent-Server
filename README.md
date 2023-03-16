# Concurrent-Server

An attempt to create concurrent server that communicates with client using FIFO pipes to return length of a given string. Also I created basic graphic interface using ncurses.h library. 

Once Server is lanched, it creates two FIFO pipes and opens them both. First one in read mode and the second one in write mode. Server receive data from first FIFO sent by Client, then calculates length of passed string, and finally writes data in the second, write mode FIFO pipe. Client stores users input in FIFO pipe, which Server immediately reads, calculates strings length, and via FIFO pipes, it sends it straight back to Client, which displays current string length on the screen. Server can handle multiple Clients one-by-one.


