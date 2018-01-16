#include "stdafx.h"

#define MAX_DIGITS 9
#define CHAR_MAX (9+1)

char *fu = "Fu";
char *py[] = { "ling", "yi", "er","san","si","wu","liu","qi","ba","jiu" };
char *wei[] = { "","Shi","Bai","Qian"}; // 10 // add "";
char *wei1[] = { "", "Wan", "Yi","Zhao" }; // 10^4

int PATA1082() { // todo: it's vague, not very clear
	char temp[CHAR_MAX + 1];
	int tempi, flag, len;
	//scanf("%d", &tempi);
	scanf("%s", temp);

	if (temp[0] == '0') { //special input: 0 ~ 3 point
		printf("ling");
		return 0;
	}

	if (temp[0] == '-') {
		flag = -1;
		len = strlen(temp) - 1;
	}
	else {
		flag = 1;
		len = strlen(temp);
	}

	if (flag == -1) {
		printf("%s", fu);
	}

	int section = len/4+((len%4)?1:0); // (len%4)?1:0 -> ((len%4)?1:0)
	int end, start = (flag == -1) ? 1 : 0 , sec_s;
	char c;
	for (int sec = section; sec > 0; sec--) {
		end = strlen(temp) - 1 - (sec - 1) * 4; // strlen(temp) -1 is the end index of temp string
		int array[4] = { 0 }; // todo: use bool is clear
		for (int i = start; i <= end; i++) {
			// todo: use a array to save
			if (temp[i] == '0') {
				bool ze = false;
				for (int k = i; k <= end; k++) {
					if (temp[k] != '0') {
						ze = true;
						i = k-1; // compensate i++
						break;
					}
				}
				if(ze){
						printf(" ling"); /// 100800000 two zeros // if not test (in random form by my random mind)
				}
				else {
					break;
				}
			}
			else {
				array[end-i] = 1;
				if (i != start || ((flag == -1) && (i = start))) // not through the main test case // complicated
					printf(" ");
				printf("%s", py[temp[i] - '0']);
				if (end != i)
					printf(" %s", wei[end - i]);
			}
		}
		if (sec != 1) { // section -> sec
			if(array[0]+array[1]+array[2]+array[3])
				printf(" %s", wei1[sec - 1]); // 1 0000 0800
		}
		start = end + 1;
	}
	return 0;
}