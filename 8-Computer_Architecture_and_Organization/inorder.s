# 22000080 KimMinchae
# 23-2 Computer Architecture and Organization (ITP30003) 01 Class
# hw1 - 3 : traversal tree inorder

.data
tree: .word 1, 2, 3, 4, -1, 6, 7
max_num_node: .word 7
#tree: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, 12, -1, 14, 15
#max_num_node: .word 15
msg: .asciiz "Inorder: "
msg2:  .asciiz "\n"
msg3:  .asciiz " "

.text
main:
    # printf("Inorder: ");
    la $a0, msg
    li $v0, 4  # print_string         
    syscall

    # inorder(0);
    li $a1, 0 
    jal inorder

    # printf("/n");
    la $a0, msg2
    li $v0, 4    # print_string       
    syscall

    li $v0, 10          # exit
    syscall

inorder:
    # if (index >= 0 && index < max_num_node  && tree[index] != -1)
    li $t7, 0      #t7 = 0 : continue, >0 : end
    lw $t1, max_num_node
    # 1)
    slt $t0, $a1, $zero # if index < 0, t0 = 1
    add $t7, $t7, $t0
    # 2)
    slt $t0, $t1, $a1 # if max_num_node < index, t0 = 1
    add $t7, $t7, $t0
    seq $t0, $t1, $a1 # if max_num_node = index, t0 = 1
    add $t7, $t7, $t0
    # 3)
    sll $s0, $a1, 2         # $s0 = $a1 * 4 (int word)
    la $t2, tree
    add $t2, $t2, $s0
    lw $t3, 0($t2)
    li $t4, -1
    seq $t0, $t3, $t4  # if tree[index] = -1, t0 = 1
    add $t7, $t7, $t0
    # result
    blt $zero, $t7, inorder_end # if t7 > 0 : jump to end

    addi $sp, $sp, -8    # adjust stack for 2 items
    sw $a1, 0($sp)       # save index
    sw $ra, 4($sp)       # save return address

    # inorder(2 * index + 1); 
    sll $a1, $a1, 1        # $a1 = 2 * index
    addi $a1, $a1, 1       # $a1 = 2 * index + 1
    jal inorder

    # before print, set tree[index] with loaded index
    lw $a1, 0($sp)             # get arguments
    sll $s0, $a1, 2         # $s0 = $a1 * 4 (int word)
    la $t5, tree
    add $t5, $t5, $s0
    lw $t6, 0($t5)
    # printf(" %d ", tree[index]);
    la $a0, msg3
    li $v0, 4    # print_string       
    syscall
    move $a0, $t6              
    li $v0, 1      # print_int           
    syscall
    la $a0, msg3
    li $v0, 4    # print_string       
    syscall

    # inorder(2 * index + 2);
    sll $a1, $a1, 1        # $a1 = 2 * index
    addi $a1, $a1, 2       # $a1 = 2 * index + 2
    jal inorder

    lw $a1, 0($sp)             # get arguments
    lw $ra, 4($sp)             # get return address
    addi $sp, $sp, 8           # free stack for 2 items
    jr $ra 

inorder_end:
    jr $ra   