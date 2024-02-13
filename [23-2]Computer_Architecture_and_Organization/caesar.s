# 22000080 KimMinchae
# 23-2 Computer Architecture and Organization (ITP30003) 01 Class
# hw1 - 2 : Caesar Cipher

.data
input:    
    .asciiz "Enter plain text: "
result:
    .asciiz "Cipher text: "
enter:
    .asciiz "\n\n"
input_str:
    .space 128  # allocate 128byte

.text
main:
        jal cipher
        
        # print enter
        la $a0, enter
        li $v0, 4           
        syscall

        jal cipher
        j exit

cipher:
        # Print "Enter plain text: "
        la $a0, input
        li $v0, 4           
        syscall

        # Scanf input_str
        la $a0, input_str
        li $v0, 8
        syscall

        # t0 = a0 = input_str address
        move $t0, $a0

        # Print "Cipher text: "
        la $a0, result
        li $v0, 4           
        syscall

        j forlen

forlen: # Print input_str[i] - 3
        lb $t1, 0($t0)    # $t1 = input_str[i]

        # if input_str[i] == '/n' => exit
        li $t5, 10
        beq $t1, $t5, cipher_end

        # if input_str[i] == ' ' => print_char
        li $t2, 32
        beq $t1, $t2, print_char

        addi $t1, $t1, -3   # input_str[i] -= 3 (cipher)
        
        # if less than 'a', add 26
        li $t3, 97 # $a1 = 'a'
        slt $t4, $t1, $t3  # $t3 = 1 if $t1 < 'a' (char >= 'a')

        beq $t4, $zero, print_char # normal => print_char
        addi $t1, $t1, 26 # : abnormal, add 26
        j print_char

print_char: 
        li $v0, 11  # print_char
        move $a0, $t1
        syscall

        # else jump to forlen
        addi $t0, $t0, 1   # i++
        j forlen

cipher_end:
        jr $ra

exit:
        li $v0, 10          # exit
        syscall