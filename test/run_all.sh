#!/bin/bash
for file in ./*.ll
do 
    llvm-as-6.0 < $file | lli-6.0 
done
