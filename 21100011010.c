#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Metin Furkan YAMAN 21100011010
//Hocam realloc kýsmýndaki sorunu çözdüm hatasýz çalýþýyor.

typedef struct musteri_abone
{
    int gun;
    int ay;
    int yil;
} tarih;

typedef struct musteri
{

    int musteri_id;
    char musteri_adsoyad[80];
    char musteri_telno[40];
    tarih *zaman;
} musteri_bilgileri;
int musteri_sayisi =0;
int musteri_sayisi2;

musteri_bilgileri *mstr;
int secenek;
float fiyat;



musteri_bilgileri* ekle()
{
    printf("\n\n");
    int i,j,csayisi;
    int eklenecek_musteri;
    printf("Sisteme ilk kez musteri kaydi yapmak istiyorsaniz '1' numarali rakami tuslayiniz\n");
    printf("Daha once sisteme musteri kaydi yaptiysaniz lutfen '2' numarali rakami tuslayiniz\n");
    printf("Lutfen tuslama yapiniz==>");
    scanf("%d",&secenek);
    if(secenek==1)
    {
        printf("Kac adet yeni musteri eklemek istiyorsunuz?==>");
        scanf("%d",&eklenecek_musteri);
        mstr=malloc(eklenecek_musteri*sizeof(musteri_bilgileri));
        if(mstr==NULL){printf("Yer yok");}

        for(i=0; i<eklenecek_musteri; i++)
        {
            printf("%d.musterinin idsini giriniz==>",i+1);
            scanf("%d",&(mstr+i)->musteri_id);

            printf("%d.musterinin adini ve soyadini arasinda _ olacak sekilde (Metin_Yaman) giriniz==>",i+1);
            scanf("%s",&(mstr+i)->musteri_adsoyad);

            printf("%d.musterinin basinda sifir olmadan telefon numarasini giriniz==>",i+1);
            scanf("%s",&(mstr+i)->musteri_telno);
            musteri_sayisi++;
            (mstr+i)->zaman = (tarih *)malloc(eklenecek_musteri*sizeof(tarih));
            for(j=0; j<1; j++)
            {

                printf("%d.musterinin sisteme kayit oldugu tarihin gununu basinda sifir olmadan giriniz==>",i+1);
                scanf("%d",&((mstr+i)->zaman+j)->gun);

                printf("%d.musterinin sisteme kayit oldugu tarihin ayin basinda sifir olmadan giriniz==>",i+1);
                scanf("%d",&((mstr+i)->zaman+j)->ay);

                printf("%d.musterinin sisteme kayit oldugu tarihin yilini basinda sifir olmadan giriniz==>",i+1);
                scanf("%d",&((mstr+i)->zaman+j)->yil);
            }
        }
        printf("\n\n");

        printf("Musteri ekleme islemi basariyla tamamlandi.");

    }

    else
    {
        printf("Kac adet yeni musteri eklemek istiyorsunuz?==>");
        scanf("%d",&eklenecek_musteri);
        mstr=realloc(mstr,sizeof(musteri_bilgileri)*(eklenecek_musteri+musteri_sayisi));
        if(mstr == NULL)
        {
            printf("yer ayrilamadi!");
            exit(0);
        }


        for(i=0; i<eklenecek_musteri; i++)
        {
            printf("%d.musterinin idsini giriniz==>",i+1);
            scanf("%d",&(mstr+musteri_sayisi+i)->musteri_id);

            printf("%d.musterinin adini ve soyadini arasinda _ olacak sekilde (Metin_Yaman) giriniz==>",i+1);
            scanf("%s",&(mstr+musteri_sayisi+i)->musteri_adsoyad);

            printf("%d.musterinin basinda sifir olmadan telefon numarasini giriniz==>",i+1);
            scanf("%s",&(mstr+musteri_sayisi+i)->musteri_telno);

            (mstr+musteri_sayisi+i)->zaman = (tarih *)malloc(sizeof(tarih));


            for(j=0; j<1; j++)
            {


                printf("%d.musterinin sisteme kayit oldugu tarihin gununu basinda sifir olmadan giriniz==>",i+1);
                scanf("%d",&((mstr+musteri_sayisi+i)->zaman+j)->gun);

                printf("%d.musterinin sisteme kayit oldugu tarihin ayin basinda sifir olmadan giriniz==>",i+1);
                scanf("%d",&((mstr+musteri_sayisi+i)->zaman+j)->ay);

                printf("%d.musterinin sisteme kayit oldugu tarihin yilini giriniz==>",i+1);
                scanf("%d",&((mstr+musteri_sayisi+i)->zaman+j)->yil);

            }
            musteri_sayisi++;



        }
        printf("\n\n");
        printf("Musteri ekleme islemi basariyla tamamlandi.");

    }
 return mstr;
}

