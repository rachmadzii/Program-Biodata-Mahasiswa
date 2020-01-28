#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct data{
    char *nim;
    char *nama;
    char *matkul;
    char *grade;
    int sks;
    float nakhir;
    int bsks;
    float bnakhir;
};
void tambah(int y){
int x;
	for(x=1;x<=y;x++){
		printf("+");
	}
}
void garis(int y){
int x;
	for(x=1;x<=y;x++){
		printf("-");
	}
}
void samdeg(int y){
int x;
	for(x=1;x<=y;x++){
		printf("=");
	}
}
void menu(){
    tambah(1); garis(48); tambah(1);
    printf("\n|----- PROGRAM INFORMASI AKADEMIS MAHASISWA -----|\n");
    printf("|------------ FAKULTAS ILMU KOMPUTER ------------|\n");
    tambah(1); garis(48); tambah(1);
    printf("\n|  1. Input Biodata Mahasiswa                    |\n");
    printf("|  2. Lihat Nilai Mahasiswa                      |\n");
    printf("|  3. Detail Nilai Mahasiswa                     |\n");
    printf("|  4. Keluar Program                             |\n");
    tambah(1); garis(48); tambah(1);
}
void input(){
	int absen,sks;
	float tugas1,tugas2,uts,uas,nakhir,rata2t;
	char nama[30],matkul[30],yesno[5],tgsl[5],nim[20],grade,lanjut;
    FILE *bio=fopen("biodata.txt","a");
	FILE *tab=fopen("table.txt","a");
	FILE *nam=fopen("namenim.txt","a");

	tambah(1); garis(50); tambah(1);
    printf("\n|-------------- INPUT DATA MAHASISWA --------------|\n");
    tambah(1); garis(50); tambah(1);
	printf("\n\n Masukkan NIM\t\t: ");
	scanf(" %[^\n]",nim);
	printf("\n Masukkan Nama\t\t: ");
	scanf(" %[^\n]",nama);
	printf("\n");
abs:
	tambah(1); garis(50); tambah(1);
	printf("\n\n Masukkan Mata Kuliah\t: ");
	scanf(" %[^\n]",matkul);
	printf("\n Masukkan SKS\t\t: ");
	scanf("%d",&sks);
	printf("\n Masukkan Absen\t\t: ");
	scanf("%d",&absen);
		if(absen<=11){
			printf("\n Nilai absen yang dimasukan tidak memenuhi kriteria.\n");
			printf(" Nilai Tugas dan Ujian akan diberi 0.\n\n");
			printf(" Data yang dimasukan benar? [y/n] ");
			scanf("%s",&yesno);
				if(strncmp(yesno,"y")){
					goto abs;
				}
				else if(strncmp(yesno,"n")){
					uas=0;
					uts=0;
					nakhir=0;
					tugas1=0;
						fprintf(bio,"%s;%s;%s;%d;%d;%d;%d;%d;%d;", &nim, &nama, &matkul, absen, tugas1, uts, uas, nakhir, sks);
						fprintf(tab,"%s;%s;%s;%d;%f;", &nim, &nama, &matkul, sks, nakhir);
						fprintf(bio,"E\n");
                        fprintf(tab,"E\n");
						fclose(bio);
						fclose(tab);
					printf(" Tekan Tombol APAPUN untuk Kembali ke Menu.");
					getch();
					system("cls");
					main();
				}

		}
		else if(12<=absen || absen<=14){
			printf("\n Masukkan Nilai Tugas\t: ");
			scanf("%f",&tugas1);
			printf(" Masukkan Nilai Tugas [Tekan X bila tidak ada]");
			lanjut = getch();
			if(lanjut == 'x' || lanjut == 'X'){
				tugas2 = 0;
				rata2t=tugas1;
				printf("\n");
				goto cont;
			}
			else {
				printf("\n\n Masukkan Nilai Tugas 2\t: ");
				scanf(" %f", &tugas2);
				rata2t=(tugas1+tugas2)/2;
				goto cont;
			}
		cont:
			printf("\n Masukkan Nilai UTS\t: ");
			scanf("%f",&uts);
			printf("\n Masukkan Nilai UAS\t: ");
			scanf("%f",&uas);
			printf("\n Data yang dimasukan benar? [y/n] ");
			scanf("%s",&yesno);
				if(strncmp(yesno,"y")){
					goto abs;
				}
				else if(strncmp(yesno,"n")){
                        nakhir=(((0.3)*uts)+((0.4)*uas)+((0.2)*rata2t)+((0.1)*((absen/14)*100));
					//	nakhir=(((0.3)*uas)+((0.4)*uas)+((0.2)*rata2t)+((0.1)*absen));
						fprintf(bio,"%s;%s;%s;%d;%f;%f;%f;%f;%d;",&nim, &nama, &matkul,absen,rata2t,uts, uas, nakhir,sks);
						fprintf(tab,"%s;%s;%s;%d;%f;",&nim, &nama, &matkul,sks,nakhir);
						fprintf(nam,"%s;%s\n",&nim, &nama);
						if(nakhir >= 90 && nakhir <= 100)
					    {
					         fprintf(bio,"A\n");
					         fprintf(tab,"A\n");
					    }
					    else if(nakhir >= 79 && nakhir <= 89)
					    {
					         fprintf(bio,"B\n");
					         fprintf(tab,"B\n");
					    }
					    else if(nakhir >= 69 && nakhir <= 78)
					    {
					        fprintf(bio,"C\n");
					         fprintf(tab,"C\n");
					    }
					    else if(nakhir >= 59 && nakhir <= 68)
					    {
					        fprintf(bio,"D\n");
					         fprintf(tab,"D\n");
					    }
					    else if(nakhir >= 0 || nakhir <= 58)
					    {
					      	fprintf(bio,"E\n");
					        fprintf(tab,"E\n");
					    }

						fclose(bio);
						fclose(tab);
				}
		}
	printf(" Ada Data Lagi? [y/n] ");
	scanf("%s",&yesno);
				if(strncmp(yesno,"y")){
					printf("\n\n Tekan Tombol APAPUN untuk Kembali ke Menu.");
					getch();
					system("cls");
					main();
				}
				else if(strncmp(yesno,"n")){
					goto abs;
				}

}
void tampil(){
	char nama[30][30],matkul[30][30],huruf[5],yesno[5],tgsl[5],grade[10][10],nim[20][20];
	char bnama[30][30][30],bmatkul[30][30][30],bgrade[10][10][10],bnim[20][20][20];
	int absen,sks[20][20],bsks[20][20][20],i,j,a;
	float tugas1,tugas2,uts,uas,nakhir[20][20],bnakhir[20][20][20],rata2t;
	bool dimen = true;
	struct data on[100];
	struct data on2[100];

	tambah(1); garis(77); tambah(1);
    printf("\n|--------------------------- DATA NILAI MAHASISWA ----------------------------|\n");
    tambah(1); garis(77); tambah(1); printf("\n");

    i = 0;
	FILE *tab=fopen("table.txt","r");
	if(tab != NULL){
    while(!feof(tab)){
		fscanf(tab," %[^;];%[^;];%[^;];%d;%f;%[^\n]\n",nim[i], nama[i], matkul[i],&on[i].sks,&on[i].nakhir,grade[i]);
		if (i == 0) {
            on2[0].nim = nim[0];
            on2[0].nama = nama[0];
            on2[0].matkul = matkul[0];
            on2[0].grade = grade[0];
            on2[0].sks = on[0].sks;
            on2[0].nakhir = on[0].nakhir;
		}
		i++;
      }
	}else printf("\n Tidak ada Data Mahasiswa, Silakan Tambah Data terlebih dahulu.\n");

	a = 0;
    if(i > 0){
        printf("\n\n [ %s  |  %s ]\n",nama[a],nim[a]);
        samdeg(79);
        printf("\n|  MATA KULIAH\t\t\t\t\t|  SKS  |   AKHIR   |  Huruf  |\n");
        samdeg(79);
        printf("\n");
        if(strlen(matkul[a]) <= 10 ) printf("|  %s\t\t\t\t\t", matkul[a]);
        else if(strlen(matkul[a]) > 5 && strlen(matkul[a]) <= 20) printf("|  %s\t\t\t\t", matkul[a]);
        else if(strlen(matkul[a]) > 10 && strlen(matkul[a]) <= 30) printf("|  %s\t\t\t", matkul[a]);
        else if(strlen(matkul[a]) > 20 && strlen(matkul[a]) <= 40) printf("|  %s\t\t", matkul[a]);
        else printf("|  %s\t", matkul[a]);
        printf("|   %d   |", on[a].sks);
        if(on[a].nakhir < 10) printf("    %.2f   |", on[a].nakhir);
        else if(on[a].nakhir < 100) printf("   %.2f   |", on[a].nakhir);
        else printf("  %.2f   |", on[a].nakhir);
        printf("    %s    |\n", grade[a]);
        samdeg(79);
    }
    for(a=1;a<i;a++){
        if(!strcmp(nim[a],nim[a-1])) {
            printf("\n");
            if(strlen(matkul[a]) <= 10 ) printf("|  %s\t\t\t\t\t", matkul[a]);
            else if(strlen(matkul[a]) > 5 && strlen(matkul[a]) <= 20) printf("|  %s\t\t\t\t", matkul[a]);
            else if(strlen(matkul[a]) > 10 && strlen(matkul[a]) <= 30) printf("|  %s\t\t\t", matkul[a]);
            else if(strlen(matkul[a]) > 20 && strlen(matkul[a]) <= 40) printf("|  %s\t\t", matkul[a]);
            else printf("|  %s\t", matkul[a]);
            printf("|   %d   |", on[a].sks);
            if(on[a].nakhir < 10) printf("    %.2f   |", on[a].nakhir);
            else if(on[a].nakhir < 100) printf("   %.2f   |", on[a].nakhir);
            else printf("  %.2f   |", on[a].nakhir);
            printf("    %s    |\n", grade[a]);
            samdeg(79);
            continue;
        } else {
            printf("\n\n\n [ %s  |  %s ]\n",nama[a],nim[a]);
            samdeg(79);
            printf("\n|  MATA KULIAH\t\t\t\t\t|  SKS  |   AKHIR   |  Huruf  |\n");
            samdeg(79);
            printf("\n");
            if(strlen(matkul[a]) <= 10 ) printf("|  %s\t\t\t\t\t", matkul[a]);
            else if(strlen(matkul[a]) > 5 && strlen(matkul[a]) <= 20) printf("|  %s\t\t\t\t", matkul[a]);
            else if(strlen(matkul[a]) > 10 && strlen(matkul[a]) <= 30) printf("|  %s\t\t\t", matkul[a]);
            else if(strlen(matkul[a]) > 20 && strlen(matkul[a]) <= 40) printf("|  %s\t\t", matkul[a]);
            else printf("|  %s\t", matkul[a]);
            printf("|   %d   |", on[a].sks);
            if(on[a].nakhir < 10) printf("    %.2f   |", on[a].nakhir);
            else if(on[a].nakhir < 100) printf("   %.2f   |", on[a].nakhir);
            else printf("   %.2f  |", on[a].nakhir);
            printf("    %s    |\n", grade[a]);
            samdeg(79);
        }
    }

fclose(tab);
printf("\n\n\n Tekan Tombol APAPUN untuk Kembali ke Menu.");
getch();
system("cls");
main();
}

void cari(){
	char nama[30],matkul[30],huruf[5],yesno[5],tgsl[5],grade[10],nim[20],nim2[20];
	int absen,sks;
	bool status = 0;
	float tugas1,tugas2,uts,uas,nakhir,rata2t;
	FILE *bio=fopen("biodata.txt","r");

	tambah(1); garis(77); tambah(1);
    printf("\n|--------------------------- CARI DATA MAHASISWA -----------------------------|\n");
    tambah(1); garis(77); tambah(1); printf("\n");
    ulangi:
	printf("\n Masukkan NIM\t: ");
	scanf(" %[^\n]",nim2);

	int a = 0;

    if(bio != NULL){
      while(!feof(bio)){
	  fscanf(bio,"%[^;];%[^;];%[^;];%d;%f;%f;%f;%f;%d;%[^\n]\n",nim, nama, matkul,&absen,&rata2t,&uts, &uas, &nakhir,&sks,grade);
      if(strncmp(nim,nim2) == 0){
        status = 1;
         if(a == 0){
             printf("\n Berhasil Ditemukan!\n\n");
             printf(" [ %s  |  %s ]\n",nama,nim);
             samdeg(110);
             printf("\n|  MATA KULIAH\t\t\t\t\t|  SKS  |  ABSEN  |   RATA TUGAS   |    UTS     |    UAS     | \n");
             samdeg(110);
         }
         printf("\n");
         if(strlen(matkul) <= 10 ) printf("|  %s\t\t\t\t\t", matkul);
         else if(strlen(matkul) > 5 && strlen(matkul) <= 20) printf("|  %s\t\t\t\t", matkul);
         else if(strlen(matkul) > 10 && strlen(matkul) <= 30) printf("|  %s\t\t\t", matkul);
         else if(strlen(matkul) > 20 && strlen(matkul) <= 40) printf("|  %s\t\t", matkul);
         else printf("|  %s\t", matkul);
         printf("|   %d   |", sks);
         if(absen < 10) printf("    %d    |", absen);
         else if(absen < 15) printf("   %d    |",absen);

         if(rata2t < 10)        printf("       %.2f     |", rata2t);
         else if(rata2t < 100)  printf("      %.2f     |", rata2t);
         else                   printf("     %.2f     |", rata2t);

         if(uts < 10)           printf("     %.2f   |", uts);
         else if(uts < 100)     printf("    %.2f   |", uts);
         else                   printf("   %.2f   |", uts);

         if(uas < 10)           printf("     %.2f   |", uas);
         else if(uas < 100)     printf("    %.2f   |", uas);
         else                   printf("   %.2f   |", uas);

         printf("\n");
         samdeg(110);
         a++;
      }
         if(feof(bio) && status == 0){
             printf("\n Data tidak ditemukan.\n\n");
         }
        }
    }else{
         printf("\n Tidak ada Data Mahasiswa, Silakan Tambah Data terlebih dahulu.\n");
    }
         printf("\n\n Tekan Tombol APAPUN untuk Kembali ke Menu.");
	  	 getch();
	  	 system("cls");
	  	 main();
}

int main(){
	int pilihan;
	menu();
main:
    printf("\n  Masukkan Pilihan [1..4] : ");
    scanf("%d", &pilihan);
    printf("\n");

    switch(pilihan){
    case 1:
        system("cls");
        input();
    break;
    case 2:
        system("cls");
        tampil();
    break;
    case 3:
        system("cls");
        cari();
    break;
    case 4 :
        goto keluar;
	break;
	default :
	    printf("  Pilihan salah, Silakan Ulangi.\n");
	    goto main;
	break;
    }
    keluar:
        system("cls");
        printf("\n\n  Terima Kasih...\n\n");

return 0;
}
