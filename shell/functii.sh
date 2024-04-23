#!/bin/bash

# documentatie:
# http://www.cs.umsl.edu/~sanjiv/classes/cs2750/lectures/kshfns.pdf
# https://unix.stackexchange.com/questions/232384/argument-string-to-integer-in-bash

# utilizare operator aritmetic: $((...)) pentru a converti din sir in numar'
# alternativa: utilizare expresie: 'expr $1 + $2;

########################
# Intrare: doua numere
#
# Iesire: un text cu rezultatul adunarii
########################
aduna_numere() {
    # ne asiguram ca se primesc exact 2 parametrii
    # altfel se afiseaza un mesaj ajutator si se returneaza 0 
    if [[ $# != 2 ]]
    then
        #echo 0
        echo "Utilizare: aduna_numere a b"
        return 1
    fi
    echo $(($1 + $2))
    return 0
}

utilizeaza_rezultat() {
    echo "Rezultatul este:" $1
    return 0
}

# 
rez_aduna=$(aduna_numere 10 20)
RET_CODE=$?
echo $rez_aduna RET_CODE: $RET_CODE

utilizeaza_rezultat $rez_aduna

# la acest apel nu se afiseaza mesajele din functia apelata: aduna_numere
# functia utilizeaza_rezultat afiseaza 'prinde primul mesaj' si-l considera iesirea functiei apelate
# in acest caz - va fi 0 de la 'echo 0'
utilizeaza_rezultat $(aduna_numere 100)
