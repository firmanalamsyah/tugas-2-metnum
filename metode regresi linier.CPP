#include <stdio.h>
#include <conio.h>
#include <math.h>
#define Nmax 100

main(){
	int x[Nmax+1];
   int x2[Nmax+1];
   int y[Nmax+1];
   int y2[Nmax+1];
   int xy[Nmax+1];
   int n,i,elemen;
   int sigmax=0,sigmay=0,sigmax2=0,sigmaxy=0;
   float prediksi[Nmax+1];
   float nyata[Nmax+1];
   float m,c,eror,sigmapre=0,sigmanya=0;
   Home:
   clrscr();
   printf("Studi Kasus Perhitungan Lama Waktu Petugas Pengantar Barang Lazada\n");
   printf("Sehingga Petugas Lazada dapat Memastikan Barang Datang dengan perkiraan waktu yang tepat\n");
   printf("\njumlah data yang diujikan : ");scanf("%d",&n);
   if(n<2){
   	printf("gagal uji karena harus lebih dari 2");
      getch();
      goto Home;
   }
   else{
   for(i=1;i<=n;i++){
      printf("Jarak Petugas ke pelanggan-%d = ",i);scanf("%d",&elemen);
      x[i]=elemen;
      sigmax=sigmax+x[i];
      x2[i]=x[i]*x[i];
      sigmax2=sigmax2+x2[i];
   }
   printf("\n");
   for(i=1;i<=n;i++){
      printf("kira-kira waktu yang dapat ditempuh Petugas ke pelanggan-%d = ",i);scanf("%d",&elemen);
      y[i]=elemen;
      sigmay=sigmay+y[i];
      y2[i]=y[i]*y[i];
      //sigmay2=sigmay2+y2[i];
      xy[i]=x[i]*y[i];
      sigmaxy=sigmaxy+xy[i];
   }
	m=((n*sigmaxy)-(sigmax * sigmay))/((n*sigmax2)-pow(sigmax,2));
   c=((sigmay*sigmax2)-(sigmax*sigmaxy))/((n*sigmax2)-pow(sigmax,2));
   for(i=1;i<=n;i++){
      prediksi[i]=(m*x[i])+c;
      sigmapre=sigmapre+prediksi[i];
      nyata[i]=y[i]-prediksi[i];
      if(nyata[i]<0){
      	nyata[i]=prediksi[i]-y[i];
      }
      sigmanya=sigmanya+nyata[i];
   }
   printf("\nJarak dari Petugas ke pelanggan\n");
   for(i=1;i<=n;i++){
   	printf("%dKM|",x[i]);
   }
      //printf("\nTotal jarak %d \n",sigmax);
   printf("\n\nkira-kira waktu yang di tempuh Petugas ke pelanggan\n");
   for(i=1;i<=n;i++){
   	printf("%d/Jam|",y[i]);
   }
      //printf("\nTotal waktu %d\n",sigmay);
/*
   printf("X2 | ");
   for(i=1;i<=n;i++){
   	printf("%d |",x2[i]);
   }
      printf("Total waktu %d jam\n",sigmax2);
   printf("Y2 | ");
   for(i=1;i<=n;i++){
   	printf("%d |",y2[i]);
   }
      printf("Sigma y2 %d \n",sigmay2);
   printf("XY | ");
   for(i=1;i<=n;i++){
   	printf("%d |",xy[i]);
   }
	printf("Sigma xy %d \n",sigmaxy);
*/
   printf("\n\nPrediksi waktu\n");
   for(i=1;i<=n;i++){
   	printf("%.2f/jam|",prediksi[i]);
   }
      //printf("\nTotal prediksi waktu %.2f\n",sigmapre);
   printf("\n\nSelisih waktu perkiraan-prediksi\n");
   for(i=1;i<=n;i++){
   	printf("%.2f/menit|",nyata[i]);
   }
      //printf("\nTotal Selisih waktu perkiraan-prediksi %.2f \n",sigmanya);
   eror=sigmanya/n;
   printf("\n\nError: %.2f/menit",eror);
	printf("\n\nPetugas yang mengantarkan barang tersebut ke pelanggan dapat lebih cepat atau lebih lambat\n");
   printf("dengan selisih waktu %.2f/menit",eror);
   getch();
   }
return 0;
}
