#!/bin/bash

# https://www.geeksforgeeks.org/bash-scripting-array/
# https://linuxhandbook.com/echo-without-newline/

# declarare si afisare vector

declare -a array1=(1 2 3 4 5)
echo array1: "${array1[@]}"
echo

declare -a array2=(
[0]=fotbal
[1]=baschet
[2]=volei
[3]=fitness
)
echo array2: ${array2[@]}
echo #adauga o linie noua

# o alta modalitate de a defini un vector, similara cu cea de mai sus
array3[0]=fotbal
array3[1]=baschet
array3[2]=volei
array3[3]=fitness
echo array3: "${array3[@]}"
echo

# https://www.geeksforgeeks.org/bash-scripting-bash-echo-command/
# echo va afisa pe ecran tot ce urmeaza. Nu este nevoie de grupare cu ghilimele
# -e - optiune pentru a activa interpretarea caracterelor 'escape'/backslash - in acest caz \n
# \n trebuie pus in ghilimele pentru a fi interpretat
echo -e "\n"parcurgere vector cu for:
for i in ${array3[@]}
do
    echo $i
done



#########################
# functie care primeste un vector ca parametru
#########################

# echo -n ... - pentru a nu adauga caracterul sfarsit de linie
echo
func_p_vector() {
    echo -n "func_p_vector:"
    echo $*
}

func_p_vector ${array3[@]}
