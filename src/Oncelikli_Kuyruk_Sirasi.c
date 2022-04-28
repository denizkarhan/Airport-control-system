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
