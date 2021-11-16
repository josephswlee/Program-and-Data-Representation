#!/bin/bash
#Joseph Lee
#sl5nj
#12 Oct 2020
#inLab6

echo "Dictionary file: "
read dict
echo "Grid file: "
read grid

#store the time of the runs
RUNNING_TIME1=`./a.out $dict $grid | tail -1`
RUNNING_TIME2=`./a.out $dict $grid | tail -1`
RUNNING_TIME3=`./a.out $dict $grid | tail -1`
RUNNING_TIME4=`./a.out $dict $grid | tail -1`
RUNNING_TIME5=`./a.out $dict $grid | tail -1`

#store the time into outcome
outcome=`expr $RUNNING_TIME1 + $RUNNING_TIME2 + $RUNNING_TIME3 + $RUNNING_TIME4 + $RUNNING_TIME5`
average=`expr $outcome / 5`

echo "Average runtime was" $average "milliseconds"