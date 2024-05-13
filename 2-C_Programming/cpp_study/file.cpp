int count = 0;
FILE* file1;

file1 = fopen("list.txt", "rt");
while (!feof(file1)) {
	list[count] = (struct bmi_record*)malloc(sizeof bmi_record));
	fscanf(file1, "%s %d %d", list[count]->name, )
		count ++
}

file1 = fopen("list.txt", "wt");
for (int i = 0; i < count; i++) {
	fprintf(file1, "%d %d", list[i]->height)
}
fclose(file1);