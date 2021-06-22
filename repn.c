
// JULIO 2020. CÉSAR BORAO MORATINOS: repn.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

enum{
	Max = 5
};

 // return the converted value if success or -1 if failed
int
convert(char *arg) {

	char *endptr;
	long repnum;
	repnum = strtol(arg,&endptr,10);
	if (endptr == arg)
		return -1;
	return repnum;
}

void
repeat(int argc, char *argv[]) {

	int repnum;
	if ((repnum = convert(argv[0])) < 0)
		errx(EXIT_FAILURE,"error: not a valid number");

	for (size_t i = 1; i < argc; i++) {
		char *word = argv[i];
		int letnum = Max;

		if (strlen(word) < Max)
			letnum = strlen(word);

		char str[letnum];
		strncpy(str,word,letnum);
		str[letnum] = '\0';
		for (size_t j = 0; j < repnum; j++) {
			fprintf(stdout, "%s", str);
		}
		fprintf(stdout, "\n");
	}
}

void
reverse(int argc, char *argv[]) {

	int repnum;
	if ((repnum = convert(argv[1])) < 0)
		errx(EXIT_FAILURE,"error: not a valid number");

	for (size_t i = 2; i < argc; i++) {
		char *word = argv[i];

		int letnum = Max;
		if (strlen(word) < Max) {
			letnum = strlen(word);
			word += strlen(word)-1;
		} else {
			word += Max-1;
		}

		char str[letnum];
		for (size_t j = 0; j < letnum; j++) {
			str[j] = *word;
			word--;
		}
		str[letnum] = '\0';

		for (size_t k = 0; k < repnum; k++) {
			fprintf(stdout, "%s", str);
		}
		fprintf(stdout, "\n");
	}
}

int
main(int argc, char *argv[]) {
	argv++;
	argc--;

	if (argc == 0)
		errx(EXIT_FAILURE,"usage: repn [-r] n [string ...]");

	if (strcmp(argv[0],"-r") == 0) {
		if(argc == 1)
			errx(EXIT_FAILURE,"usage: repn [-r] n [string ...]");

		reverse(argc,argv);
	} else {
		repeat(argc,argv);
	}
	exit(EXIT_SUCCESS);
}
