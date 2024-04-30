.data
str_ascii:    
    .asciiz "ASCII Code "
str_is:
    .asciiz " is "

.text
main:
    li $t0, 65

    # Print 'ASCII Code '
    la $a0, str_ascii
    li $v0, 4           
    syscall             # print_string

    # Print $t0
    move $a0, $t0
    li $v0, 1
    syscall             # print_int

    # Print ' is '
    la $a0, str_is
    li $v0, 4           
    syscall             # print_string

    # $t0 = 65 (ASCII Code 65 = 'A')
    move $a0, $t0
    li $v0, 11          # print_char
    syscall

    li $v0, 10          # exit
    syscall
