#!/bin/bash

grep -o -E "mul\([0-9]{1,3},[0-9]{1,3}\)" input | grep -o -E "[0-9]{1,3}" | ./a.out
