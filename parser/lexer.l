%{

#include <iostream>
#include "parser.yy.hpp"

#if defined(LLDEBUG)
    #define yield(expr) std::cout << #expr << std::endl; return expr
#else
    #define yield(expr) return expr
#endif

%}

%option noyywrap nodefault caseless yylineno

%x PHP
%x IN_STRING
%%

<PHP>"(" {
    yield(parenthesis_open);
}

<PHP>")" {
       yield(parenthesis_close);
}

<PHP>"{" {
    yield(bracket_open);
}

<PHP>"}" {
       yield(bracket_close);
}

"<?"|"<?php" {
    BEGIN PHP;
}

<PHP>"?>" {
    BEGIN INITIAL;
}

<PHP>"true" {
    yield(k_true);
}

<PHP>"false" {
    yield(k_false);
}

<PHP>"null" {
    yield(k_null);
}

<PHP>"if" {
    yield(k_if);
}

<PHP>"elseif" {
    yield(k_elseif);
}

<PHP>"else" {
    yield(k_else);
}

<PHP>"for" {
    yield(k_for);
}

<PHP>"foreach" {
    yield(k_foreach);
}

<PHP>"while" {
    yield(k_while);
}

<PHP>"do" {
    yield(k_do);
}

. ;
<PHP>. ;
\n  ;
<PHP>\n   ;

%%