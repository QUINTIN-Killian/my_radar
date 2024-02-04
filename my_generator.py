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
        self.nb_towers = 30

def help():
    print("Planes and towers generator for the my_radar project :\n")
    print("USAGE")
    print("    -h : to get help")
    print("    -p [nbr -> type:int] : to generate 'nbr' planes (default : 100)")
    print("    -t [nbr -> type:int] : to generate 'nbr' towers (default : 30)")
    print("    -fn [name -> type:str] : to name the result file with the extension '.rdr' (default : 'radar.rdr')")
    print("\nCreated by Killian QUINTIN")

def is_number(str):
    my_list = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
    for i in range(len(str)):
        if str[i] not in my_list:
            print("Incorrect argument(s) : './<bin> -h' to get help.")
            sys.exit(84)
    return True

def generator(infos):
    file = open(f"scripts/{infos.file_name}.rdr", "w")
    for i in range(infos.nb_planes):
        file.write(f"A  {randint(0, 1920)} {randint(0, 1080)}  {randint(0, 1920)} {randint(0, 1080)}  {randint(1, 20)}  {randint(0, 20)}\n")
    for i in range(infos.nb_towers):
        file.write(f"T  {randint(0, 1920)} {randint(0, 1080)}  {randint(1, 50)}\n")
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
            else:
                print("Incorrect argument(s) : './<bin> -h' to get help.")
                sys.exit(84)
        else:
            print("Incorrect number of arguments : './<bin> -h' to get help.")
            sys.exit(84)
    generator(infos)
    print(f"'{infos.file_name}.rdr' generated successfully !")
    sys.exit(0)