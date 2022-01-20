#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct kuyruk{
	int	oncelik_id;
	int	ucak_id;
	int	talep_edilen_inis_saati;
	int	inis_saati;
	int	ucak_bekleme_suresi;
	int	ucak_kalkis_saati;
	struct kuyruk *next;
};

struct	kuyruk *root = NULL;
char	ucak_adi[4][25] = {"Ambulans Ucagina", "Savas Ucagina", "Yolcu ucagina", "Kargo ucagina"};
int		saat = 0, i = -1, j, s;
int 	oncelik_id[50];
int 	ucak_id[50];
int 	talep_edilen_inis_saati[50];
int		inen_ucaklar_indisi[50];
int		bekleme_suresi[50];
void	input_txt();
void	inis_pisti_kullanim_sirasi();
void	output_txt();
void	oncelikli_kuyruk(int l);

int	main(){
	root = (struct kuyruk*)malloc(sizeof(struct kuyruk));
	struct kuyruk *iter = root;
	input_txt();
	output_txt();
	return (0);
}

void	input_txt(){
	FILE * input_dosyasi;
	input_dosyasi = fopen("input.txt", "r");
	char	dizi[50];
	fgets(dizi, 50, input_dosyasi);
	while (fscanf(input_dosyasi, "%d %d %d", &oncelik_id[i], &ucak_id[i], &talep_edilen_inis_saati[++i]) == 3); s = i;
	for (i = 0 ; i < 50 ; i++){bekleme_suresi[i] = 0; inen_ucaklar_indisi[i] = -1;}
	inis_pisti_kullanim_sirasi();
	fclose(input_dosyasi);
}
void	inis_pisti_kullanim_sirasi(){
	printf("\t\tHAVALIMANI UCUS YONETIM SISTEMI\n");
	int i = -1, j, indis;
	while (++i < 24 && ++saat < 25){
		int	min = 5;
		int	total = 0;
		for (j = 0 ; j < 50 ; j++){
			if (inen_ucaklar_indisi[j] == 1)	{continue;}
			if (talep_edilen_inis_saati[j] == saat && bekleme_suresi[j] <= 3){ total++;
				if (bekleme_suresi[j] == 3)		{indis = j; break;}
				else if (oncelik_id[j] < min)	{min = oncelik_id[j]; indis = j;}
			}
		}
		if (total == 0)	{continue;}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN);
		printf("\n%d numarali %s saat %d icin inis izni verilmistir.\n", ucak_id[indis], ucak_adi[oncelik_id[indis] - 1], saat);
		inen_ucaklar_indisi[indis] = 1;
		oncelikli_kuyruk(indis);
		for (j = 0 ; j < 50 ; j++){
			if (talep_edilen_inis_saati[j] == saat && j != indis){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED);
					printf("%d numarali %s %d numarali ucagin inmesi sebebiyle inis saati ertelenmistir.\n", ucak_id[j], ucak_adi[oncelik_id[j] - 1], ucak_id[indis]);
					talep_edilen_inis_saati[j]++;
					bekleme_suresi[j]++;}
		}
		sleep(1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY);
		printf("-----------------------------------------------------------------------------------------------------");
	}
}
void	oncelikli_kuyruk(int l){		
	root -> oncelik_id = oncelik_id[l];
	root -> ucak_id = ucak_id[l];
	root -> talep_edilen_inis_saati = talep_edilen_inis_saati[l] - bekleme_suresi[l];
	root -> inis_saati = talep_edilen_inis_saati[l];
	root -> ucak_bekleme_suresi = bekleme_suresi[l];
	root -> ucak_kalkis_saati = (talep_edilen_inis_saati[l] + 1) % 24;
	root -> next = (struct kuyruk *)malloc(sizeof(struct kuyruk));
	root = root -> next;
}
void	output_txt(){
	FILE *kalkis;
	kalkis = fopen("output.txt", "a");
	fprintf(kalkis, "Oncelik ID | Ucak ID | Talep edilen inis saati | inis saati | gecikme suresi | kalkis saati\n");
	for (j = 0 ; j < s ; j++){
		if (inen_ucaklar_indisi[j] == 1){fprintf(kalkis, "%d	       %d		   %d.00		%d.00	     %d saat		%d.00\n", oncelik_id[j], ucak_id[j], (talep_edilen_inis_saati[j]- bekleme_suresi[j]), talep_edilen_inis_saati[j]%24, bekleme_suresi[j], (talep_edilen_inis_saati[j] + 1)%24);}
		else{fprintf(kalkis, "%d	       %d		   %d.00		izin yok	     izin yok	izin yok\n", oncelik_id[j], ucak_id[j], ((talep_edilen_inis_saati[j]- bekleme_suresi[j])));}
	}
	fclose(kalkis);
}


