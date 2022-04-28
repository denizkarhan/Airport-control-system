#ifndef LIBRARY_H
# define LIBRARY_H

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

#endif
