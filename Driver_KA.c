#include "Header_KA.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main() {
  // inisialisasi struct yang dibutuhkan untuk membuat node kereta api
  int pilihan_menuAwal, pilih_ka, pilih_kelas, pesan_tiket, sistemTiket;

  KA *kereta_api1 = (KA *)malloc(sizeof(KA) * 1);
  KA *kereta_api2 = (KA *)malloc(sizeof(KA) * 1);
  KA *kereta_api3 = (KA *)malloc(sizeof(KA) * 1);

  kereta_api1->kode_kereta = 1;
  strcpy(kereta_api1->namaKeretaApi, "Malabar");
  strcpy(kereta_api1->destinasi, "Palembang - Medan");
  strcpy(kereta_api1->jam_keberangkatan, "12.25 WIB");
  strcpy(kereta_api1->jenis_kelas, "atas | menengah | Biasa");
  kereta_api1->daya_tampung = 200;
  kereta_api1->sisa_tiket = 200;
  kereta_api1->kelas_atas = 500;
  kereta_api1->harga_atas = 175000;
  kereta_api1->kelas_menengah = 60;
  kereta_api1->harga_menengah = 110000;
  kereta_api1->kelas_biasa = 90;
  kereta_api1->harga_biasa = 65000;
  kereta_api1->id_atas = 1;
  kereta_api1->id_menengah = 2;
  kereta_api1->id_biasa = 3;
  kereta_api1->keuntungan_kereta = 0;
  kereta_api1->nextNode = kereta_api2;

  kereta_api2->kode_kereta = 2;
  strcpy(kereta_api2->namaKeretaApi, "Ranggajati");
  strcpy(kereta_api2->destinasi, "Medan - Balige");
  strcpy(kereta_api2->jam_keberangkatan, "17.00 WIB");
  strcpy(kereta_api2->jenis_kelas, "atas | menengah | Biasa");
  kereta_api2->daya_tampung = 115;
  kereta_api2->sisa_tiket = 115;
  kereta_api2->kelas_atas = 25;
  kereta_api2->harga_atas = 160000;
  kereta_api2->kelas_menengah = 30;
  kereta_api2->harga_menengah = 100000;
  kereta_api2->kelas_biasa = 60;
  kereta_api2->harga_biasa = 60000;
  kereta_api2->id_atas = 1;
  kereta_api2->id_menengah = 2;
  kereta_api2->id_biasa = 3;
  kereta_api2->keuntungan_kereta = 0;
  kereta_api2->nextNode = kereta_api3;

  kereta_api3->kode_kereta = 3;
  strcpy(kereta_api3->namaKeretaApi, "Ciremai");
  strcpy(kereta_api3->destinasi, "Siantar - Batam");
  strcpy(kereta_api3->jam_keberangkatan, "08.45 WIB");
  strcpy(kereta_api3->jenis_kelas, "atas | menengah | Biasa");
  kereta_api3->daya_tampung = 80;
  kereta_api3->sisa_tiket = 80;
  kereta_api3->kelas_atas = 5;
  kereta_api3->harga_atas = 140000;
  kereta_api3->kelas_menengah = 25;
  kereta_api3->harga_menengah = 105000;
  kereta_api3->kelas_biasa = 50;
  kereta_api3->harga_biasa = 70000;
  kereta_api3->id_atas = 1;
  kereta_api3->id_menengah = 2;
  kereta_api3->id_biasa = 3;
  kereta_api3->keuntungan_kereta = 0;
  kereta_api3->nextNode = NULL;

  // variable penampung yang bersifat constant untuk data size kelas
  int const sz_atas1 = kereta_api1->kelas_atas;
  int const sz_menengah1 = kereta_api1->kelas_menengah;
  int const sz_biasa1 = kereta_api1->kelas_biasa;
  int const sz_atas2 = kereta_api2->kelas_atas;
  int const sz_menengah2 = kereta_api2->kelas_menengah;
  int const sz_biasa2 = kereta_api2->kelas_biasa;
  int const sz_atas3 = kereta_api3->kelas_atas;
  int const sz_menengah3 = kereta_api3->kelas_menengah;
  int const sz_biasa3 = kereta_api3->kelas_biasa;

  // variable penampung yang bersifat constant untuk data harga tiket
  int const harga_atas1 = kereta_api1->harga_atas;
  int const harga_menengah1 = kereta_api1->harga_menengah;
  int const harga_biasa1 = kereta_api1->harga_biasa;
  int const harga_atas2 = kereta_api2->harga_atas;
  int const harga_menengah2 = kereta_api2->harga_menengah;
  int const harga_biasa2 = kereta_api2->harga_biasa;
  int const harga_atas3 = kereta_api3->harga_atas;
  int const harga_menengah3 = kereta_api3->harga_menengah;
  int const harga_biasa3 = kereta_api3->harga_biasa;

