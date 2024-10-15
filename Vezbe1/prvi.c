#include <stdio.h>

int main() {
    int novcanice[] = {1, 2, 5, 10, 20, 50, 100};
	int suma;
	int brojaci[] = {0, 0, 0, 0, 0, 0, 0};
	printf("Uneti zeljenu sumu: ");
	scanf("%d", &suma);
	int brojac = 0;
	while(suma > 0) {
		for(int i = 6; i >= 0; i--) {
			while(suma >= novcanice[i]) {
				suma -= novcanice[i];
				brojaci[i]++;
			}
		}
	}
	for(int i = 0; i < 7; i++) {
		if(brojaci[i] != 0) {
			printf("Potrebno je %d novcanica od %d\n", brojaci[i], novcanice[i]);
		}
	}
	return 0;
}