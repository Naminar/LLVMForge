grammar Forge;

// Parser rule
program: block+;
block: NAME setBColor varDecl* ascendLoop* descendLoop*;
setBColor: 'based' 'color' 'is' INT;
varDecl: 'let' NAME 'is' (randGet | expr);
randGet: 'rand' INT;
ascendLoop: 'ascend' '[' iterLoop gradLoop xLoop yLoop ']';
iterLoop: 'iterator' 'is' (NAME | INT);
gradLoop: 'gradient' 'is' NAME;
xLoop: 'xpoint' 'is' NAME;
yLoop: 'ypoint' 'is' NAME;
descendLoop: 'descend' '[' iterLoop gradLoop xLoop yLoop ']';
expr:
	'-' expr
	| ( '*' | '/') expr expr
	| ( '+' | '-') expr expr
	| '(' expr ')'
	| INT
	| NAME;

// Lexer rules
NAME: [a-zA-Z_]+;
INT: [0-9]+;
WS: [ \t\r\n]+ -> skip;