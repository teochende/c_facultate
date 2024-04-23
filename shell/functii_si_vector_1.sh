#!/bin/bash

#
# Site foarte bun:
# https://www.shellscript.sh/functions.html
#

# utilizare read:
# https://www.geeksforgeeks.org/bash-scripting-how-to-read-a-file-line-by-line/?ref=ml_lbp

# https://www.geeksforgeeks.org/bash-scripting-functions/?ref=ml_lbp

creare_vect() {
    i=0
    echo -n "introduceti o valoare: "

    read v[0]
    i=$i+1 

    echo -n "doriti sa mai introduceti o valoare (1 daca da, altceva daca nu)?: "
    read raspuns

    while [ $raspuns -eq 1 ]
    do
        echo -n "introduceti o valoare: "
        read v[i]
        i=$i+1    
        echo -n "doriti sa mai introduceti o valoare( 1 daca da altaceva daca nu )?: "
        read raspuns
    done
 
    n=$i
	
    #echo "${v[@]}"
    
    return 10
}


max_vect() {
    echo in max_vect: ${v[@]}
    max=${v[0]}
    
    for i in ${v[@]}
    do
        echo Valoarea din vector: $i
	#if [ max -lt $i ] - echivalent cu notatia de mai jos cu [[ ... ]]
        if [[ $max < $i ]]
        then
            max=$i
        fi
    done

    return 0
}

creare_vect

# salvare cod de return - ce s-a dat ca parametru la return
REZ_CREATE=$?
echo rezultat returnat: $REZ_CREATE

# vectorul v este variabila globala, vizibila in afara functiei
echo VECTOR: ${v[@]}

# vectorul v este vizibil si in interiorul functiei max_vect
max_vect
# dupa executia functiei max_vect, max este vizibil si in afara functiei
echo max = $max
