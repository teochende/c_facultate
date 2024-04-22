!/bin/bash



creare_vect() {

	i = 0;
  echo "introduceti o valoare: "

	read v[0]
  i=$i+1 

	echo "doriti sa mai introduceti o valoare (1 daca da, altceva daca nu)?"
  read raspuns

	while [ $raspuns -eq 1 ]
  do
    echo "introduceti o valoare: "
    read v[i]
    i=$i+1
    
    echo "doriti sa mai introduceti o valoare( 1 daca da altaceva daca nu )?"
    read raspuns
  done
 
	n=$i
	echo "vector final: ${v[@]}"
  return ${v[@]}
}


max_vect() {

	max = $1[0]
  echo "max = $max"
}

v=`creare_vect`
#vector=$(creare_vect)

#echo ${v[@]}
