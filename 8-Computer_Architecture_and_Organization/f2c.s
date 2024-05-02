.data
constant: 
   .float 0.0, 5.0, 9.0, 32.0
str1:
	.asciiz "Enter the fahrenheit temperature: "
str2:	
	.asciiz "Converted celsius temperature is "

.text
.globl main
main:
	la  	$s1, constant	
	lwc1 	$f1, 0($s1)
	
	la 	 	$a0, str1		# Print out str1
	li      $v0, 4
	syscall

	li		$v0, 6			# read floating number for fahrenheit temperature
	syscall 
	add.s	$f12, $f0, $f1

	lwc1	$f16, 4($s1)	# covert fahrenheit to celsius
	lwc1  	$f18, 8($s1)
	div.s 	$f16, $f16, $f18
	lwc1  	$f18, 12($s1)
	sub.s 	$f18, $f12, $f18
	mul.s 	$f0,  $f16, $f18

	la 	 	$a0, str2		# Print out str2
	li      $v0, 4
	syscall

	add.s   $f12, $f0, $f1	# Print out celsius temperature
	li      $v0, 2
	syscall

	li 		$v0, 10			# exit system call code
	syscall 



	
