#include <stdio.h>
#include <time.h>
#include <string.h>

struct time {
	int tm_sec;
	int tm_min; 
	int tm_hour; 
	int tm_mday; 
	int tm_mon; 
	int tm_year; 
	int tm_wday; 
};

int ifs(hoje_dia,hoje_mes,hoje_ano)
{
	int i = 0;
	//int hoje_dia, hoje_mes, hoje_ano;
	int dia, mes, ano;
	
	while(i == 0) {
		printf("Digite a data de nascimento ou da primeira vacina do seu Pet\n");
		printf("No formato DD MM AAAA\n");
		scanf("%d %d %d", &dia, &mes, &ano);
		
		int vac_ano;
		vac_ano = ano+1;
		if (dia > 31 || mes > 12) {
			printf("Data Inválida\n");
			continue;
		} 
		if (ano > hoje_ano) {
			printf("O Pet Ainda não nasceu :(\n");
			continue;
		} 
		else if (ano == hoje_ano) {
			if (mes > hoje_mes) {
				printf("O Pet Ainda não nasceu :(\n");
				continue;
			} else if (mes == hoje_mes && dia > hoje_dia) {
				printf("O Pet Ainda não nasceu :(\n");	
				continue;		
			}
		}
		if (hoje_ano < vac_ano) {
			printf("Você deverá realizar a próxima vacina no dia: %d/%d/%d\n", dia, mes, vac_ano);
			break;
		}
		else if (hoje_ano == vac_ano) {
			if (hoje_mes < mes) {
				printf("Você deverá realizar a próxima vacina no dia: %d/%d/%d\n", dia, mes, vac_ano);
				break;
			} 
			else if (hoje_mes == mes && hoje_dia < dia) {
				printf("Você deverá realizar a próxima vacina no dia: %d/%d/%d\n", dia, mes, vac_ano);
				break;
			} else {	
				printf("Voce já realizou a vacina de %d/%d/%d? s/n \n", dia,mes,vac_ano);
				char opt[10];
				scanf("%s", opt);
				if (strcmp(opt,"s")==0) {
					vac_ano++;
					ifs2(hoje_dia,hoje_mes,hoje_ano,dia,mes,ano,vac_ano);
				} else {
					printf("! Você já deve realizar essa vacina !\n");
				}
				break;
			}
		} else {
			printf("Voce já realizou a vacina de %d/%d/%d? s/n \n", dia,mes,vac_ano);
			char opt[10];
			scanf("%s", opt);
			if (strcmp(opt, "s")==0) {
				vac_ano++;
				ifs2(hoje_dia,hoje_mes,hoje_ano,dia,mes,ano,vac_ano);
			} else {
				printf("! Você já deve realizar essa vacina !\n");
			}
			getchar();
			break;
		}
	}
}

int ifs2(hoje_dia,hoje_mes,hoje_ano,dia,mes,ano,vac_ano)
{
	int i = 0; 
	while(i == 0) {
		if (hoje_ano < vac_ano) {
			printf("Você deverá realizar a próxima vacina no dia: %d/%d/%d\n", dia, mes, vac_ano);
			break;
		}
		else if (hoje_ano == vac_ano) {
			if (hoje_mes < mes) {
				printf("Você deverá realizar a próxima vacina no dia: %d/%d/%d\n", dia, mes, vac_ano);
				break;
			} 
			else if (hoje_mes == mes && hoje_dia < dia) {
				printf("Você deverá realizar a próxima vacina no dia: %d/%d/%d\n", dia, mes, vac_ano);
				break;
			} else {	
				printf("Voce já realizou a vacina de %d/%d/%d? s/n \n", dia,mes,vac_ano);
				char opt[10];
				scanf("%s", opt);
				if (strcmp(opt,"s")==0) {
					vac_ano++;
					ifs2(hoje_dia,hoje_mes,hoje_ano,dia,mes,ano,vac_ano);
				} else {
					printf("! Você já deve realizar essa vacina !\n");
				}
				break;
			}
		} else {
			printf("Voce já realizou a vacina de %d/%d/%d? s/n \n", dia,mes,vac_ano);
			char opt[10];
			scanf("%s", opt);
			if (strcmp(opt, "s")==0) {
				vac_ano++;
				ifs2(hoje_dia,hoje_mes,hoje_ano,dia,mes,ano,vac_ano);
			} else {
				printf("! Você já deve realizar essa vacina !\n");
			}
			getchar();
			break;
		}
	}
}

int main(void)
{
	struct tm *local;
	
	time_t t;
	t= time(NULL);
	local=localtime(&t);
	
	int hoje_dia, hoje_mes, hoje_ano;
	int dia, mes, ano;
	int vac_ano; 
	hoje_dia=local->tm_mday;
	hoje_mes=local->tm_mon+1;
	hoje_ano=local->tm_year+1900;
	
	int i = 0;
	printf("-=> Seja Bem-Vindo ao HELPet <=-\n");
	ifs(hoje_dia,hoje_mes,hoje_ano,dia,mes,ano,vac_ano);
	
}
