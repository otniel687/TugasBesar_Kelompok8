#include "boolean.h"
#include "kaHeader.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// prosedur untuk mencetak informasi kereta api
void cetakInformasi(KA *data) {
  system("cls"); //linux = clear, windows = cls
  char *choice;
  char *key;

  choice = (char *)malloc(1 * sizeof(char));
  key = (char *)malloc(1 * sizeof(char));
  key = "y";

  while (data != NULL) {
    printf("Nama Kereta Api\t\t: %s\n", data->namaKA);
    printf("Destinasi\t\t: %s\n", data->destinasi);
    printf("Jam Keberangkatan\t: %s\n", data->jam_keberangkatan);
    printf("Daya Tampung\t\t: %d Orang\n", data->daya_tampung);
    printf("Tiket Tersedia\t\t: %d Tiket\n", data->sisa_tiket);
    printf("Kelas Tersedia\t\t: %s\n", data->jenis_kelas);
    printf("\n=======================================================\n\n");
    data = data->nextNode;
  }

  printf("Apakah anda ingin keluar? (enter y to exit/any key to continue) : ");
  scanf("%s", choice);
  puts("");

  if (strcmp(choice, key) == 0) {
    exit(1);
  }

  system("cls"); //linux = clear, windows = cls
}

// prosedur untuk menampilkan list kereta
void daftarKa(KA *data) {
  system("cls"); //linux = clear, windows = cls
  int i = 1;

  printf("=====Daftar KA Tersedia=====\n");
  while (data != NULL) {
    printf("[%d] %s\n", i, data->namaKA);
    i++;
    data = data->nextNode;
  }
}

// prosedur untuk memilih kelas dan membeli tiket
void pilihanKa(KA *data, int pilih, int pesan_jumlah) {
  system("cls"); //linux = clear, windows = cls
  int i = 1;

  while (data != NULL) {
    if (pilih == data->kode_kereta) {
      printf("=====Menu Tiket %s=====\n", data->namaKA);
      printf("Kapasitas Penumpang\t: %d orang\n", data->daya_tampung);
      printf("Tiket Tersedia\t\t: %d tiket\n", data->sisa_tiket);
      printf("\nDetail Kelas Kereta\n");
      printf("1. Eksekutif\t- Rp.%d/orang\nTiket "
             "Tersedia\t: %d tiket\n",
             data->harga_eksekutif, data->kelas_eksekutif);
      printf("===================================\n");
      printf("2. Bisnis\t- Rp.%d/orang\nTiket "
             "Tersedia\t: %d tiket\n",
             data->harga_bisnis, data->kelas_bisnis);
      printf("===================================\n");
      printf("3. Biasa\t- Rp.%d/orang\nTiket "
             "Tersedia\t: %d tiket\n",
             data->harga_biasa, data->kelas_biasa);
      printf("===================================\n");

      break;
    }
    data = data->nextNode;
  }
}

// prosedur untuk menghitung operasi pemesanan tiket
boolean operasitiket(KA *data, int pilih_kelas, int pesan_jumlah,
                     int pilih_ka) {

  while (data != NULL) {
    if (pilih_ka == data->kode_kereta) {
      if (pilih_kelas == data->id_eksekutif && data->kelas_eksekutif != 0 &&
          pesan_jumlah <= data->kelas_eksekutif) {
        data->kelas_eksekutif -= pesan_jumlah;
        data->sisa_tiket -= pesan_jumlah;
        return 1;
        break;
      } else if (pilih_kelas == data->id_bisnis && data->kelas_bisnis != 0 &&
                 pesan_jumlah <= data->kelas_bisnis) {
        data->kelas_bisnis -= pesan_jumlah;
        data->sisa_tiket -= pesan_jumlah;
        return 1;
        break;
      } else if (pilih_kelas == data->id_biasa && data->kelas_biasa != 0 &&
                 pesan_jumlah <= data->kelas_biasa) {
        data->kelas_biasa -= pesan_jumlah;
        data->sisa_tiket -= pesan_jumlah;
        return 1;
        break;
      }
    }

    data = data->nextNode;
  }

  return 0;
}

