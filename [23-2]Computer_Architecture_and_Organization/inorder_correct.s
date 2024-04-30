.data
tree:   .word 1, 2, 3, 4, -1, 6, 7
max_num_node:   .word 7
newline: .asciiz "\n"
space:   .asciiz " "
inorder_msg: .asciiz "Inorder: "

.text
.globl main

# Function to print an integer
print_int:
    li $v0, 1          # Load system call code for printing integer
    syscall
    jr $ra             # Return

# Function to print a string
print_string:
    li $v0, 4          # Load system call code for printing string
    syscall
    jr $ra             # Return

# Recursive inorder traversal function
inorder:
    # Function prologue
    addi $sp, $sp, -12   # Make space on the stack for local variables
    sw $ra, 8($sp)       # Save return address
    sw $a0, 4($sp)       # Save argument index
    sw $t0, 0($sp)       # Save temporary register t0

    lw $t0, max_num_node # Load max_num_node into t0
    lw $a0, 0($a0)       # Load index into a0
    li $t1, -1           # Load -1 into t1

    # Check base case: index >= max_num_node or tree[index] == -1
    bge $a0, $t0, end_inorder   # If index >= max_num_node, return
    lw $t2, tree($a0)          # Load tree[index] into t2
    beq $t2, $t1, end_inorder   # If tree[index] == -1, return

    # Recursive call: inorder(2 * index + 1)
    sll $t3, $a0, 1           # Compute 2 * index
    addi $t3, $t3, 1           # Compute 2 * index + 1
    move $a0, $t3              # Set argument for left subtree
    jal inorder                # Recursive call

    # Print tree[index]
    lw $a0, tree($a0)          # Load tree[index] into a0
    jal print_int              # Print the integer

    # Recursive call: inorder(2 * index + 2)
    lw $a0, 4($sp)             # Restore argument index
    sll $t4, $a0, 1           # Compute 2 * index
    addi $t4, $t4, 2           # Compute 2 * index + 2
    move $a0, $t4              # Set argument for right subtree
    jal inorder                # Recursive call

end_inorder:
    # Function epilogue
    lw $ra, 8($sp)            # Restore return address
    lw $a0, 4($sp)            # Restore argument index
    lw $t0, 0($sp)            # Restore temporary register t0
    addi $sp, $sp, 12         # Restore the stack pointer
    jr $ra                    # Return

main:
    # Print "Inorder: "
    la $a0, inorder_msg      # Load the address of the message
    jal print_string

    # Call inorder(0)
    li $a0, 0                # Set argument index to 0
    jal inorder

    # Print a newline
    la $a0, newline           # Load the address of the newline string
    jal print_string

    # Exit program
    li $v0, 10               # Load system call code for exit
    syscall
