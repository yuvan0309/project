; DEVELOP AN ALP TO FIND SUM OF FIRST 10 INTERGER NUMBER
    AREA SUM,CODE,READONLY
ENTRY
START
    MOV R5,#10
    MOV R4,#0
    MOV R1,#1
REPEAT
    ADD R0,R0,R1
    ADD R1,#1
    SUBS R5,#1
    CMP R5,#0
    BNE REPEAT
    LDR R4,=RESULT
    STR R0,[R4]
XSS B XSS
    AREA DATA2,DATA,READWRITE
RESULT DCD 0x40000000
    END