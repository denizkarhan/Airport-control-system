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
