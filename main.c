/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Main file.
** main
*/
/*
NOTES :
*/

#include "include/my.h"
#include "include/my_radar.h"

static void print_help(void)
{
    my_putstr("Welcome in the my_radar simulation !\n\n");
    my_putstr("This project simulates the trajectory of planes.\n");
    my_putstr("Their goal is to reach their final destination.\n");
    my_putstr("If they hit eachother, they crash.\n");
    my_putstr("They can't crash if they are in the view range of ");
    my_putstr("a control tower.\n");
    my_putstr("Usage :\n");
    my_putstr("    ./my_radar <file>\n");
    my_putstr("\nCreated by Killian QUINTIN.\n");
}

static int help(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_help();
        return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    window_t window;

    if (help(ac, av))
        return 0;
    if (error_handling(ac, av))
        return 84;
    init_window(&window);
    main_screen(&window);
    return 0;
}
