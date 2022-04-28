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
