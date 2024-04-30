# 22000080 KimMinchae
# 23-2 Computer Architecture and Organization (ITP30003) 01 Class
# hw2 - 2 : determines square root

.data
str1:      
    .asciiz "Enter the number: "
str2:     
    .asciiz "Square root: "
y:          
    .float 1.0
e:          
    .float 0.00001
two:        
    .float 2.0

.text
.globl main

main:
    # 1) get input
    li 	 	$v0, 4
    la      $a0, str1
    syscall

    li      $v0, 6
    syscall                    # $f0 = input

    # 2) set float register
    add.s   $f1, $f1, $f0      # $f1 = input = n
    add.s   $f2, $f2, $f0      # $f2 = input = x
    l.s     $f3, y             # $f3 = y
    l.s     $f4, e             # $f4 = e
    l.s     $f5, two           # $f5 = 2.0

    # 3) sqrt loop
sqrt:
    # if (x - y) <= e, exit loop
    sub.s   $f6, $f2, $f3      # $f6 = x - y
    c.eq.s $f6, $f4            
    bc1t sqrt_end              # if (x - y) == e, exit loop
    c.lt.s $f6, $f4
    bc1t sqrt_end              # if (x - y) < e, exit loop

    # update x and y
    add.s   $f2, $f2, $f3      # x = x + y
    div.s   $f2, $f2, $f5      # x = (x + y) / 2.0

    div.s   $f3, $f1, $f2      # y = n / x

    # repeat loop
    j       sqrt

    # 4) print result
sqrt_end:
    li      $v0, 4
    la      $a0, str2
    syscall

    li      $v0, 2
    mov.s   $f12, $f3          # $f12 = y
    syscall

    li      $v0, 10           # exit system call code
    syscall
