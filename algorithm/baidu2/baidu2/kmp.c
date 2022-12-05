
typedef struct Str {
	char str[maxSize];
	int length;
} Str;

void getNext(Str ms, int next[]) {
	next[0] = -1;
	if (ms.length == 1) return;

	next[1] = 0;
	int i = 0, j = -1;
	int cn = 0;
	int pos = 2;
	while (pos < ms.length) {
		if (next[pos - 1] == ms.str[cn]) {
			next[pos++] = cn + 1;
		}
		else if (cn > 0) {
			cn = next[cn];
		}
		else {
			next[pos++] = 0;
		}
	}


}


int getIndexOf(Str ss, Str ms) {
	if (ss.length < 1 || ms.length < 1 || ss.length < ms.length) {
		return -1;
	}
	int si = 0, mi = 0;

	int next[maxSize];

	getNext(ms, next);

	while (si < ss.length && mi < ms.length) {
		if (ss.str[si] == ms.str[mi]) {
			++si;
			++mi;
		}
		else if (next[mi] == -1) {
			++si;
		}
		else {
			mi = next[mi];
		}
	}

	return mi == ms.length ? si - mi : -1;
}

