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


int lihatRute() {
	rute *r;
	rute r1;
    FILE *fp;
    int n,i,j, counter=1;
    

	
	printf("\n\n-------------------------------------------------------------------");
    
    fp = fopen("rute.txt","r");
	system("cls");
	printf("LIHAT DATA RUTE");
	printf("\nData Lengkap Rute Kereta Api");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKeberangkatan  \tTujuan\t  \tKode_Rute\t   \tBisnis\t    \tPremium\n");
	while(fread(&r1,sizeof(rute),1,fp)) { 
		printf("%d\t\t%s\t\t%s\t\t%s\t%d\t%d\n",counter,r1.kbrt,r1.tjn,r1.kode,r1.bisnis,r1.premium);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
    fclose(fp);
}

int tambahRute() {
	rute *r;
	kota k1;
    FILE *fp,*fp1;
    int n,i,j;

    r = (rute*)malloc(100*sizeof(rute));
    fp = fopen("rute.txt","a+");
    fp1 = fopen("kota.txt","r");
    
	printf("TAMBAH DATA RUTE\n\n");
	char kode1[100], kode2[100], kode3[100];
    for(i=0;i<1;i++){
    	printf("Tambah Data Rute : ");
    	fflush(stdin);
        scanf("%s %s %s %d %d",r[i].kbrt,r[i].tjn,r[i].kode,&r[i].bisnis,&r[i].premium);
        while(fread(&k1,sizeof(kota),1,fp1)) {
            if(strcmp(r[i].kbrt,k1.nama)==0) {
            	strcpy(kode1,k1.kode);
			} 
			
			if (strcmp(r[i].tjn,k1.nama)==0) {
				strcpy(kode2,k1.kode);
			}
			
			strcpy(kode3,strcat(kode1,"-"));
			strcpy(r[i].kode,(strcat(kode3,kode2)));
        }
        
        fwrite(r+i,sizeof(rute),1,fp);
    }
    
    printf("\n-----------------------------------------");
    printf("\nData Berhasil Ditambahkan\n");
    printf("------------------------------------------");
    
    fclose(fp);
    
    kelolaRute();
}


int hapusRute() {
	int i, j, found=0;
    rute r1;
    FILE *fp, *fp1;
    char kode[100];
    fp = fopen("rute.txt","r");
	system("cls");
	lihatRute();
    
    printf("\nDelete Rute : DELETE_");
    fflush(stdin);
    scanf("%[^\n]s",kode);

    fp = fopen("rute.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&r1,sizeof(rute),1,fp)){
        if(strcmp(r1.kode,kode)==0){
            found = 1;
        }
        else
            fwrite(&r1,sizeof(rute),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("rute.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&r1,sizeof(rute),1,fp1)){
            fwrite(&r1,sizeof(rute),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nNot Found.....\n");
}

int kelolaRute() {
	int i, j, counter=1;
    rute r1;
    rute *r;
    FILE *fp;
	
	fp = fopen("rute.txt","r");

	system("cls");
	printf("LIHAT DATA RUTE");
	printf("\nData Lengkap Rute Kereta Api");
	printf("\n-------------------------------------------------------------------\n");
    
    printf("No\t\tKeberangkatan\tTujuan\t\tKode_Rute\t\tBisnis\t\tPremium\n");
	while(fread(&r1,sizeof(rute),1,fp)) { 
		printf("%d\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\n",counter,r1.kbrt,r1.tjn,r1.kode,r1.bisnis,r1.premium);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
	
	printf("\n\n1. Tambah Data Rute");
	printf("\n2. Lihat Data Rute");
	printf("\n3. Edit Data Rute");
	printf("\n4. Delete Data Rute");
	printf("\n99. Menu Utama");
	
	printf("\n\nPilihan : ");
	int choice;
	fflush(stdin);
	scanf("%d",&choice);
	
	switch(choice) {
		case 1: 
			system("cls");
			tambahRute();
			kelolaRute();
			break;
		case 2:
			system("cls");
			lihatRute();
			kelolaRute();
			break;
		case 3:
			system("cls");
			editRute();
			kelolaRute();
			break;
		case 4:
			hapusRute();
			kelolaRute();
			system("cls");
			break;
		case 99:
			system("cls");
			menuAdmin();
			break;
		default:
			printf("Inputan anda tidak valid !");
	}
}

int editRute() {
	rute *r;
	int i=0;
	int j, found=0, counter=1;
    rute r1;
    kota k1;
    FILE *fp, *fp1, *fp2;
    
    char kode[100], kode1[100], kode2[100], kode3[100];
    
	system("cls");
    lihatRute();


    fflush(stdin);
    
	fp = fopen("kota.txt","r");
    fp1 = fopen("rute.txt","r");
    fp2 = fopen("temp.txt","w");
    
    
    printf("\n\nEdit Rute : \nEDIT_");
    scanf("%[^\n]s",kode);
    
	while(fread(&r1,sizeof(rute),1,fp1)){
    	if(strcmp(r1.kode,kode)==0){
   			found = 1;
	    	fflush(stdin);
            printf("\nKeberangkatan : ");
		    scanf("%[^\n]s",r1.kbrt);
		    fflush(stdin);
		    printf("Tujuan : ");
		    scanf("%[^\n]s",r1.tjn);
		    fflush(stdin);
		    printf("Bisnis : ");
		    scanf("%d",&r1.bisnis);
		    fflush(stdin);
		    printf("Premium : ");
		    scanf("%d",&r1.premium);
	
			while(fread(&k1,sizeof(kota),1,fp)) {
	            if(strcmp(r1.kbrt,k1.nama)==0) {
	            	strcpy(kode1,k1.kode);
				} 
				
				if (strcmp(r1.tjn,k1.nama)==0) {
					strcpy(kode2,k1.kode);
				}
				strcpy(kode3,strcat(kode1,"-"));
				strcpy(r1.kode,(strcat(kode3,kode2)));
	        }
	    	
        } 
        
    	fwrite(&r1,sizeof(rute),1,fp2);
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    
    if (found==1) {
	    
    	fp = fopen("rute.txt","w");
    	fp1 = fopen("temp.txt","r");
    	
		while(fread(&k1,sizeof(rute),1,fp1)) {
            fwrite(&k1,sizeof(rute),1,fp);
        }
        
	    fclose(fp);
	    fclose(fp1);
	    
	} else {
		printf("\n\nnot found");
	}
}



int hapusKota() {
	int i, j, found=0;
    kota k1;
    FILE *fp, *fp1;
    char kode[100];
    fp = fopen("kota.txt","r");
	system("cls");
	lihatKota();
    
    printf("\nDelete Kota : DELETE_");
    fflush(stdin);
    scanf("%[^\n]s",kode);

    fp = fopen("kota.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&k1,sizeof(kota),1,fp)){
        if(strcmp(k1.kode,kode)==0){
            found = 1;
        }
        else
            fwrite(&k1,sizeof(kota),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("kota.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&k1,sizeof(kota),1,fp1)){
            fwrite(&k1,sizeof(kota),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nNot Found.....\n");
} 


int lihatKota() {
	kota *k;
	kota k1;
    FILE *fp;
    int n,i,j, counter=1;
    
    fp = fopen("kota.txt","r");
	system("cls");
	printf("LIHAT DATA KOTA");
	printf("\nData Lengkap Kota");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKode Kota\t\tNama Kota\n");
	while(fread(&k1,sizeof(kota),1,fp)) { 
		printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.nama);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
    fclose(fp);
}

int editKota() {
	int i=0;
	int j, found=0, counter=1;
    kota k1;
    FILE *fp, *fp1;
    char kode[100];
    
    fp = fopen("kota.txt","r");
	
    printf("EDIT DATA KOTA");
    
	printf("\nData Lengkap Kota");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKode Kota\t\tNama Kota\n");
	while(fread(&k1,sizeof(kota),1,fp)) { 
		printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.nama);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
	
	fclose(fp);

    fflush(stdin);
    printf("\n\nEdit Kota : \nEDIT_");
    scanf("%[^\n]s",kode);
    
    fp = fopen("kota.txt","r");
    fp1 = fopen("temp.txt","w");
    
    while(fread(&k1,sizeof(kota),1,fp)){
        if(strcmp(k1.kode,kode)==0){
       		found = 1;
        	fflush(stdin);
            printf("\nKode Kota : ");
		    scanf("%[^\n]s",k1.kode);
		    fflush(stdin);
		    printf("Nama Kota : ");
		    scanf("%[^\n]s",k1.nama);
        } 
        fwrite(&k1,sizeof(kota),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    
    if (found==1) {
    	fp = fopen("kota.txt","w");
    	fp1 = fopen("temp.txt","r");
    	while(fread(&k1,sizeof(kota),1,fp1)) {
            fwrite(&k1,sizeof(kota),1,fp);
        }
        
	    fclose(fp);
	    fclose(fp1);
	} else {
		printf("\n\nnot found");
	}
	
	kelolaKota();
}

int tambahKota() {
	kota *k;
    FILE *fp;
    int n,i,j;

    k = (kota*)malloc(100*sizeof(kota));
    fp = fopen("kota.txt","a+");
    
	printf("TAMBAH DATA KOTA\n\n");
    for(i=0;i<1;i++){
    	printf("Tambah Kota : ");
    	fflush(stdin);
        scanf("%s %s",k[i].kode,k[i].nama);
        
        fwrite(k+i,sizeof(kota),1,fp);
    }
    
    fclose(fp);
    
}


int kelolaKota() {
	int i, j, counter=1;
    kota k1;
    kota *k;
    FILE *fp;
	
	fp = fopen("kota.txt","r");

	system("cls");
	printf("#LIHAT DATA KOTA#");
	printf("\nData Lengkap Kota");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKode Kota\t\tNama Kota\n");
	while(fread(&k1,sizeof(kota),1,fp)) { 
		printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.nama);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
	
	printf("\n\n1. Tambah Data Kota");
	printf("\n2. Lihat Data Kota");
	printf("\n3. Edit Data Kota");
	printf("\n4. Delete Data Kota");
	printf("\n99. Menu Utama");
	
	printf("\n\nPilihan : ");
	int choice;
	fflush(stdin);
	scanf("%d",&choice);
	
	switch(choice) {
		case 1: 
			system("cls");
			tambahKota();
			kelolaKota();
			break;
		case 2:
			system("cls");
			lihatKota();
			kelolaKota();
			break;
		case 3:
			system("cls");
			editKota();
			kelolaKota();
			break;
		case 4:
			system("cls");
			hapusKota();
			kelolaKota();
			break;
		case 99:
			system("cls");
			menuAdmin();
			break;
		default:
			printf("Inputan anda tidak valid !");
	}

int hapusKota() {
	int i, j, found=0;
    kota k1;
    FILE *fp, *fp1;
    char kode[100];
    fp = fopen("kota.txt","r");
	system("cls");
	lihatKota();
    
    printf("\nDelete Kota : DELETE_");
    fflush(stdin);
    scanf("%[^\n]s",kode);

    fp = fopen("kota.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&k1,sizeof(kota),1,fp)){
        if(strcmp(k1.kode,kode)==0){
            found = 1;
        }
        else
            fwrite(&k1,sizeof(kota),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("kota.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&k1,sizeof(kota),1,fp1)){
            fwrite(&k1,sizeof(kota),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nNot Found.....\n");
} 


int lihatKota() {
	kota *k;
	kota k1;
    FILE *fp;
    int n,i,j, counter=1;
    
    fp = fopen("kota.txt","r");
	system("cls");
	printf("LIHAT DATA KOTA");
	printf("\nData Lengkap Kota");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKode Kota\t\tNama Kota\n");
	while(fread(&k1,sizeof(kota),1,fp)) { 
		printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.nama);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
    fclose(fp);
}

int editKota() {
	int i=0;
	int j, found=0, counter=1;
    kota k1;
    FILE *fp, *fp1;
    char kode[100];
    
    fp = fopen("kota.txt","r");
	
    printf("EDIT DATA KOTA");
    
	printf("\nData Lengkap Kota");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKode Kota\t\tNama Kota\n");
	while(fread(&k1,sizeof(kota),1,fp)) { 
		printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.nama);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
	
	fclose(fp);

    fflush(stdin);
    printf("\n\nEdit Kota : \nEDIT_");
    scanf("%[^\n]s",kode);
    
    fp = fopen("kota.txt","r");
    fp1 = fopen("temp.txt","w");
    
    while(fread(&k1,sizeof(kota),1,fp)){
        if(strcmp(k1.kode,kode)==0){
       		found = 1;
        	fflush(stdin);
            printf("\nKode Kota : ");
		    scanf("%[^\n]s",k1.kode);
		    fflush(stdin);
		    printf("Nama Kota : ");
		    scanf("%[^\n]s",k1.nama);
        } 
        fwrite(&k1,sizeof(kota),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    
    if (found==1) {
    	fp = fopen("kota.txt","w");
    	fp1 = fopen("temp.txt","r");
    	while(fread(&k1,sizeof(kota),1,fp1)) {
            fwrite(&k1,sizeof(kota),1,fp);
        }
        
	    fclose(fp);
	    fclose(fp1);
	} else {
		printf("\n\nnot found");
	}
	
	kelolaKota();
}

int tambahKota() {
	kota *k;
    FILE *fp;
    int n,i,j;

    k = (kota*)malloc(100*sizeof(kota));
    fp = fopen("kota.txt","a+");
    
	printf("TAMBAH DATA KOTA\n\n");
    for(i=0;i<1;i++){
    	printf("Tambah Kota : ");
    	fflush(stdin);
        scanf("%s %s",k[i].kode,k[i].nama);
        
        fwrite(k+i,sizeof(kota),1,fp);
    }
    
    fclose(fp);
    
}


int kelolaKota() {
	int i, j, counter=1;
    kota k1;
    kota *k;
    FILE *fp;
	
	fp = fopen("kota.txt","r");

	system("cls");
	printf("#LIHAT DATA KOTA#");
	printf("\nData Lengkap Kota");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKode Kota\t\tNama Kota\n");
	while(fread(&k1,sizeof(kota),1,fp)) { 
		printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.nama);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
	
	printf("\n\n1. Tambah Data Kota");
	printf("\n2. Lihat Data Kota");
	printf("\n3. Edit Data Kota");
	printf("\n4. Delete Data Kota");
	printf("\n99. Menu Utama");
	
	printf("\n\nPilihan : ");
	int choice;
	fflush(stdin);
	scanf("%d",&choice);
	
	switch(choice) {
		case 1: 
			system("cls");
			tambahKota();
			kelolaKota();
			break;
		case 2:
			system("cls");
			lihatKota();
			kelolaKota();
			break;
		case 3:
			system("cls");
			editKota();
			kelolaKota();
			break;
		case 4:
			system("cls");
			hapusKota();
			kelolaKota();
			break;
		case 99:
			system("cls");
			menuAdmin();
			break;
		default:
			printf("Inputan anda tidak valid !");
	}
	
}	
}