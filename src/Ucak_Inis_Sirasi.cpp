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
