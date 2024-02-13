# 22000080 KimMinchae
# 23-2 Computer Architecture and Organization (ITP30003) 01 Class
# hw1 - 1 : reverse pyramid

.data
 msg : .asciiz "Enter the number of rows: "
 msg2 : .asciiz " "
 msg3 : .asciiz "\n"

.text
main:
        # printf("Enter the number of rows: ");
        li $v0, 4
        la $t0, msg
        move $a0, $t0
        syscall
        # scanf("%d", &row);
        li $v0, 5
        syscall
        move $t1, $v0 #$t1 = row
        # int cur_row = row;
        move $t2, $t1 #$t2 = cur_row

        # for(int i=0; i<row; i++){
        move $s0, $zero #$s0 = i = 0


forrow: 
        slt $t3, $s0, $t1 #t3 = 0 if $s0 >= $t1 (i >= row)
        beq $t3, $zero, exit1 #go to exit1 if $s0 >= $t1 (i >= row)

        # for(int b=0; b<i; b++)
        move $s1, $zero #$s1 = b = 0

forblk: 
        sll $s7, $s0, 1 #t7 = $s0*2 = i*2
        slt $t4, $s1, $s7 #t4 = 0 if $s1 >= $s7 (b >= i*2)
        beq $t4, $zero, exit2 #go to exit2 if $s1 >= $s0 (b >= i)
        # printf("  ");
        li $v0, 4
        la $a0, msg2
        syscall
        #forblk, b++
        addi $s1, $s1, 1 
        j forblk

        
exit2:  
        # for(int j=cur_row; j<cur_row*2-1; j++)
        move $s2, $t2 #$s2 = j = cur_row
        sll $t5, $t2, 1 #$t5 = cur_row*2
        addi $t5, $t5, -1 #$t5 = cur_row*2-1

forord: slt $t6, $s2, $t5 #t6 = 0 if $s2 >= $t5 (j >= cur_row*2-1)
        beq $t6, $zero, exit3 #go to exit3 if $s2 >= $t5 (j >= cur_row*2-1)
# printf("%d ", j);
        li $v0, 1
        move $a0, $s2
        syscall
        la $a0, msg2
        li $v0, 4 
        syscall
        #forord, j++
        addi $s2, $s2, 1 
        j forord

        # printf("%d ", cur_row*2-1);
exit3:  li $v0, 1
        move $a0, $t5
        syscall
        la $a0, msg2
        li $v0, 4 
        syscall

        # for(int j=cur_row*2-2; j>cur_row-1; j--)
        move $s3, $t2 #$s3 = cur_row
        sll $s3, $t2, 1 #$s3 = cur_row*2
        addi $s3, $s3, -2 #$s3 = cur_row*2-2
        move $t7, $t2 #$t7 = j = cur_row
        addi $t7, $t7, -1 #$t8 = cur_row-1
fordeo: slt $t8, $t7, $s3 #t8 = 0 if $t7 >= $s3 (cur_row-1 >= j)
        beq $t8, $zero, exit4 #go to exit4 if $s2 >= $t5 (j >= cur_row-1)
# printf("%d ", j);
        li $v0, 1
        move $a0, $s3
        syscall
        la $a0, msg2
        li $v0, 4 
        syscall
        #fordeo, j--
        addi $s3, $s3, -1 
        j fordeo

exit4:  # cur_row -= 1
        addi $t2 $t2 -1

        # printf("\n");
        li $v0, 4
        la $t0, msg3
        move $a0, $t0
        syscall

        #forrow, i++
        addi $s0, $s0, 1 
        j forrow


exit1:  # end syscall
        li $v0, 10
        syscall
        