// menu awal
menu_awal:
  printf("======Informasi Kereta Api ======\n");
  printf("[1] Informasi Kereta Api\n");
  printf("[2] Beli Tiket\n");
  printf("[3] Keuntungan Kereta Api Ku\n");
  printf("[4] Keluar\n");
  printf("\nPilih : ");
  scanf("%d", &pilihan_menuAwal);

  switch (pilihan_menuAwal) {
    // case 1 digunakan untuk menampilkan informasi detail mengenai kereta api
  case 1:
    cetakInformasi(kereta_api1);
    goto menu_awal;

    // case 2 digunakan untuk menampilkan list kereta api yang ingin dipilih
    // untuk membeli tiket
  case 2:
  backTiket:
    daftarKa(kereta_api1);

  backKereta:
    printf("\nPilih Kereta : ");
    scanf("%d", &pilih_ka);
    if (pilih_ka > 3) {
      printf("\nInputan yang anda masukkan salah!\n");
      goto backKereta;
    }

    // prosedur yang digunakan untuk menghitung harga tiket naik 20%
    hargaNaik(kereta_api1, sz_atas1, sz_menengah1, sz_biasa1, sz_atas2,
              sz_menengah2, sz_biasa2, sz_atas3, sz_menengah3, sz_biasa3,
              harga_atas1, harga_menengah1, harga_biasa1, harga_atas2,
              harga_menengah2, harga_biasa2, harga_atas3, harga_menengah3,
              harga_biasa3, pilih_ka);

    // prosedur untuk memilih kereta api
    pilihanKa(kereta_api1, pilih_ka, pesan_tiket);

    printf("\nPilih Kelas\t: ");
    scanf("%d", &pilih_kelas);

    printf("Jumlah Tiket\t: ");
    scanf("%d", &pesan_tiket);

    // prosedur yang digunakan untuk menghitung keuntungan masing masing kereta
    hitungKeuntungan(kereta_api1, pilih_ka, pilih_kelas, pesan_tiket);

    // fungsi operasi pembelian tiket yang mengembalikan nilai boolean
    sistemTiket =
        operasitiket(kereta_api1, pilih_kelas, pesan_tiket, pilih_ka);

    if (sistemTiket == 1) {
      system("cls");
      printf("----%d tiket pesanan dibeli [Pembelian "
             "Berhasil]----\n",
             pesan_tiket);
    } else if (sistemTiket == 0) {
      system("cls");
      printf("----Tiket pesanan tidak sesuai [Pembelian Gagal]----\n\n");
    }

    goto menu_awal;

    // case 3 digunakan untuk mencetak keuntungan dari total dan masing masing kereta
  case 3:
    cetakKeuntungan(kereta_api1);
    goto menu_awal;

    // case 4 = exit
  case 4:
    system("cls");
    printf("~Terima kasih sudah menggunakan aplikasi Kereta Api Ku~\n");
    exit(1);

  default:
    printf("Keywords yang anda masukkan salah!\n");
    goto menu_awal;
  }

  return 0;
}
