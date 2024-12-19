grammar Forge;

// Parser rule
expr:
	'-' expr
	| expr ( '*' | '/') expr
	| expr ( '+' | '-') expr
	| '{' expr '}'
	| INT
    | NAME;

// Lexer rules
NAME: [a-zA-Z_]+;
INT: [0-9]+;
WS: [ \t\r\n]+ -> skip;