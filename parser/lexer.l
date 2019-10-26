%{

#include <iostream>
#include "parser.yy.hpp"

#if defined(LLDEBUG)
    #define yield(expr) std::cout << #expr << std::endl; return expr
#else
    #define yield(expr) return expr
#endif

%}

%option noyywrap
%option nodefault

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

. ;
<PHP>. ;
\n  ;
<PHP>\n   ;

%%