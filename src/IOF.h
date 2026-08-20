// This is must-have header file
// Input Output Files

// fp = file pointer

// fopen arguments fopen(pointer to file, work type)
// r - read only, w - full clean and write, a - writing at the end of file

void cleanORcreateBF(const char *file) { // function for creating or
    FILE *fp = fopen(file, "w"); // writing to file, if not exist, create
    if (fp == NULL) {
        printf("Cannot create or clean file...\n");
        return;
    }
    fclose(fp); // closing file
}

void ISfileExists(const char *file) {
    FILE *fp = fopen(file, "r"); // only reading
    if (fp == NULL) {
        printf("File %s doesn't exist, created...\n", file);
        cleanORcreateBF(file);
    } else {
        fclose(fp);
    }
}

void read(const char *file) {
    FILE *fp = fopen(file, "r");
    if(fp == NULL) {
        printf("Cannot read file...");
        return;
    }
    fseek(fp, 0, SEEK_END); // searching end file
    long size = ftell(fp);
    rewind(fp);

    char *buf = malloc(size + 1); 
    
	if (buf == NULL) { // if memory isnt allocated, program crashed
		printf("Memory allocation failed...\n");
		fclose(fp);
		return;
	}

	fread(buf, 1, size, fp);
    buf[size] = '\0';

    printf("%s", buf);

    fclose(fp); 
    free(buf);
}

void adddata(const char *file, char *author, char *book, char *year) {
    FILE *fp = fopen(file, "a");
    if (fp == NULL) {
        printf("Cannot open file...\n");
        return;
    }
    fprintf(fp, "%s, %s, %s.\n", author, book, year); // writing to the file
    fclose(fp);
}
