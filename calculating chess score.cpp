#include <iostream>
#include <fstream>
using namespace std;

///////////////////////////////////////////////////Selman-Þahin tarafýndan tasarlanmýþtýr//////////////////////////////////////////////////////////////////////////////////////////////////
///////projede program board metinlerindeki yer alan yazýlarý okuyarak 8x8 lük 64 kareden oluþan matrix tablosuna aktarir . Karedeki koordinat bilgisi þu þekildedir
//// 0  1  2  3  4  5  6  7
//   8  9 10  11 12 13 14 15
///  ** ** ** ** **
///  56 57 58 59 60 61 62 63 ;   þeklidedir. Her bir koordinata taþlarýn renk, çeþit , puan bilgileri verilmiþtir. Daha sonra taþlarýn piyon , at ve vezir karþilarindaki tehdit durumlarý belirlenip bunlara göre puan hesaplanmiþtir.
/// proje çiktisi olarak yukardaki gibi tabloda taþlarin deðerlerini görebilirsiniz. siyah taþlar - iþaretli , beyaz taþlar + iþaretlidir.   165.Satirdaki metin okuma kod kisminda metni deðiþtirerek diðer sonuçlari kontrol edebilirsiniz. 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  





class nokta{
	public:
	int	x,y;
	int renk;
	float deger;
	int cesit;
	int kordinat;
	
	
	void kordinat_ata(int x1,int y1) // taplodaki  koordinatlar için numaralandýrma yapilmasi
	{

	x = x1;
	y = y1;
	kordinat =(y1*8) + x1;
	}
	
	
	
	
	
void renk_ata(int renk1) // renk atama foksiyonu
{
if (renk1 == 115)   //siyah renk -1
{

 renk = -1;
}
else if (renk1 == 98) // beyaz renk 1
{
	

renk = 1;
}

else {	

renk = 0;		
}	

}


void deger_ata(int d1)  // her taþin sahip olduðu puanlar atanmýþtýr.
{
if (d1 == 112) // piyon
{
 cesit = 1;
 deger = 1 ;
}
else if (d1 == 97) // at
{
	
cesit = 2;
deger = 3;
}

else if (d1 == 102) // fil
{
	
cesit = 3;
deger = 3;
}
else if (d1 == 107) // kale
{
	
cesit = 4;
deger = 5;
}

else if (d1 == 118)  // vezir
{
	
cesit = 5;
deger = 9;
}

else if (d1 == 115)  // þah
{
	
cesit = 6;
deger = 100;
}

else {	
cesit = 0;
deger = 0;
		
}	
}
	
};






