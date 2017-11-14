#!/bin/bash
echo "cc lex_part.c -o myflex"
cc parse_lex_rules.c -o PLR
echo "generation lex-sequence..."
./PLR < rules.txt > lex_sequence.h

echo "cc build_autom.c -o mybison"
cc build_lex_autom.c -o BLA
echo "automaton building..."
./BLA > lex_automaton.h

#echo "cc main.c -o task4"
#cc main.c -o task4

#echo ""
#echo "cleaning temporarily files..."
#rm lex_sequence.h automaton.h myflex mybison
#echo "_ ready for using _"

echo cc main.c -o task5
cc main.c -o task5