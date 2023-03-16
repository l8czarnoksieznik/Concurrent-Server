#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>

int main()
{
    int fd1, fd2;
    char *mfifo1 = "fifo1";
    char *mfifo2 = "fifo2";
    char str[100];
    char tmp[12];

    int row, col;
    char mesg[]="Wprowadz tekst: ";
    char mesg2[]="...Odebrano z serwera: ";

    // Czesc graficzna
    initscr();
    start_color();
    getmaxyx(stdscr, row, col);
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    refresh();

    attron(COLOR_PAIR(2) | A_BOLD);
    mvprintw(0, 0, "KLIENT");
    refresh();
    attroff(COLOR_PAIR(2) | A_BOLD);
    
    attron(COLOR_PAIR(1));
    mvprintw(row/2-1, ((col-strlen(mesg))/2 - 10), "%s", mesg);
    refresh();

    // Pobieramy tekst od uzytkownika
    getstr(str);    

    // Otwieramy FIFO1 w trybie do zapisu i FIFO2 w trybie do zapisu
    fd1 = open(mfifo1, O_WRONLY);
    fd2 = open(mfifo2, O_RDONLY);

    // Zapisujemy do FIFO1 podany tekst
    write(fd1, str, sizeof(str));
    // Odczytujemy z FIFO2
    read(fd2, tmp, sizeof(tmp));

    mvprintw(row/2+3, ((col-strlen(mesg2))/2-10), "%s%s\n", mesg2, tmp);
    refresh();

    attroff(COLOR_PAIR(1));

    refresh();
    getch();
    endwin();

    // Zamykamy FIFO
    close(fd1);
    close(fd2);

}