int main() {
int k[8];
int k1[64];
int k2[64];
int k3[64];
int k4[64];

int a1[56];
int a2[56];
int a3[56];
int a4[56];

int b1[56];
int b2[56];
int b3[56];
int b4[56];
int a[8];
int b[8];
int kontrol[64];

float puan[64];
nokta dizi[64];
string satir;
int i1,j1,z1;
int i,j,t,r,e;
int h=0;
int z = 0;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//***************************************************************************************************************************






ifstream okumadosyasi;

okumadosyasi.open("board1.txt");  // yorum satýrýný silerek sonuçlandirilmasi istediðiniz board metnini seçiniz.

//  okumadosyasi.open("board2.txt"); 
 //okumadosyasi.open("board3.txt"); 




















////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////










 for(j=0; j<8; j++)
{
	
	
getline(okumadosyasi, satir); //satýrý tümden okumayý saðlar

//cout << j ;
     
for (i=0; i<23; i++)
{
z= i + (8*j);  // satýrdaki her harfi kontrol etmek için döngü



if((i+2)%3 == 0) // 1 - 4 - 7 þeklinde giden , boardtaki renk harfleri ni kontrol eder
{

i1 =((i-1)/3);
z= i1 +  (8*j);
dizi[z].renk_ata(satir.at(i)); // koordinatlara renkleri atama yapar
dizi[z].kordinat_ata(i1,j); // koordinatlara sayi olarak atama yapar. sol üstten 0 1 2 3 þeklinde baþlar sol üstten minimum sað alt maximumdur.
//cout << z ;
}


if((i%3) == 0)  // boardtaki taþlarin cinslarini kontrol eder, taþ cinsi bilgisi not defterinde 0 - 3 - 6 þeklinde siralanmiþtir 
{
i1 =((i)/3);
z= i1 +  (8*j);

dizi[z].deger_ata(satir.at(i)); // koordinaatlara her bir taþa uygun deðerler atanýr.
}

}


}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

for (z=0; z<64; z++)  
{

kontrol[z] = 0; // bir taþi etkileyen durumlari kontrol etmek için , birden fazla kez puan kýrmamak için.
puan[z]= (dizi[z].renk)*dizi[z].deger;   // tablodaki her kordinata taþýn rengine göre deðer atamasi yapiyor.puan[] dizi'ne renk beyazsa + , siyahsa - iþaretli deðerler yükleniyor.

}




for (z=0; z<64; z++) // taþlarýn birbirinlerine karþý tehditi hesaplama
{
	
	if (dizi[z].cesit == 2)  // atýn oluþturdðu tehdit durumlarý hesaplanir
	{
	
	k[1] = (a[1] = (dizi[z].x +2)) + 8*  (b[1] =(dizi[z].y +1)); // burada  ve alt satýrlarda atýn gidebileceði koordinatlar yer aliyor.
	k[2] = (a[2] = dizi[z].x +2) + 8* (b[2] = dizi[z].y -1);
	
	k[3] = (a[3] = dizi[z].x -2) + 8* (b[3] = dizi[z].y +1);
	k[4] = (a[4] = dizi[z].x -2) + 8* (b[4] = dizi[z].y -1);
	
	k[5] = (a[5] = dizi[z].x +1) + 8* (b[5] = dizi[z].y +2);
	k[6] = (a[6] = dizi[z].x -1) + 8* (b[6] = dizi[z].y +2 );

    k[7] = (a[7] = dizi[z].x +1) + 8* (b[7] = dizi[z].y -2);
	k[8] = (a[8] = dizi[z].x -1) + 8* (b[8] = dizi[z].y -2);	
	




	for (z1=1; z1<9; z1++)  
	{
	    if ((a[z1]<8 && a[z1]>=0) && (b[z1]<8 && b[z1]>=0)) // yukarda belirlenen atin gidebileceði koordinatlarin toblonun içeride mi diye kontrol ediliyor 
		 {

		 	
		 if	((dizi[z].renk == 1) && (puan[k[z1]]<0) && (kontrol[k[z1]] == 0 ))  // eðer atýn rengi beyaz ve gideceði renk siyahsa siyahin deðerini 2 ye bölüyor.
		 	{ 
		 	
		 	       
		 		kontrol[k[z1]] = 3;  // kontrol dizisine iþaret birakliyor. ayni taþi birden fazla kez 2 ye bölmemek için.
		 		puan[k[z1]] = puan[k[z1]] / 2;
		 		
			 }
			 
		 if	((dizi[z].renk == -1) && puan[k[z1]]>0  && (kontrol[k[z1]] == 0 ) ) // atin rengi beyaz ve hedef taþ siyah olma durumu,
		 	{
		 		
		 		kontrol[k[z1]] = 3;
		 		puan[k[z1]] = puan[k[z1]] / 2;
		 		
		 		
		 		
		 		
			 }
		 	
		 	
		 }

		 
		 
	}
	
	}
		
	

	
if ((dizi[z].cesit == 1)  && ( dizi[z].renk == 1 ))  // beyaz piyonun oluþturduðu tehdit durumlar
	{
	
	k[1] = (a[1] = dizi[z].x + 1) + 8*  (b[1] =  dizi[z].y -1);	// piyonun gidecebileceði koordinatlar
	k[2] = (a[2] = dizi[z].x  -1) + 8*  (b[2] =  dizi[z].y -1);


	for (z1=1; z1<3; z1++) 
	{
	    if ((a[z1]<8 && a[z1]>=0) && (b[z1]<8 && b[z1]>=0)) // bu koordinatlar tablonun içinde mi kontol edilir.
		 {
		 	
	 if  	(puan[k[z1]]<0 && (kontrol[k[z1]] == 0 )) // eðer piyonun gidebileceði yerler de siyaj taþ varsa , onun deðerini yarýya düþürür.
		 
		 	{
			    kontrol[k[z1]] = 3;
		 		puan[k[z1]] = puan[k[z1]] / 2;
		 		
			 }
		 		
		 }
		
			
	
	
}
	
   		

	
}



if ((dizi[z].cesit == 1)  && ( dizi[z].renk == -1 ))  // // siyah piyonun oluþturduðu tehdit durumlarý
	{
	
	k[1] = (a[1] = dizi[z].x + 1) +  8*  (b[1] =  dizi[z].y +1);	// piyonun gideceði koordinatlar
	k[2] = (a[2] = dizi[z].x  -1) +  8*  (b[2] =  dizi[z].y +1);


	for (z1=1; z1<3; z1++) 
	{
	    if ((a[z1]<8 && a[z1]>=0) && (b[z1]<8 && b[z1]>=0) &&  (kontrol[k[z1]] < 2)); // koordinatlar taplonun içinde mi kontrol edilir
		 {
		 	if  	( puan[k[z1]]>0   && (kontrol[k[z1]] == 0 )) // hedef taþ beyaz mi?
		 	{
			 
		 	    kontrol[k[z1]] = 3;
		 		puan[k[z1]] = puan[k[z1]] / 2; // hedef taþýn deðeri yariya indirilir.
	}
		 
		 }
		 
		 		
		
	
}
		
}





/////////////////////////////////////////////////////////////////
if ((dizi[z].cesit == 5)  ) // vezirin oluþturduðu tehdit durumlarý
	{
	
	for(t=1; t<8; t++)
	{		
	
	k1[t] = (a1[t] = dizi[z].x - t) +  8*  (b1[t] =  dizi[z].y -t); // sol üst çapraz hareketi

	if (((a1[t]>8 ) || (a1[t]<= 0)) || ((b1[t]>8 || (b1[t]<=0)) ||  (puan[k1[t]] != 0) )) // bu güzergahta karþisinda rakip taþ çikana kadar farkli bir taþ var mi , ya da taplonun diþina çikiliyor mu diye kontrol edilir.
	{
		
		
		if ( (((puan[k1[t]] < 0 ) && (dizi[z].renk > 0  )) || ((puan[k1[t]] > 0 ) && (dizi[z].renk < 0  )  ) ) &&  (kontrol[k1[t]] == 0) ) // hedef taþ rakipse , hedef taþin deðeri yariya indirilir.
		{
		
	puan[k1[t]] = puan[k1[t]] / 2;
kontrol[k1[t]] = 3;
}

	break;
}

//// diðer durumlarda yukardakine benzerdir. o yüzden sadece yönleri açikladim.

}
 
 	for(t=1; t<8; t++) 
	{		
	
	k1[t] = (a1[t] = dizi[z].x + t) +  8*  (b1[t] =  dizi[z].y + t);   /// sað - alt yönlü çapraz hareket

	if (((a1[t]>8 ) || (a1[t]<= 0)) || ((b1[t]>8 || (b1[t]<=0)) ||  (puan[k1[t]] != 0) ))
	{
		
		
		if ( (((puan[k1[t]] < 0 ) && (dizi[z].renk > 0  )) || ((puan[k1[t]] > 0 ) && (dizi[z].renk < 0  )  ) ) &&  (kontrol[k1[t]] == 0) )
		{
		
	puan[k1[t]] = puan[k1[t]] / 2;
	kontrol[k1[t]] = 3;
}
	break;
}
}

////////////////////////////////////////////////////////
 	for(t=1; t<8; t++)
	{		
	
	
	
	k1[t] = (a1[t] = dizi[z].x + t) +  8*  (b1[t] =  dizi[z].y - t); /// sað - üst yönlü çapraz hareket
	

	if (((a1[t]>8 ) || (a1[t]< 0)) || ((b1[t]>8 || (b1[t]<0)) ||  (puan[k1[t]] != 0) ))
	{
		
		
		if ( (((puan[k1[t]] < 0 ) && (dizi[z].renk > 0  )) || ((puan[k1[t]] > 0 ) && (dizi[z].renk < 0  )  ) ) &&  (kontrol[k1[t]] == 0) )
		{
		
	puan[k1[t]] = puan[k1[t]] / 2;
	kontrol[k1[t]] = 3;
}


	break;
}


}


 	for(t=1; t<8; t++)
	{		
	
	k1[t] = (a1[t] = dizi[z].x - t) +  8*  (b1[t] =  dizi[z].y + t); /// sol - alt yönlü çapraz hareket

	if (((a1[t]>8 ) || (a1[t]< 0)) || ((b1[t]>8 || (b1[t]<0)) ||  (puan[k1[t]] != 0) ))
	{
		
		
		if ( (((puan[k1[t]] < 0 ) && (dizi[z].renk > 0  )) || ((puan[k1[t]] > 0 ) && (dizi[z].renk < 0  )  ) ) &&  (kontrol[k1[t]] == 0) )
		{
		
	puan[k1[t]] = puan[k1[t]] / 2;
	kontrol[k1[t]] = 3;
}
	break;
}


}

 	for(t=1; t<8; t++)
	{		
	
	k1[t] = (a1[t] = dizi[z].x ) +  8*  (b1[t] =  dizi[z].y + t); /// düz aþaðý yönlü hareket

	if (((a1[t]>8 ) || (a1[t]< 0)) || ((b1[t]>8 || (b1[t]<0)) ||  (puan[k1[t]] != 0) ))
	{
		
		
		if ( (((puan[k1[t]] < 0 ) && (dizi[z].renk > 0  )) || ((puan[k1[t]] > 0 ) && (dizi[z].renk < 0  )  ) ) &&  (kontrol[k1[t]] == 0) )
		{
		
	puan[k1[t]] = puan[k1[t]] / 2;
	kontrol[k1[t]] = 3;
}
	break;
}


}

 	for(t=1; t<8; t++)
	{		
	
	k1[t] = (a1[t] = dizi[z].x ) +  8*  (b1[t] =  dizi[z].y - t); /// düz yukarý yönlü hareket

	if (((a1[t]>8 ) || (a1[t]< 0)) || ((b1[t]>8 || (b1[t]<0)) ||  (puan[k1[t]] != 0) ))
	{
		
		//cout   << t << " "  << a1[t] << " " << b1[t] << " " << puan[k1[t]] << endl ;
		//cout << "a11" << kontrol[k1[t]] << "  " << puan[k1[t]] << "  " << dizi[z].renk;
		
		if ( (((puan[k1[t]] < 0 ) && (dizi[z].renk > 0  )) || ((puan[k1[t]] > 0 ) && (dizi[z].renk < 0  )  ) ) &&  (kontrol[k1[t]] == 0) )
		{
	puan[k1[t]] = puan[k1[t]] / 2;
	kontrol[k1[t]] = 3;
}
	break;
}


}

 	for(t=1; t<8; t++)
	{		
	
	k1[t] = (a1[t] = dizi[z].x + t ) +  8*  (b1[t] =  dizi[z].y ); /// düz sað  yönlü hareket
	

	if (((a1[t]>8 ) || (a1[t]< 0)) || ((b1[t]>8 || (b1[t]<0)) ||  (puan[k1[t]] != 0) ))
	{
		
		
		if ( (((puan[k1[t]] < 0 ) && (dizi[z].renk > 0  )) || ((puan[k1[t]] > 0 ) && (dizi[z].renk < 0  )  ) ) &&  (kontrol[k1[t]] == 0) )
		{
		
	puan[k1[t]] = puan[k1[t]] / 2;
	kontrol[k1[t]] = 3;
}
	break;
}


}


 	for(t=1; t<8; t++)
	{		
	
	k1[t] = (a1[t] = dizi[z].x -t ) +  8*  (b1[t] =  dizi[z].y ); /// düz sol yönlü hareket
	

	if (((a1[t]>8 ) || (a1[t]< 0)) || ((b1[t]>8 || (b1[t]<0)) ||  (puan[k1[t]] != 0) ))
	{
		
		
		if ( (((puan[k1[t]] < 0 ) && (dizi[z].renk > 0  )) || ((puan[k1[t]] > 0 ) && (dizi[z].renk < 0  )  ) ) &&  (kontrol[k1[t]] == 0) )
		{
		
	puan[k1[t]] = puan[k1[t]] / 2;
	kontrol[k1[t]] = 3;
}
	break;
}


}
 
 
 
 
 
 
 

}

}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////














cout  << "--------SonuclaR ---------"  << endl   ;


float total1 =0;
float total2 =0;

for (z=0; z<64; z++)
{
	if(puan[z]>0)
{
		
total1 = puan[z] + total1;
}

	if(puan[z]<0)
{
		
total2 = puan[z] + total2;
}
}

total2 = total2*-1;

cout  << " beyaz taslarin toplam puani :         " << total1 << endl << endl << endl;
cout  << " siyah taslarin toplam puani :         " << total2 << endl << endl << endl;




cout  << "--------Deger Tablosu ---------"  << endl   ;


for (z=0; z<64; z++)
{
if (z%8 ==0)
{
	cout << endl;
}
 
cout  << puan[z] <<  "  " ;

}


okumadosyasi.close();
return 0;



}