// prosedur yang digunakan untuk menghitung kenaikan harga 20%
void hargaNaik(KA *data, int sz_eksekutif1, int sz_bisnis1, int sz_biasa1,
               int sz_eksekutif2, int sz_bisnis2, int sz_biasa2,
               int sz_eksekutif3, int sz_bisnis3, int sz_biasa3,
               int harga_eksekutif1, int harga_bisnis1, int harga_biasa1,
               int harga_eksekutif2, int harga_bisnis2, int harga_biasa2,
               int harga_eksekutif3, int harga_bisnis3, int harga_biasa3,
               int pilih_ka) {

  if (pilih_ka == 1) {
    if (data->kelas_eksekutif <= (int)sz_eksekutif1 * 0.4) {
      data->harga_eksekutif = (int)(harga_eksekutif1 * 1.2);
    }
    if (data->kelas_bisnis <= (int)sz_bisnis1 * 0.4) {
      data->harga_bisnis = (int)(harga_bisnis1 * 1.2);
    }
    if (data->kelas_biasa <= (int)sz_biasa1 * 0.4) {
      data->harga_biasa = (int)(harga_biasa1 * 1.2);
    }
  } else if (pilih_ka == 2) {
    if (data->kelas_eksekutif <= (int)sz_eksekutif2 * 0.4) {
      data->harga_eksekutif = (int)(harga_eksekutif2 * 1.2);
    }
    if (data->kelas_bisnis <= (int)sz_bisnis2 * 0.4) {
      data->harga_bisnis = (int)(harga_bisnis2 * 1.2);
    }
    if (data->kelas_biasa <= (int)sz_biasa2 * 0.4) {
      data->harga_biasa = (int)(harga_biasa2 * 1.2);
    }
  } else if (pilih_ka == 3) {
    if (data->kelas_eksekutif <= (int)sz_eksekutif3 * 0.4) {
      data->harga_eksekutif = (int)(harga_eksekutif3 * 1.2);
    }
    if (data->kelas_bisnis <= (int)sz_bisnis3 * 0.4) {
      data->harga_bisnis = (int)(harga_bisnis3 * 1.2);
    }
    if (data->kelas_biasa <= (int)sz_biasa3 * 0.4) {
      data->harga_biasa = (int)(harga_biasa3 * 1.2);
    }
  }
}

// prosedur untuk menghitung keuntungan
void hitungKeuntungan(KA *data, int pilih_ka, int pilih_kelas,
                      int pesan_jumlah_tiket) {
  while (data != NULL) {
    if (pilih_ka == data->kode_kereta) {
      if (pilih_kelas == data->id_eksekutif &&
          pesan_jumlah_tiket <= data->kelas_eksekutif) {
        data->keuntungan_kereta += pesan_jumlah_tiket * data->harga_eksekutif;
      } else if (pilih_kelas == data->id_bisnis &&
                 pesan_jumlah_tiket <= data->kelas_bisnis) {
        data->keuntungan_kereta += pesan_jumlah_tiket * data->harga_bisnis;
      } else if (pilih_kelas == data->id_biasa &&
                 pesan_jumlah_tiket <= data->kelas_biasa) {
        data->keuntungan_kereta += pesan_jumlah_tiket * data->harga_biasa;
      }
    }

    data = data->nextNode;
  }
}

// prosedur untuk mencetak informasi keuntungan
void cetakKeuntungan(KA *data) {
  system("cls"); //linux = clear, windows = cls
  int total_keuntungan = 0;
  char *choice;
  char *key;

  choice = (char *)malloc(1 * sizeof(char));
  key = (char *)malloc(1 * sizeof(char));
  key = "y";

  while (data != NULL) {
    printf("-----Total Biaya Kereta %s-----\n", data->namaKA);
    printf("Pendapatan\t: Rp.%d\n", data->keuntungan_kereta);
    printf("Modal Dasar\t: Rp.%d\n", MODAL_DASAR);
    printf("Keuntungan\t: Rp.%d\n\n", data->keuntungan_kereta - MODAL_DASAR);

    total_keuntungan += data->keuntungan_kereta;

    data = data->nextNode;
  }

  printf("=========================================\n");
  printf("Total pendapatan Kereta Api Ku\n==> Rp.%d\n\n", total_keuntungan);
  printf("Apakah anda ingin keluar?[enter y to exit/any key to continue] = ");
  scanf("%s", choice);
  puts("");

  if (strcmp(choice, key) == 0) {
    exit(1);
  }

  system("cls"); //linux = clear, windows = cls
}