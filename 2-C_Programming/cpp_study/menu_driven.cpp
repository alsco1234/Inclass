int main() { 
int thelist[SIZE]; 
int n = 0;  /* the number of elements */
int cmd; do { 
	cmd = get_command();
	 switch (cmd) { 
		case INSERT: insert_element(thelist, &n);
					 break; 
		 case DELETE: delete_element(thelist, &n);
					 break; 
		case STATUS:
		show_status(thelist, n); 
	 break; 
	 case QUIT:
	 printf(" Bye.\n"); 
	 break; default: 
		 printf("\n\n Invalid command, try again, please. \n\n\n");
		 break; 
	 } 
} while (cmd != QUIT); 
return 0; 
}