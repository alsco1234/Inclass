.data
buffer:
	.space 20
str1:
	.asciiz "Enter string(max 20 chars): "
str2:	
	.asciiz "You wrote:\n"

.text
.globl main
main:
	la	 $a0, str1		# load print str1
	li	 $v0, 4			# print_string system call code
	syscall

	li 	 $v0, 8			# read_string system call code
	la 	 $a0, buffer	# load the byte space for string
	move $t0, $a0		# save string to $t0
	syscall

	la 	 $a0, str2		# load and print str2
	li	 $v0, 4			# print_string system call code
	syscall

	la   $a0, buffer	# reload byte space
	move $a0, $t0		# load string to $a0
	li	 $v0, 4
	syscall

	li 		$v0, 10		# exit system call code
	syscall 
