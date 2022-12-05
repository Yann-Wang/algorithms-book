#include<stdio.h>
#include "kmp.h"

void main() {
	Str ss = {"abcab",5};
	Str ms = { "cab",3 };
	int index;
	index = getIndexOf(ss, ms);

	printf("%d\n", index);

}