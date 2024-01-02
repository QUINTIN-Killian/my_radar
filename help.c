/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** display help messages
** help
*/

#include "include/my.h"
#include "include/my_radar.h"

void print_help(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr(" ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("  path_to_script     The path to the script file.\n\n");
    my_putstr("OPTIONS\n");
    my_putstr(" -fh               print the parameter file usage and quit.\n");
    my_putstr(" -h                print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr(" 'L' key enable/disable hitboxes and areas.\n");
    my_putstr(" 'S' key enable/disable sprites.\n");
    my_putstr(" 'Q' key enable/disable the quad tree's hitbox.\n");
    my_putstr(" 'Escape' key in start menu leaves the game.\n");
    my_putstr(" 'Escape' key during simulation opens the pause menu.\n");
}

static void print_file_help_aux(void)
{
    my_putstr("  ARRIVAL Y       The plane's ordinate arrival position ");
    my_putstr("(from 0 to 1080)\n");
    my_putstr("  SPEED           The plane's speed (from 1 to 20 ; ");
    my_putstr("0=not moving)\n");
    my_putstr("  DELAY           The plane's spawn second (from 0 to ");
    my_putstr("inf)\n\n");
    my_putstr("  POSITION X      The towers's abscissa position (from 0 to ");
    my_putstr("1920)\n");
    my_putstr("  POSITION Y      The towers's ordinate position (from 0 to ");
    my_putstr("1080)\n");
    my_putstr("  RADIUS          The towers's view range (from 1 to 20)\n\n");
    my_putstr("  note that for each number given, its absolute value is ");
    my_putstr("used in the program\n");
}

void print_file_help(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("FILE USAGE\n");
    my_putstr(" A  [DEPARTURE X] [DEPARTURE Y]  [ARRIVAL X] [ARRIVAL Y]  ");
    my_putstr("[SPEED]  [DELAY]\n");
    my_putstr(" or\n");
    my_putstr(" T  [POSITION X] [POSITION Y]  [RADIUS]\n\n");
    my_putstr("  DEPARTURE X     The plane's abscissa departure position ");
    my_putstr("(from 0 to 1920)\n");
    my_putstr("  DEPARTURE Y     The plane's ordinate departure position ");
    my_putstr("(from 0 to 1080)\n");
    my_putstr("  ARRIVAL X       The plane's abscissa arrival position ");
    my_putstr("(from 0 to 1920)\n");
    print_file_help_aux();
}
