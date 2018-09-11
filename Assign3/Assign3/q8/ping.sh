#!/bin/bash
for i in {1..64}
do 
ping -t $i -c 1 yahoo.com
done
