#!/bin/bash
#Joseph Lee
#sl5nj
#postLab 7

echo "enter the exponent for counter.cpp: "
read n

if [ $n == "quit" ] ; then
	exit 0
	fi

length=5
total=0
time=0

for (( i=1; i <= length; i++ ))
do
	echo "Running iteration ${i}..."
	time=`./a.out ${n}`
	echo "time taken: ${time} ms"
	total=`expr $total + $time`
	
done

echo "${length} iterations took ${total} ms"
average=`expr $total / 5`
echo "Average time was $average ms"