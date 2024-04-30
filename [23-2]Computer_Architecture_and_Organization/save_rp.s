.data
 msg : .asciiz "Enter the number of rows: "
 msg2 : .asciiz "=="
 msg2 : .asciiz "="

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
 forrow: move $s0, $zero #$s0 = i = 0
         slt $t3, $s0, $t1 #t3 = 0 if $s0 >= $t1 (i >= row)
         beq $t3, $zero, exit1 #go to exit1 if $s0 >= $t1 (i >= row)

         # for(int b=0; b<i; b++)
 blkrow: move $s1, $zero #$s1 = b = 0 
         slt $t4, $s1, $s0 #t4 = 0 if $s1 >= $s0 (b >= i)
         beq $t4, $zero, exit2 #go to exit1 if $s0 >= $t1 (b >= i)

         # printf("  ");
         li $v0, 4
         la $t0, msg2
         move $a0, $t0
         syscall

 exit2: # for(int j=cur_row; j<cur_row*2-1; j++)
 ordrow: move $s2, $t2 #$s2 = j = cur_row
         sll $t5, $t2, 1 #$t5 = cur_row*2
         addi $t5, $t5, -1 #$t5 = cur_row*2-1
         slt $t6, $s2, $t5 #t6 = 0 if $s2 >= $t5 (j >= cur_row*2-1)
         beq $t6, $zero, exit3 #go to exit1 if $s2 >= $t5 (j >= cur_row*2-1)

        # printf("%d ", j);
         li $v0, 1
         la $t0, msg2
         move $a0, $t0
         syscall

 exit3: # fprintf("%d ", cur_row*2-1);






        # end syscall
 exit1: li $v0, 10
         syscall
         
        