# Concurrent-Server

An attempt to create a concurrent server that communicates with clients using FIFO pipes to return the length of a given string. Also, I created a basic graphic interface using the ncurses.h library.

Once the server is launched, it creates two FIFO pipes and opens them both. First one in read mode and the second one in write mode. The server receives data from the first FIFO sent by the client, calculates the length of the passed string, and finally writes the data into the second, write-mode FIFO pipe and transfers it to the client, which displays the current string length on the screen. The server can handle multiple clients one-by-one.


