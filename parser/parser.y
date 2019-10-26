%{
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <stdexcept>

int yylex();

void yyerror (char const *s)
{
    throw std::runtime_error(s);
}

%}

%token require semicolon parenthesis_open parenthesis_close
%token identifier s_equal

%token l_string l_int l_double
%token k_true k_false k_null k_array

%token k_static k_function
%token k_class k_interface k_abstract k_extends k_implements
%token k_private k_protected k_public k_final k_const

%token k_if k_elseif k_else k_for k_foreach k_while k_do k_switch k_case k_try k_catch k_finally k_as k_throw
%token bracket_open bracket_close

%token s_double_arrow s_arrow s_dot s_comma s_double_colon s_ellipsis
%token s_double_equal s_triple_equal s_inferior s_superior s_different s_triple_different s_not s_double_plus s_double_minus s_star s_slash s_modulo

%token k_echo k_empty k_isset

%token t_symbol

%token b_eval b_current b_each b_key b_reset b_next

%start code

%%

code:
| macro_statement code
| declaration code

macro_statement: unchecked_statement semicolon
| conditionnal_structure
| bracket_open code bracket_close

unchecked_statement:
| statement

statement: assignation
| value
| builtin

assignation: identifier s_equal identifier
| identifier s_equal value
| identifier s_equal assignation

conditionnal_structure: if_structure
| for_structure
| foreach_structure
| while_structure
| do_while_structure

condition: parenthesis_open value parenthesis_close

if_structure: k_if condition macro_statement elsif_structure

elsif_structure:
| k_elseif condition macro_statement k_else_structure
| k_else_structure

k_else_structure:
| macro_statement

for_structure: k_for parenthesis_open for_assignation parenthesis_close macro_statement

for_assignation: semicolon for_test
| assignation semicolon for_test

for_test: semicolon for_side_effect
| value semicolon for_side_effect

for_side_effect:
| value

foreach_structure: k_foreach parenthesis_open foreach_content parenthesis_close macro_statement

foreach_content: identifier k_as identifier
| identifier k_as identifier s_double_arrow identifier

do_while_structure: k_do macro_statement k_while condition semicolon

while_structure: k_while condition macro_statement

builtin: k_echo value

declaration: k_class t_symbol extension_list implementation_list
| k_interface identifier extension_list

extension_list:
| k_extends t_symbol_list

implementation_list:
| k_implements identifier_list

t_symbol_list: t_symbol
| t_symbol s_comma t_symbol_list

identifier_list: identifier
| identifier s_comma identifier_list

literal: l_int
 | l_string
 | l_double
 | parenthesis_open literal parenthesis_close
 | k_true
 | k_false
 | k_null

expression: literal
 | k_empty condition
 | k_isset condition
 | assignation
 | function_call
 | array_notation
 | expression operator expression

operator: s_double_equal
// ...

value:
| condition
| expression
| lambda
//| lambda_class

function_call: callable parenthesis_open identifier_list parenthesis_close

callable: lambda
| t_symbol
// actual function
// array with reference

lambda: k_function function_handler

function_handler: parenthesis_open identifier_list parenthesis_close bracket_open macro_statement bracket_close


array_notation: k_array parenthesis_open array_list parenthesis_close
| bracket_open array_list bracket_close

array_list:
| value
| value s_comma array_list
| literal s_double_arrow value
| literal s_double_arrow value s_comma array_list
