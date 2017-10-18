#!/bin/bash
echo "cc lex_part.c -o myflex"
cc myflex.c -o myflex
echo "generation lex-sequence..."
./myflex < rules.txt > lex_sequence.h

echo "cc build_autom.c -o mybison"
cc build_autom.c -o mybison
echo "automaton building..."
./mybison > automaton.h
#cat automaton.h

echo "cc main.c -o task4"
cc main.c -o task4

echo ""
echo "cleaning temporarily files..."
rm lex_sequence.h automaton.h myflex mybison
echo "_ ready for using _"