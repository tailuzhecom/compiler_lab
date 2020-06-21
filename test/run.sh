#!/bin/bash
read input
llvm-as-6.0 < $input | lli-6.0 

