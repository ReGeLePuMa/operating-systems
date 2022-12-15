#!/bin/bash

NUM_CLIENTS=8

for i in $(seq 1 $NUM_CLIENTS); do
    cat msg.txt | grep "$i" > temp.txt
    # wait
    nc localhost 42424 < temp.txt
done
rm temp.txt
wait

