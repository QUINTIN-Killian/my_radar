##
## EPITECH PROJECT, 2023
## my_radar
## File description:
## planes and towers generator for the my_radar project
## my_generator
##

import sys
from random import randint

class Infos:
    def __init__(self):
        self.file_name = "radar"
        self.nb_planes = 100
        self.speed_min = 1
        self.speed_max = 20
        self.delay_min = 0
        self.delay_max = 20
        self.nb_towers = 30
        self.tower_radius_min = 1
        self.tower_radius_max = 100
        self.x_min = 0
        self.x_max = 1920
        self.y_min = 0
        self.y_max = 1080

def help():
    print("Planes and towers generator for the my_radar project :\n")
    print("USAGE")
    print("    -h : to get help")
    print("    -p [nbr -> type:int] : to generate 'nbr' planes (default : 100)")
    print("    -t [nbr -> type:int] : to generate 'nbr' towers (default : 30)")
    print("    -fn [name -> type:str] : to name the result file with extension '.rdr' (default : 'radar.rdr')")
    print("    -tower_radius_min [nbr -> type:int] : to set the minimal towers radius (default : 1)")
    print("    -tower_radius_max [nbr -> type:int] : to set the maximal towers radius (default : 100)")
    print("    -screen_x_min [nbr -> type:int] : to set the minimum number of pixels of the screen in abscissa (default : 0)")
    print("    -screen_x_max [nbr -> type:int] : to set the maximum number of pixels of the screen in abscissa (default : 1920)")
    print("    -screen_y_min [nbr -> type:int] : to set the minimum number of pixels of the screen in ordinate (default : 0)")
    print("    -screen_y_max [nbr -> type:int] : to set the maximum number of pixels of the screen in ordinate (default : 1080)")
    print("    -speed_min [nbr -> type:int] : to set the minimal planes' speed (default : 1)")
    print("    -speed_max [nbr -> type:int] : to set the maximal planes' speed (default : 20)")
    print("    -delay_min [nbr -> type:int] : to set the minimal planes' delay (default : 0)")
    print("    -delay_max [nbr -> type:int] : to set the maximal planes' delay (default : 20)")
    print("\nCreated by Killian QUINTIN")

def is_number(str):
    my_list = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
    for i in range(len(str)):
        if str[i] not in my_list:
            print("Incorrect argument(s) : './<bin> -h' to get help.")
            sys.exit(84)
    return True

def generator(infos):
    file = open(f"{infos.file_name}.rdr", "w")
    for i in range(infos.nb_planes):
        file.write(f"A  {randint(infos.x_min, infos.x_max)} {randint(infos.y_min, infos.y_max)}  {randint(infos.x_min, infos.x_max)} {randint(infos.y_min, infos.y_max)}  {randint(infos.speed_min, infos.speed_max)}  {randint(infos.delay_min, infos.delay_max)}\n")
    for i in range(infos.nb_towers):
        file.write(f"T  {randint(infos.x_min, infos.x_max)} {randint(infos.y_min, infos.y_max)}  {randint(infos.tower_radius_min, infos.tower_radius_max)}\n")
    file.close()

if __name__ == "__main__":
    args = sys.argv[1:]
    if len(args) == 1 and args[0] == "-h":
        help()
        sys.exit(0)
    infos = Infos()
    if len(args) % 2 != 0:
        print("Incorrect number of arguments : './<bin> -h' to get help.")
        sys.exit(84)
    for i in range(0, len(args), 2):
        if i < len(args) - 1:
            if args[i] == "-t" and is_number(args[i + 1]):
                infos.nb_towers = int(args[i + 1])
            elif args[i] == "-p" and is_number(args[i + 1]):
                infos.nb_planes = int(args[i + 1])
            elif args[i] == "-fn":
                infos.file_name = args[i + 1]
            elif args[i] == "-speed_min" and is_number(args[i + 1]):
                infos.speed_min = int(args[i + 1])
            elif args[i] == "-speed_max" and is_number(args[i + 1]):
                infos.speed_max = int(args[i + 1])
            elif args[i] == "-delay_min" and is_number(args[i + 1]):
                infos.delay_min_min = int(args[i + 1])
            elif args[i] == "-delay_max" and is_number(args[i + 1]):
                infos.delay_max = int(args[i + 1])
            elif args[i] == "-tower_radius_min" and is_number(args[i + 1]):
                infos.tower_radius_min = int(args[i + 1])
            elif args[i] == "-tower_radius_max" and is_number(args[i + 1]):
                infos.tower_radius_max = int(args[i + 1])
            elif args[i] == "-screen_x_min" and is_number(args[i + 1]):
                infos.x_min = int(args[i + 1])
            elif args[i] == "-screen_x_max" and is_number(args[i + 1]):
                infos.x_max = int(args[i + 1])
            elif args[i] == "-screen_y_min" and is_number(args[i + 1]):
                infos.y_min = int(args[i + 1])
            elif args[i] == "-screen_y_max" and is_number(args[i + 1]):
                infos.y_max = int(args[i + 1])
            else:
                print("Incorrect argument(s) : './<bin> -h' to get help.")
                sys.exit(84)
        else:
            print("Incorrect number of arguments : './<bin> -h' to get help.")
            sys.exit(84)
    generator(infos)
    print(f"'{infos.file_name}.rdr' generated successfully !")
    sys.exit(0)