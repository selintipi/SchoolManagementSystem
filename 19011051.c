#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int dersID;
	char dersadi [30];
	int derskredisi;
	int kontenjan;
	int ogretimuyeID;
}dersler;
typedef struct{
	int ogretimuyeID;
	char ogretimad [30];
	char ogretimsoyad [30];
	char unvan [30];
}ogretimuyesi;
typedef struct{
	int ogrenciID;
	char ad [30];
	char soyad [30];
	int derssayisi;
	int kredi;
}ogrenci;
typedef struct{
	int no;
	int dersID;
	int ogrenciID;
	int kayit;
	int tarih;
}ogrderskayit;

void ogrenci_ekleme(){
	FILE *data=fopen("ogrenciler.txt","a+");
	ogrenci o;
	int ogrenciID,i=0;
	o.kredi=0;
	o.derssayisi=0;
	printf("\nOgrenci ID :\n");
	scanf("%d", &ogrenciID);
	while(!feof(data)){
		fscanf(data,"%d %s %s %d %d\n", &o.ogrenciID, o.ad, o.soyad, &o.derssayisi, &o.kredi);
		if(o.ogrenciID==ogrenciID){
			i=1;
		}
	}
	fseek(data, 0, SEEK_SET);
	printf("\nAd :\n");
	scanf("%s", o.ad);
	printf("\nSoyad :\n");
	scanf("%s", o.soyad);
	if(i==0){
		fprintf(data,"%d %s %s %d %d\n", ogrenciID, o.ad, o.soyad, o.derssayisi, o.kredi);
	}
	else{
		printf("\nID Bulunmaktadir Ogrenci Eklenemiyor\n");
	}
	fclose(data);
}
void ogrenci_silme(){
	int ogrenciID,i=0,j=0;
	ogrenci o;
	ogrderskayit odk;
	FILE *data1=fopen("ogrenciler.txt","r");
	FILE *data2=fopen("tmp.txt","w");
	printf("\nSilinecek Ogrenci ID:\n");
	scanf("%d",&ogrenciID);
	while(!feof(data1)){
		fscanf(data1,"%d %s %s %d %d\n", &o.ogrenciID, o.ad, o.soyad, &o.derssayisi, &o.kredi);
		if(ogrenciID!=o.ogrenciID){
			fprintf(data2,"%d %s %s %d %d\n", o.ogrenciID, o.ad, o.soyad, o.derssayisi, o.kredi);
		}
		else{
			i=1;
		}
	}
	if(i==0){
		printf("\nIDye Ait Ogrenci Bulunmamakta\n");
	}
	else{
		j=1;
	}
	fclose(data1);
	fclose(data2);
	remove("ogrenciler.txt");
	rename("tmp.txt","ogrenciler.txt");
	if(j==1){
		data1=fopen("ogrenciderskayit.txt","r");
		data2=fopen("tmp.txt","w");
		while(!feof(data1)){
			fscanf(data1,"%d %d %d %d %d\n", &odk.no, &odk.dersID, &odk.ogrenciID, &odk.kayit, &odk.tarih);
			if(ogrenciID==odk.ogrenciID){
				fprintf(data2,"%d %d %d %d %d\n", odk.no, odk.dersID, odk.ogrenciID, 0, odk.tarih);
			}
			else{
				fprintf(data2,"%d %d %d %d %d\n", odk.no, odk.dersID, odk.ogrenciID, odk.kayit, odk.tarih);
			}
		}
		fclose(data1);
		fclose(data2);
		remove("ogrenciderskayit.txt");
		rename("tmp.txt","ogrenciderskayit.txt");
	}
}
void ders_ekleme(){
	FILE *data=fopen("dersler.txt","a+");
	dersler d;
	int dersID,i=0;
	printf("\nDers ID :\n");
	scanf("%d", &dersID);
	while(!feof(data)){
		fscanf(data,"%d %s %d %d %d\n", &d.dersID, d.dersadi, &d.derskredisi, &d.kontenjan, &d.ogretimuyeID);
		if(dersID==d.dersID){
			i=1;
		}
	}
	fseek(data, 0, SEEK_SET);
	printf("\nDers Adi :\n");
	scanf("%s", d.dersadi);
	printf("\nDers Kredisi :\n");
	scanf("%d", &d.derskredisi);
	printf("\nKontenjan :\n");
	scanf("%d", &d.kontenjan);
	printf("\nDersi Verecek Ogretim Uyesinin IDsi :\n");
	scanf("%d", &d.ogretimuyeID);
	if(i==0){
	fprintf(data,"%d %s %d %d %d\n", dersID, d.dersadi, d.derskredisi, d.kontenjan, d.ogretimuyeID);
	}
	else{
		printf("\nID Bulunmaktadir Ders Eklenemiyor\n");
	}	
	fclose(data);
}
void ders_silme(){
	FILE *data1=fopen("dersler.txt","r");
	FILE *data2=fopen("tmp.txt","w");
	dersler d;
	ogrderskayit odk;
	int dersID,i=0,j=0;
	printf("\nSilinecek Ders ID :\n");
	scanf("%d", &dersID);
	while(!feof(data1)){
		fscanf(data1,"%d %s %d %d %d\n", &d.dersID, d.dersadi, &d.derskredisi, &d.kontenjan, &d.ogretimuyeID);
		if(d.dersID!=dersID){
			fprintf(data2,"%d %s %d %d %d\n", d.dersID, d.dersadi, d.derskredisi, d.kontenjan, d.ogretimuyeID);
		}
		else{
			i=1;
		}
	}
	if(i==0){
		printf("\nGirdiginiz IDli Ders Bulunmamakta\n");
	}
	fclose(data1);
	fclose(data2);
	remove("dersler.txt");
	rename("tmp.txt","dersler.txt");
}
void ogretimuyesi_ekleme(){
	FILE *data=fopen("ogretimuyeleri.txt","a+");
	ogretimuyesi ou;
	int ogretimuyeID,i=0;
	printf("\nOgretim Uye ID :\n");
	scanf("%d", &ogretimuyeID);
	while(!feof(data)){
		fscanf(data,"%d %s %s %s\n", &ou.ogretimuyeID, ou.ogretimad, ou.ogretimsoyad, ou.unvan);
		if(ou.ogretimuyeID==ogretimuyeID){
			i=1;
		}
	}
	fseek(data, 0, SEEK_SET);
	printf("\nAd :\n");
	scanf(" %s", ou.ogretimad);
	printf("\nSoyad :\n");
	scanf(" %s", ou.ogretimsoyad);
	printf("\nUnvan :\n");
	scanf("%s", ou.unvan);
	if(i==0){
		fprintf(data,"%d %s %s %s\n", ogretimuyeID, ou.ogretimad, ou.ogretimsoyad, ou.unvan);
	}
	else{
		printf("\nID Bulunmaktadir Ogretim Uyesi Eklenemiyor\n");
	}
	fclose(data);
}
void ogretimuyesi_silme(){
	FILE *data1=fopen("ogretimuyeleri.txt","r");
	FILE *data2=fopen("tmp.txt","w");
	ogretimuyesi ou;
	int ogretimuyeID,i=0,j=0;
	printf("\nSilinecek Ogretim Uye ID :\n");
	scanf("%d", &ogretimuyeID);
	while(!feof(data1)){
		fscanf(data1,"%d %s %s %s\n", &ou.ogretimuyeID, ou.ogretimad, ou.ogretimsoyad, ou.unvan);
		if(ogretimuyeID!=ou.ogretimuyeID){
			fprintf(data2,"%d %s %s %s\n", ou.ogretimuyeID, ou.ogretimad, ou.ogretimsoyad, ou.unvan);
		}
		else{
			i=1;
		}
	}
	if(i==0){
		printf("\nGirdiginiz IDli Ogretim Uyesi Bulunmamakta\n");
	}
	fclose(data1);
	fclose(data2);
	remove("ogretimuyeleri.txt");
	rename("tmp.txt","ogretimuyeleri.txt");
}
void ogrenciye_ders_ekleme(){
	FILE *data=fopen("dersler.txt","r");
	int a=0,i=0,j=0,k=0,b=0,dersID,maxders,maxkredi,ogrenciID,tarih,kayit=1,no,flag;
	dersler *tmp1;
	ogrenci *tmp2;
	ogrderskayit odk;
	tmp1=(dersler*)malloc(1*sizeof(dersler));
	tmp2=(ogrenci*)malloc(1*sizeof(ogrenci));
	printf("\nDersler :\n");
	while(!feof(data)){
		a++;
		tmp1=(dersler*)realloc(tmp1,a*sizeof(dersler));
		fscanf(data,"%d %s %d %d %d\n", &tmp1[a-1].dersID, tmp1[a-1].dersadi, &tmp1[a-1].derskredisi, &tmp1[a-1].kontenjan, &tmp1[a-1].ogretimuyeID);
		printf("%d %s %d %d %d\n", tmp1[a-1].dersID, tmp1[a-1].dersadi, tmp1[a-1].derskredisi, tmp1[a-1].kontenjan, tmp1[a-1].ogretimuyeID);
	}
	fclose(data);
	data=fopen("ogrenciler.txt","r");
	while(!feof(data)){
		j++;
		tmp2=(ogrenci*)realloc(tmp2,j*sizeof(ogrenci));
		fscanf(data,"%d %s %s %d %d\n", &tmp2[j-1].ogrenciID, tmp2[j-1].ad, tmp2[j-1].soyad, &tmp2[j-1].derssayisi, &tmp2[j-1].kredi);
	}
	fclose(data);
	printf("Eklemek Istediginiz Dersin IDsini Girin :\n");
	scanf("%d", &dersID);
	printf("\nMaksimum Ders Sayisi Girin :\n");
	scanf("%d", &maxders);
	printf("\nMaksimum Kredi Sayisini Girin :\n");
	scanf("%d", &maxkredi);
	printf("\nOgrenci IDnizi Girin :\n");
	scanf("%d", &ogrenciID);
	printf("\nBugunun Tarihini Girin :\n");
	scanf("%d", &tarih);
	for(i=0;i<a;i++){
		if(tmp1[i].dersID==dersID){
			for(b=0;b<j;b++){
				if(tmp2[b].ogrenciID==ogrenciID){
					if(tmp2[b].derssayisi<maxders && tmp2[b].kredi+tmp1[i].derskredisi<=maxkredi){
					tmp2[b].derssayisi++;
					tmp2[b].kredi=tmp2[b].kredi+tmp1[i].derskredisi;
					flag=1;
					}
					else{
						printf("\nMax Ders Sayisi Ya Da Kredisine Ulasilmistir, Ders Eklenemiyor\n");
					}
				}
			}
		}
	}
	data=fopen("ogrenciler.txt","w");
	fseek(data, 0, SEEK_SET);
	for(i=0;i<j;i++){
		fprintf(data,"%d %s %s %d %d\n", tmp2[i].ogrenciID, tmp2[i].ad, tmp2[i].soyad, tmp2[i].derssayisi, tmp2[i].kredi);	
	}
	fclose(data);
	data=fopen("ogrenciderskayit.txt","a+");
	while(!feof(data)){
		odk.no=0;
		fscanf(data,"%d %d %d %d %d\n", &odk.no, &odk.dersID, &odk.ogrenciID, &odk.kayit, &odk.tarih);
		no=odk.no+1;
	}
	if(flag==1){
		fprintf(data,"%d %d %d %d %d\n", no, dersID, ogrenciID, kayit, tarih);	
	}
	fclose(data);
}
void ogrenciden_ders_silme(){
	FILE *data=fopen("dersler.txt","r");
	int a=0,i=0,j=0,k=0,b=0,m=0,dersID,ogrenciID;
	dersler *tmp1;
	ogrenci *tmp2;
	ogrderskayit *tmp3;
	tmp1=(dersler*)malloc(1*sizeof(dersler));
	tmp2=(ogrenci*)malloc(1*sizeof(ogrenci));
	tmp3=(ogrderskayit*)malloc(1*sizeof(ogrderskayit));
	while(!feof(data)){
		a++;
		tmp1=(dersler*)realloc(tmp1,a*sizeof(dersler));
		fscanf(data,"%d %s %d %d %d\n", &tmp1[a-1].dersID, tmp1[a-1].dersadi, &tmp1[a-1].derskredisi, &tmp1[a-1].kontenjan, &tmp1[a-1].ogretimuyeID);
	}
	fclose(data);
	data=fopen("ogrenciler.txt","r");
	while(!feof(data)){
		j++;
		tmp2=(ogrenci*)realloc(tmp2,j*sizeof(ogrenci));
		fscanf(data,"%d %s %s %d %d\n", &tmp2[j-1].ogrenciID, tmp2[j-1].ad, tmp2[j-1].soyad, &tmp2[j-1].derssayisi, &tmp2[j-1].kredi);
	}
	fclose(data);
	data=fopen("ogrenciderskayit.txt","r");
	while(!feof(data)){
		m++;
		tmp3=(ogrderskayit*)realloc(tmp3,m*sizeof(ogrderskayit));
		fscanf(data,"%d %d %d %d %d\n", &tmp3[m-1].no, &tmp3[m-1].dersID, &tmp3[m-1].ogrenciID, &tmp3[m-1].kayit, &tmp3[m-1].tarih);
	}
	fclose(data);
	printf("\nSilmek Istediginiz Dersin IDsini Girin :\n");
	scanf("%d", &dersID);
	printf("\nOgrenci IDnizi Girin :\n");
	scanf("%d", &ogrenciID);
	for(i=0;i<a;i++){
		if(tmp1[i].dersID==dersID){
			for(b=0;b<j;b++){
				if(tmp2[b].ogrenciID==ogrenciID){
					tmp2[b].derssayisi--;
					tmp2[b].kredi=tmp2[b].kredi-tmp1[i].derskredisi;
				}
			}
		}
	}
	data=fopen("ogrenciler.txt","w");
	fseek(data, 0, SEEK_SET);
	for(i=0;i<j;i++){
		fprintf(data,"%d %s %s %d %d\n", tmp2[i].ogrenciID, tmp2[i].ad, tmp2[i].soyad, tmp2[i].derssayisi, tmp2[i].kredi);
	}
	fclose(data);
	data=fopen("ogrenciderskayit.txt","w");
	fseek(data, 0, SEEK_SET);
	for(i=0;i<m;i++){
		if(tmp3[i].dersID==dersID && tmp3[i].ogrenciID==ogrenciID){
			tmp3[i].kayit=0;
		}
		fprintf(data,"%d %d %d %d %d\n", tmp3[i].no, tmp3[i].dersID, tmp3[i].ogrenciID, tmp3[i].kayit, tmp3[i].tarih);
	}
	fclose(data);
}
void verilen_dersleri_gorme(){
	int ogretimuyeID,i=0;
	dersler *tmp;
	printf("\nDerslerini Gormek Istediginiz Ogretim Uyesinin IDsini Girin :\n");
	scanf("%d", &ogretimuyeID);
	FILE *data=fopen("dersler.txt","r");
	printf("\nDersler :\n");
	while(!feof(data)){
		i++;
		tmp=(dersler*)realloc(tmp,i*sizeof(dersler));
		fscanf(data,"%d %s %d %d %d\n", &tmp[i-1].dersID, tmp[i-1].dersadi, &tmp[i-1].derskredisi, &tmp[i-1].kontenjan, &tmp[i-1].ogretimuyeID);
		if(ogretimuyeID==tmp[i-1].ogretimuyeID){
			printf("%s\n", tmp[i-1].dersadi);
		}
	}
	fclose(data);	
}
void ogrenci_gorme(){
	int dersID,i=0;
	ogrderskayit *tmp;
	printf("\nOgrencilerini Gormek Istediginiz Dersin IDsini Girin :\n");
	scanf("%d", &dersID);
	FILE *data=fopen("ogrenciderskayit.txt","r");
	printf("\nDersi Alan Ogrencilerin IDleri  :\n");
	while(!feof(data)){
		i++;
		tmp=(ogrderskayit*)realloc(tmp,i*sizeof(ogrderskayit));
		fscanf(data,"%d %d %d %d %d\n", &tmp[i-1].no, &tmp[i-1].dersID, &tmp[i-1].ogrenciID, &tmp[i-1].kayit, &tmp[i-1].tarih);
		if(dersID==tmp[i-1].dersID && tmp[i-1].kayit==1){
			printf("%d\n", tmp[i-1].ogrenciID);
		}
	}
	fclose(data);
}
void alinan_dersleri_gorme(){
	int ogrenciID,i=0;
	ogrderskayit *tmp;
	printf("\nDerslerini Gormek Istediginiz Ogrencinin IDsini Girin :\n");
	scanf("%d", &ogrenciID);
	FILE *data=fopen("ogrenciderskayit.txt","r");
	printf("\nOgrencinin Derslerinin IDleri :\n");
	while(!feof(data)){
		i++;
		tmp=(ogrderskayit*)realloc(tmp,i*sizeof(ogrderskayit));
		fscanf(data,"%d %d %d %d %d\n", &tmp[i-1].no, &tmp[i-1].dersID, &tmp[i-1].ogrenciID, &tmp[i-1].kayit, &tmp[i-1].tarih);
		if(tmp[i-1].kayit=1){
			printf("%d\n", tmp[i-1].dersID);
		}
	}
	fclose(data);
}
void siniflistesi_olusturma(){
	int ogretimuyeID,dersID,i=0,j=0,k=0,b=0;
	dersler tmp1;
	ogrderskayit tmp2;
	FILE *data=fopen("dersler.txt","r");
	FILE *fp=fopen("ogrenciderskayit.txt","r");
	FILE *fw;
	printf("\nOgretim Uyesinin IDsini Girin :\n");
	scanf("%d", &ogretimuyeID);
	printf("\nOgretim Uyesinin Verdigi Derslerin IDleri :\n");
	while(!feof(data)){
		fscanf(data, "%d %s %d %d %d\n", &tmp1.dersID, tmp1.dersadi, &tmp1.derskredisi, &tmp1.kontenjan, &tmp1.ogretimuyeID);
		if(tmp1.ogretimuyeID==ogretimuyeID){
			printf("%d\n", tmp1.dersID);
		}
	}
	fseek(data, 0, SEEK_SET);
	printf("\nOgretim Uyesinin Verdigi Dersin IDsini Girin :\n");
	scanf("%d", &dersID);
	fw=fopen("derskodu_siniflistesi.txt","w");
	while(!feof(data)){
		fscanf(data, "%d %s %d %d %d\n", &tmp1.dersID, tmp1.dersadi, &tmp1.derskredisi, &tmp1.kontenjan, &tmp1.ogretimuyeID);
		if(tmp1.ogretimuyeID==ogretimuyeID && tmp1.dersID==dersID){
			while(!feof(fp)){
				fscanf(fp, "%d %d %d %d %d\n", &tmp2.no, &tmp2.dersID, &tmp2.ogrenciID, &tmp2.kayit, &tmp2.tarih);
				if(tmp2.dersID==dersID && tmp2.kayit==1){
					fprintf(fw, "%d\n", tmp2.ogrenciID);
				}
			}
		}
	}
	fclose(data);
	fclose(fp);
	fclose(fw);
}
int main(){
	int choose=1;
	while(choose > 0){
		printf("\nOgrenci Eklemek Icin 1\n");
		printf("\nOgrenci Silmek Icin 2\n");
		printf("\nDers Eklemek Icin 3\n");
		printf("\nDers Silmek Icin 4\n");
		printf("\nOgretim Uyesi Eklemek Icin 5\n");
		printf("\nOgretim Uyesi Silmek Icin 6\n");
		printf("\nOgrenciye Ders Eklemek Icin 7\n");
		printf("\nOgrenciden Ders Silmek Icin 8\n");
		printf("\nOgretim Uyesinin Verdigi Dersleri Gormek Icin 9\n");
		printf("\nDersi Alan Ogrencileri Gormek Icin 10\n");
		printf("\nOgrencinin Aldigi Dersleri Gormek Icin 11\n");
		printf("\nOgretim Uyesinin Dersinin Ogrencilerini Dosyaya Yazdirmak Icin 12\n");
		printf("\nCikis icin 0a basiniz :\n");
		scanf(" %d", &choose);
		switch(choose){
			case 1:
				ogrenci_ekleme();	
				break;
			case 2:
				ogrenci_silme();	
				break;
			case 3:
				ders_ekleme();	
				break;
			case 4:
				ders_silme();
				break;
			case 5:
				ogretimuyesi_ekleme();	
				break;
			case 6:
				ogretimuyesi_silme();
				break;
			case 7:
				ogrenciye_ders_ekleme();	
				break;
			case 8:
				ogrenciden_ders_silme();
				break;
			case 9:
				verilen_dersleri_gorme();
				break;
			case 10:
				ogrenci_gorme();
				break;
			case 11:
				alinan_dersleri_gorme();
				break;
			case 12:
				siniflistesi_olusturma();
				break;
		}
	}
	return 0;
}