void kayitli_musteriler_listele(musteri_bilgileri *deneme)
{


    int i,j,eklenecek_musteri;
    printf("\n------------------------------------------------------------------------------------\n");
    for(i=0;i<musteri_sayisi;i++)
    {
        printf("\n %d.musterinin id'si==> %d",i+1,(deneme+i)->musteri_id);
        printf("\n %d.musterinin adi-soyadi==> %s",i+1,(deneme+i)->musteri_adsoyad);
        printf("\n %d.musterinin telefon numarasi==> %s",i+1,(deneme+i)->musteri_telno);

        for(j=0; j<1; j++)
        {
            printf("\n %d.musterinin kayit tarihi==>%d.%d.%d",i+1,((deneme+i)->zaman+j)->gun,((deneme+i)->zaman+j)->ay,((deneme+i)->zaman+j)->yil);
        }


    }
     printf("\n------------------------------------------------------------------------------------\n");
    return deneme;
}



void menu()
{
    int i,alim,para;
    printf("\n\n\n>>>>>>>>>>>>>>>>>>>>MENUMUZ<<<<<<<<<<<<<<<<<<<<\n\n");
    printf("-----ICECEKLER-----\n");
    printf("~TURK KAHVESI->30TL\n~AMERICANO->25TL\n~MOCHA->20TL\n~LATTE->40TL\n\n");
    printf("-----APERATIFLER-----\n");
    printf("~KURABIYE->10TL\n~DONUT->20TL\n~ISLAK KEK->25TL\n~OZEL URETIM ALMAN CIKOLATASI->40TL\n\n");
    printf("Kac adet urun alacaksiniz?:",alim);
    scanf("%d",&alim);
    for(i=1; i<=alim; i++)
    {
        printf("Almak istediginiz %d.urunun fiyatini giriniz==>",i);
        scanf("%d",&para);
        fiyat=fiyat+para;
    }
    printf("Urunler basariyla sepete eklenmistir");
    printf("\n\n\n");
}


