#!/bin/bash
#

for (( i=0; i<=$1; i++ ))
do
    if [ $i -lt 10 ]
    then
        convert -verbose -coalesce $2"00"$i$3 $4"00"$i".png"
    elif [[ $i -gt 9 && $i -lt 100 ]]
    then
        convert -verbose -coalesce $2"0"$i$3 $4"0"$i".png"
    else
        convert -verbose -coalesce $2$i$3 $4$i".png"
    fi
done
