
void kmain(void)
{
	const char *str = "Hello cruel word!";
	char  *vidptr = (char *)0xb8000; // This is where video memory begins
	unsigned int j = 0;
	unsigned int i = 0;

	/* Clear the screen of 25 lines, 80 columns. Each element takes 2 bytes */
	while(j < 80 * 25 * 2){
		vidptr[j] = ' ';
		vidptr[j + 1] = 0x07;
		j = j + 2;
	}

	j = 0;

	/* Write the string to video memory */
	while(str[j] != '\0'){
		vidptr[i] = str[j];
		vidptr[i+1] = 0x07;
		++j;
		i = i + 2;
	}
	return;
}
