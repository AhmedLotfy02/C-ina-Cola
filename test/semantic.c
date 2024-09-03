// Semantic Errors:
// #define UNDECLARED 1
/*
//in-Case: use of IDENTIFIER in Rules: {assignment: IDENTIFIER '='  expr},{term: IDENTIFIER} ,
to Check if:
    1) the IDENTIFIER is Not Declared before.
*/
int x = y;
print("X = ", x);
// #define REDECLARED 2
/*
//in-Case: Declare New IDENTIFIER in Rules: {decleration: .... IDENTIFIER ....},{...: ...IDENTIFIER...} ,
to Check if:
    1) the IDENTIFIER is declared in and only in the current Scope of Program.
*/
int x = 4;
int x = 5;
print("X = ", x);
// #define OUT_OF_SCOPE 3
/*
//in-Case: use of IDENTIFIER in Rules: {assignment: IDENTIFIER '='  expr},{term: IDENTIFIER} ,
to Check if:
    1) Declared out of the current Scope and downstream to the Base scope{0}
    2) or Declared but Removed when Exit it's Scope and become Ghost Variable
*/
{
    int x = 5;
}
{
    int y = x;
}
print("X = ", x);
print("Y = ", y);
// #define UNINITIALIZED 4
/*
//in-Case: use of IDENTIFIER in Rules: {term: IDENTIFIER} ,
to Check if:
    1) IDENTIFIER Variable is used before initialized
*/
int x;
int y = x;
print("Y = ", y);
// #define CONSTANT 5
/*
//in-Case: use of IDENTIFIER in Rules: {assignment: IDENTIFIER '='  expr}
to Check if:
    1) IDENTIFIER Variable is Constant in the Nearest Scope from the current Scope and downstream to the Base scope{0}
*/
const int x = 1;
x = 5;
print("X = ", x);
// #define TYPE_MISMATCH 6
/*
//in-Case: use of IDENTIFIER in Rules: {assignment: IDENTIFIER '='  expr},{decleration: dataType IDENTIFIER  '='  expr} ,{decleration: dataModifier dataType IDENTIFIER  '='  expr }
//in-Case: use of IDENTIFIER in Functions: { arithmatic(struct nodeType* op1, struct nodeType*op2, char* op),doComparison(struct nodeType* op1, struct nodeType*op2, char* op),logical(struct nodeType* op1, struct nodeType* op2, char* op),identifierNodeTypeCheck(char* name , struct nodeType* node),nodeNodeTypeCheck(struct nodeType* node1, struct nodeType* node2) },Negation(struct nodeType* term).
to Check if:
    1) IDENTIFIER->type !=  expr->type in assignment or decleration
    2) Using Negation() but term->type == String type.
    3) Using arithmatic() or doComparison() or logical() ,and op1->type != op2->type passed to function.
    4) Using arithmatic() with op1->type = Sting ,and op = {'-','*','/'}  passed to function.
*/
// 1
int x = "String type Mismatch";
print("X = ", x);
// 2
int y = -"2";
int z = -"D";
print("Y = ", y, " , Z = ", z);
// 3
int a = 3 + "Ahmed";
float b = 3.5 && "Ahmed";
bool c = false != "Ahmed";
print("A = ", a, " ,B = ", b, " ,C = ", c);
// 4
string s = "Omar" * "Kareem";
print("S = ", s);
// #define UNUSED 7
/*
  //in-Case: Declare or Intialize IDENTIFIER in Rules: {assignment: IDENTIFIER '='  expr},{decleration: dataType IDENTIFIER  '='  expr} But not used ever in {term: IDENTIFIER} \
  to Check if:                                                                                                                                                                  \
      1) All IDENTIFIER Varibles are Declared or Intialized But not used ever in {term: IDENTIFIER, ...}                                                                        \
  */
int x = 5;
int y = 3;
int z = y;
print("X = ", x, "Y = ", y, "Z = ", z);
;

// #define CONSTANT_IF 8
/*                                                            \
 //in-Case: use of expr in Rules: {ifCondition  : IF '(' expr ')' ...} ,            \
 to Check if:                                                                       \
     1) expr is Constant expression and = False                                     \
     2) or expr is Constant expression and = True                                   \
     3) when expr => Constant{0} * Varible{expr} or Varible{expr} * Constant{0}     \
     4) when expr => Constant{0} / Varible{expr}                                    \
     5) when expr => Constant{0} % Varible{expr}                                    \
     6) when expr => Constant{0} AND Varible{expr} or Varible{expr} AND Constant{0} \
     7) when expr => Constant{1} OR Varible{expr} or Varible{expr} OR Constant{1}   \
 */
bool t = true;
print("T = ", t);
const bool f = false;
print("F = ", f);
if (t)
{
    int x = 5;
    print("X = ", x);
}
if (f)
{
    int x = 3;
    print("X = ", x);
}
if (t && f)
{
    int x = 4;
    print("X = ", x);
}