#include "boolean.h"
#include "Header_KA.h"
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
    printf("Nama Kereta Api\t\t: %s\n", data->namaKeretaApi);
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
    printf("[%d] %s\n", i, data->namaKeretaApi);
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
      printf("=====Menu Tiket %s=====\n", data->namaKeretaApi);
      printf("Kapasitas Penumpang\t: %d orang\n", data->daya_tampung);
      printf("Tiket Tersedia\t\t: %d tiket\n", data->sisa_tiket);
      printf("\nDetail Kelas Kereta\n");
      printf("1. atas\t- Rp.%d/orang\nTiket "
             "Tersedia\t: %d tiket\n",
             data->harga_atas, data->kelas_atas);
      printf("===================================\n");
      printf("2. menengah\t- Rp.%d/orang\nTiket "
             "Tersedia\t: %d tiket\n",
             data->harga_menengah, data->kelas_menengah);
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
      if (pilih_kelas == data->id_atas && data->kelas_atas != 0 &&
          pesan_jumlah <= data->kelas_atas) {
        data->kelas_atas -= pesan_jumlah;
        data->sisa_tiket -= pesan_jumlah;
        return 1;
        break;
      } else if (pilih_kelas == data->id_menengah && data->kelas_menengah != 0 &&
                 pesan_jumlah <= data->kelas_menengah) {
        data->kelas_menengah -= pesan_jumlah;
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
void hargaNaik(KA *data, int sz_atas1, int sz_menengah1, int sz_biasa1,
               int sz_atas2, int sz_menengah2, int sz_biasa2,
               int sz_atas3, int sz_menengah3, int sz_biasa3,
               int harga_atas1, int harga_menengah1, int harga_biasa1,
               int harga_atas2, int harga_menengah2, int harga_biasa2,
               int harga_atas3, int harga_menengah3, int harga_biasa3,
               int pilih_ka) {

  if (pilih_ka == 1) {
    if (data->kelas_atas <= (int)sz_atas1 * 0.4) {
      data->harga_atas = (int)(harga_atas1 * 1.2);
    }
    if (data->kelas_menengah <= (int)sz_menengah1 * 0.4) {
      data->harga_menengah = (int)(harga_menengah1 * 1.2);
    }
    if (data->kelas_biasa <= (int)sz_biasa1 * 0.4) {
      data->harga_biasa = (int)(harga_biasa1 * 1.2);
    }
  } else if (pilih_ka == 2) {
    if (data->kelas_atas <= (int)sz_atas2 * 0.4) {
      data->harga_atas = (int)(harga_atas2 * 1.2);
    }
    if (data->kelas_menengah <= (int)sz_menengah2 * 0.4) {
      data->harga_menengah = (int)(harga_menengah2 * 1.2);
    }
    if (data->kelas_biasa <= (int)sz_biasa2 * 0.4) {
      data->harga_biasa = (int)(harga_biasa2 * 1.2);
    }
  } else if (pilih_ka == 3) {
    if (data->kelas_atas <= (int)sz_atas3 * 0.4) {
      data->harga_atas = (int)(harga_atas3 * 1.2);
    }
    if (data->kelas_menengah <= (int)sz_menengah3 * 0.4) {
      data->harga_menengah = (int)(harga_menengah3 * 1.2);
    }
    if (data->kelas_biasa <= (int)sz_biasa3 * 0.4) {
      data->harga_biasa = (int)(harga_biasa3 * 1.2);
    }
  }
}

// prosedur untuk menghitung keuntungan
void hitungKeuntungan(KA *data, int pilih_ka, int pilih_kelas,
                      int pesan_tiket) {
  while (data != NULL) {
    if (pilih_ka == data->kode_kereta) {
      if (pilih_kelas == data->id_atas &&
          pesan_tiket <= data->kelas_atas) {
        data->keuntungan_kereta += pesan_tiket * data->harga_atas;
      } else if (pilih_kelas == data->id_menengah &&
                 pesan_tiket <= data->kelas_menengah) {
        data->keuntungan_kereta += pesan_tiket * data->harga_menengah;
      } else if (pilih_kelas == data->id_biasa &&
                 pesan_tiket <= data->kelas_biasa) {
        data->keuntungan_kereta += pesan_tiket * data->harga_biasa;
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
    printf("-----Total Biaya Kereta %s-----\n", data->namaKeretaApi);
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
