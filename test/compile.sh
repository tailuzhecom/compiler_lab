#!/bin/bash
for file in ./*.rsh
do 
    ../cmake-build-debug/rush $file
    llvm-as-6.0 $file.ll -o $file.bc 
    llc-6.0 -filetype=asm $file.bc -o $file.s
    clang -g $file.s -o $file.out 
done


rm *.bc *.s
