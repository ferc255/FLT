#!/bin/bash
echo "cc lex_part.c -o PLR"
cc parse_lex_rules.c -o PLR
echo "Generation lex-sequence..."
./PLR < lex_rules.txt > lex_sequence.h

echo ""
echo "cc build_autom.c -o BLA"
cc build_lex_autom.c -o BLA
echo "Automaton building..."
./BLA > lex_automaton.h


echo ""
echo "cc parse_grammar.c -o PG"
cc parse_grammar.c -o PG
echo "Parsing grammar..."
./PG < grammar.txt > grammar.h

echo ""
echo "cc gen_tables.c -o GT"
cc gen_tables.c -o GT
echo "building syntax tables..."
./GT > syn_tables.h

echo ""
echo "cc main.c -o task5"
cc main.c -o task5

echo ""
echo "cleaning temporary files..."
#rm PLR lex_sequence.h BLA lex_automaton.h PG grammar.h GT syn_tables.h
echo ""
echo "_ ready for usage _"