void indirimhesaplama()
{

    int tuslama;
    float indirim;
     printf("\n-----------------------------------------------------------------------------\n");
    printf("\t\tIndirim hesaplama menumuze hosgeldiniz\n");
    printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("----->Kafeye uyelik surenizi asagidaki seceneklerden bulup o secenegi tuslayiniz.\n");

    printf("1)0-1 yillik arasinda aboneligim var.(Eger tam 1 yilsa bu secenegi seciniz)\n2)1-2 yil arasinda aboneligim var.(Eger tam 2 yilsa bu secenegi seciniz)\n3)2-3 yil arasinda aboneligim var.\n4)3++ yillik aboneligim var.\n");

    printf("-----------------------------------------------------------------------------\n");
    printf("----->Bu alana tuslama yapiniz==>",tuslama);
    scanf("%d",&tuslama);


    if(tuslama==1)
    {


        printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("Tebrikler yuzde onluk indirim hakki kazandiniz.\n");
        indirim=fiyat*0.1;
        printf("Ucretten %.2f TL kadar dusulmustur.\n",indirim);
        fiyat=fiyat-indirim;
        printf("Odemeniz gereken yeni ucret = %.2f TL'dir",fiyat);
    }

    else if(tuslama==2)
    {

        printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("Tebrikler yuzde on beslik indirim hakki kazandiniz.\n");
        indirim=fiyat*0.15;
        printf("Ucretten %.2f TL kadar dusulmustur.\n",indirim);
        fiyat=fiyat-indirim;
        printf("Odemeniz gereken yeni ucret = %.2f TL'dir",fiyat);
    }

    else if(tuslama==3)
    {
       printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("Tebrikler yuzde yirmilik indirim hakki kazandiniz.\n");
        indirim=fiyat*0.2;
        printf("Ucretten %.2f TL kadar dusulmustur.\n",indirim);
        fiyat=fiyat-indirim;
        printf("Odemeniz gereken yeni ucret = %.2f TL'dir",fiyat);


    }

   else if (tuslama==4)
   {
        printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("Tebrikler yuzde yirmi beslik indirim hakki kazandiniz.\n");
        indirim=fiyat*0.25;
        printf("Ucretten %.2f TL kadar dusulmustur.\n",indirim);
        fiyat=fiyat-indirim;
        printf("Odemeniz gereken yeni ucret = %.2f TL'dir",fiyat);

   }
   else
   {
       printf("Yanlis tuslama yaptiniz\n");
   }
float odeme;
        printf("\n\t\t----ODEME EKRANINA HOSGELDINIZ----\n");
        printf("Lutfen odeme yapiniz=>");
        scanf("%f",&odeme);
        float paraustu=0;

        if(odeme<fiyat)


        {
         printf("\nEksik tutar girdiniz satis tamamlanamadi");
        }
        else
        {
            paraustu=odeme-fiyat;
            printf("Para ustunuz= %.2f",paraustu);
            printf("\nBizi tercih ettiginiz icin tesekkurler\n");
            printf("Tekrar gorusmek uzere,afiyet olsun :)");
        }





    printf("\n\n");
}
musteri_kayit_guncelleme()
{
    printf("---------------------------------------------------\n");
    printf("KULLANICI ISIM-SOYISIM HATA DUZELTME EKRANINDASINIZ\n");

    	int i,silinecek_id[80],yenisim[80];
    	printf("Ad-Soyad bilgilerini yanlis girdiginiz (guncelemek istediginiz) musterinin adini giriniz==>");
    	scanf("%s",&silinecek_id);
    	printf("\nKullanicinin duzeltilmis AD-SOYAD bilgilisini arasinda_ olacak sekilde yaziniz==>");
    	scanf( "%s",&yenisim);
    int kontrol;

	for(i=0;i<musteri_sayisi;i++)
        {
                kontrol=strcmp((mstr+i)->musteri_adsoyad,silinecek_id);

		if(kontrol==0)
		{
			strcpy((mstr+i)->musteri_adsoyad,&yenisim);

		}

	 }
	 printf("Kullanicinin isim soyisim bilgileri basariyla guncellenmistir.");

    }
void sil()
{

    int no,i,kullaniciid,*silineninadresi,*yerinegeleninadresi;
    char adsoyadlasilme[80];
    printf("Silmek istediginiz musterinin sirasini giriniz(2. musteri ise 2'i tuslayiniz) giriniz==>");//Hocam burdaki hatayý çözemedim sadece sonuncu musteriyi siliyor
    scanf("%d",&no);
    i=no;

        free (mstr);

    musteri_sayisi--;

    printf("Silme islemi basariyla tamamlandi.\n");

}




int main()
{
    int tercih;
    int silmek;
    printf("~~~~~~~~~YAMAN KAFE'YE HOSGELDINIZ~~~~~~~~~\n");
    do
    {
        printf("\n*************************************");
        printf("\nA)Yeni musteri kaydi olustumak icin -1- rakamini tuslayiniz");
        printf("\nB)Kayitli musterileri listelemek icin -2- rakamini tuslayiniz.");
          printf("\nC)Musterinin isim-soyad bilgilerini yanlis girdiyseniz guncelleme islemi icin -3- rakamini tuslayiniz.");
        printf("\nD)Musteri kayit silme islemi icin -4- rakamini tuslayiniz.");

        printf("\nE)Kafe menusune erisip  sepete ekleme islemi icin -5- rakamini tuslayiniz.");
        printf("\nF)Size ozel indirim tariflerinden yararlanabilmek icin -6- rakamini tuslayiniz.");
        printf("\nG)Otomosayondan cikis yapmak icin -7- rakamini tuslayiniz.");
        printf("\n************************************");
        printf("\nSeciminiz buraya tuslayiniz==>");
        scanf("%d",&tercih);
        musteri_bilgileri *mstr;
        switch (tercih)
        {
        case 1:
             mstr=ekle();
            break;
        case 2:

            kayitli_musteriler_listele(mstr);
            break ;
        case 4 :
            sil(mstr);
            break;
        case 3:
            musteri_kayit_guncelleme();
            break;
        case 5:
            menu();
            break;
        case 6:
            indirimhesaplama();
            break;
        }
    }
    while(tercih!=7);



}
