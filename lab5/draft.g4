grammar Forge;

// Parser rule
program: block+;
block: NAME setBColor varDecl* ascendLoop descendLoop;
setBColor: 'based' 'color' 'is' INT;
varDecl: 'let' NAME 'is' (INT | randGet);
randGet: 'rand' INT;
ascendLoop: 'ascend' '[' custLoopInit ']' ;
descendLoop: 'descend' '[' custLoopInit ']' ;
custLoopInit: iterLoop gradLoop xLoop yLoop;
iterLoop: 'iterator' 'is' (NAME | INT);
gradLoop: 'gradient' 'is' NAME;
xLoop: 'x' 'is' NAME;
yLoop: 'y' 'is' NAME;
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