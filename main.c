#include <stdio.h>
#include <stdlib.h>

int		saat = 1;
int 	oncelik_id[28];
int 	ucak_id[28];
int 	talep_edilen_inis_saati[28];
int		inen_ucaklar_indisi[28];
int		bekleme_suresi[28];
int		ucaklarin_inis_sirasi_indeksleri[28];

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
	int 	i = 0;
	fgets(dizi, 50, input_dosyasi);
	while (fscanf(input_dosyasi, "%d %d %d", &oncelik_id[i], &ucak_id[i], &talep_edilen_inis_saati[i]) == 3) i++;
	for (int m = 0 ; m < 28 ; m++){
		bekleme_suresi[m] = 0;
		inen_ucaklar_indisi[m] = -1;}
	inis_pisti_kullanim_sirasi();
	fclose(input_dosyasi);
}

void	inis_pisti_kullanim_sirasi(){
	printf("\t\tHAVALIMANI UCUS YONETIM SISTEMI\n");
	int i, j, indis;
	for (i = 0 ; i < 24 ; i++){
		int	min = 10;
		for (j = 0 ; j < 28 ; j++){
			if (inen_ucaklar_indisi[j] == 1)
				continue;
			if (talep_edilen_inis_saati[j] == saat){
				if (bekleme_suresi[j] == 3){
					indis = j;
					break;}
			 	else if (bekleme_suresi[j] > 3)
					continue;
				else if (oncelik_id[j] < min){
					min = oncelik_id[j];
					indis = j;}
			}
		}
		int temp = indis;
		ucaklarin_inis_sirasi_indeksleri[saat - 1] = indis;
		//if (i != 23)
			printf("\n%d numarali %s saat %d icin inis izni verilmistir.\n", ucak_id[indis], ucak_turu[oncelik_id[indis] - 1], saat);
		/*if (i == 23){
			for (j = 0 ; j < 28 ; j++){
				if (inen_ucaklar_indisi[j] == 1)
					continue;
				if (oncelik_id[j] < min){
					min = oncelik_id[j];
					indis = j;}
				}
				printf("\n%d numarali %s saat %d icin inis izni verilmistir.\n", ucak_id[indis], ucak_turu[oncelik_id[indis] - 1], saat);
				printf("%d numarali %s %d numarali ucagin acil inisinden dolayi inis izni verilememistir, Lutfen Sabiha gokcene ilerleyiniz.\n", ucak_id[i], ucak_turu[oncelik_id[i] - 1], ucak_id[indis]);
			}*/
		for (j = 0 ; j < 28 ; j++){
			if (talep_edilen_inis_saati[j] == saat){
				if (j != indis && j != temp){
					printf("%d numarali %s %d numarali ucagin inmesi sebebiyle inis saatiniz ertelenmistir.\n", ucak_id[j], ucak_turu[oncelik_id[j] - 1], ucak_id[indis]);
					talep_edilen_inis_saati[j]++;
					bekleme_suresi[j]++;}
			}
		}
		printf("-------------------------------------------------------------------------");
		inen_ucaklar_indisi[indis] = 1;
		saat++;
	}
}

void	output_txt(){
	FILE *kalkis;
	kalkis = fopen("output2.txt", "a");
	fprintf(kalkis, "Oncelik ID | Ucak ID | Talep edilen inis saati | inis saati | gecikme suresi | kalkis saati\n");
	for (int i = 0 ; i < 28 ; i++){
		if (inen_ucaklar_indisi[i] == 1)
			fprintf(kalkis, "%d	       %d		   %d.00		%d.00	     %d saat		%d.00\n", oncelik_id[ucaklarin_inis_sirasi_indeksleri[i]], ucak_id[ucaklarin_inis_sirasi_indeksleri[i]], (talep_edilen_inis_saati[ucaklarin_inis_sirasi_indeksleri[i]]- bekleme_suresi[ucaklarin_inis_sirasi_indeksleri[i]]), ((talep_edilen_inis_saati[ucaklarin_inis_sirasi_indeksleri[i]]- bekleme_suresi[ucaklarin_inis_sirasi_indeksleri[i]]) + bekleme_suresi[ucaklarin_inis_sirasi_indeksleri[i]])%24, bekleme_suresi[ucaklarin_inis_sirasi_indeksleri[i]], ((talep_edilen_inis_saati[ucaklarin_inis_sirasi_indeksleri[i]]- bekleme_suresi[ucaklarin_inis_sirasi_indeksleri[i]]) + bekleme_suresi[ucaklarin_inis_sirasi_indeksleri[i]] + 1)%24);
		else
			fprintf(kalkis, "%d	       %d		   %d.00		izin yok	     izin yok	izin yok\n", oncelik_id[i], ucak_id[i], ((talep_edilen_inis_saati[i]- bekleme_suresi[i])), ((talep_edilen_inis_saati[i]- bekleme_suresi[i]) + bekleme_suresi[i])%24, bekleme_suresi[i], ((talep_edilen_inis_saati[i]- bekleme_suresi[i]) + bekleme_suresi[i] + 1)%24);}
	fclose(kalkis);
}

