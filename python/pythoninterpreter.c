#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum
{
    OP_PRINT,
    OP_UNKNOWN
} OpCode;

// byte code -> .pyc
typedef struct
{
    OpCode opcode;
    const char *arg;
} Instruction;

// parser
Instruction parse(const char *source)
{
    Instruction inst;
    if (strncmp(source, "print(\"hello\")", 15) == 0)
    {
        inst.opcode = OP_PRINT;
        inst.arg = "hello";
    }
    else
    {
        inst.opcode = OP_UNKNOWN;
        inst.arg = NULL;
    }
    return inst;
}

// virtual machine
void execute(Instruction inst)
{
    switch (inst.opcode)
    {
    case OP_PRINT:
        printf("%s\n", inst.arg);
        break;
    case OP_UNKNOWN:
        printf("Invalid Instruction\n");
        break;
    }
}

int main()
{
    char source[256];
    printf("PYTHON prototype V1.0 (print(\"hello\") ):\n>>>");
    fgets(source, sizeof(source), stdin);
    source[strcspn(source, "\n")] = 0;

    Instruction inst = parse(source);
    execute(inst);
    return 0;
}