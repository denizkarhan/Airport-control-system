#include <stdio.h>
#include <stdlib.h>

int		saat = 0;
int 	oncelik_id[28];
int 	ucak_id[28];
int 	talep_edilen_inis_saati[28];
int		inen_ucaklar_indisi[28];
int		bekleme_suresi[28];

char	ucak_turu[4][25] = {"Ambulans Ucagina", "Savas Ucagina", "Yolcu ucagina", "Kargo ucagina"};

void	input_txt();
void	inis_pisti_kullanim_sirasi();
void	output_txt();

int	main(){
	input_txt();
	output_txt();
	return (0);
}

void	input_txt(){
	FILE * input_dosyasi;
	input_dosyasi = fopen("input.txt", "r");
	char	dizi[50];
	int 	i = -1;
	fgets(dizi, 50, input_dosyasi);
	while (fscanf(input_dosyasi, "%d %d %d", &oncelik_id[i], &ucak_id[i], &talep_edilen_inis_saati[++i]) == 3);
	for (i = 0 ; i < 28 ; i++){bekleme_suresi[i] = 0; inen_ucaklar_indisi[i] = -1;}
	inis_pisti_kullanim_sirasi();
	fclose(input_dosyasi);
}

void	inis_pisti_kullanim_sirasi(){
	printf("\t\tHAVALIMANI UCUS YONETIM SISTEMI\n");
	int i = -1, j, indis;
	while (++i < 24 && ++saat < 25){
		int	min = 5;
		for (j = 0 ; j < 28 ; j++){
			if (inen_ucaklar_indisi[j] == 1)	{continue;}
			if (talep_edilen_inis_saati[j] == saat && bekleme_suresi[j] <= 3){
				if (bekleme_suresi[j] == 3)		{indis = j; break;}
				else if (oncelik_id[j] < min)	{min = oncelik_id[j]; indis = j;}
			}
		}
		printf("\n%d numarali %s saat %d icin inis izni verilmistir.\n", ucak_id[indis], ucak_turu[oncelik_id[indis] - 1], saat);
		inen_ucaklar_indisi[indis] = 1;
		for (j = 0 ; j < 28 ; j++){
			if (talep_edilen_inis_saati[j] == saat && j != indis){
					printf("%d numarali %s %d numarali ucagin inmesi sebebiyle inis saati ertelenmistir.\n", ucak_id[j], ucak_turu[oncelik_id[j] - 1], ucak_id[indis]);
					talep_edilen_inis_saati[j]++;
					bekleme_suresi[j]++;}
		}
		printf("##########################################################################################");
	}
}

void	output_txt(){
	FILE *kalkis;
	kalkis = fopen("output.txt", "a");
	fprintf(kalkis, "Oncelik ID | Ucak ID | Talep edilen inis saati | inis saati | gecikme suresi | kalkis saati\n");
	int	i;
	for (i = 0 ; i < 28 ; i++){
		if (inen_ucaklar_indisi[i] == 1){fprintf(kalkis, "%d	       %d		   %d.00		%d.00	     %d saat		%d.00\n", oncelik_id[i], ucak_id[i], (talep_edilen_inis_saati[i]- bekleme_suresi[i]), ((talep_edilen_inis_saati[i]- bekleme_suresi[i]) + bekleme_suresi[i])%24, bekleme_suresi[i], ((talep_edilen_inis_saati[i]- bekleme_suresi[i]) + bekleme_suresi[i] + 1)%24);}
		else{fprintf(kalkis, "%d	       %d		   %d.00		izin yok	     izin yok	izin yok\n", oncelik_id[i], ucak_id[i], ((talep_edilen_inis_saati[i]- bekleme_suresi[i])), ((talep_edilen_inis_saati[i]- bekleme_suresi[i]) + bekleme_suresi[i])%24, bekleme_suresi[i], ((talep_edilen_inis_saati[i]- bekleme_suresi[i]) + bekleme_suresi[i] + 1)%24);}
	}
	fclose(kalkis);
}

