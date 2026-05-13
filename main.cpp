#include <iostream>
#include <iostream>
#include <vector>
#include <filesystem>
#include "Image_Class.h"
using namespace std;



void invert(Image &image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                image(i, j, k) =255- image(i, j, k);


            }
        }
    }
    cout<<"Image inverted successfully!\n";
}
Image rotate(Image &image,int x) {
    int W = image.width;
    int H = image.height;

    if (x==90)
    {Image rotat(H, W);
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                for (int k = 0; k < 3; k++) {

                    unsigned char pixell = image(j,i , k);
                    rotat.setPixel(H - 1 - i,j,  k, pixell); }
            }
        }
        return rotat;}
    else if (x==180)
    { Image rotat(W, H);
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                for (int k = 0; k < 3; k++) {
                    unsigned char pixell = image(j, i, k);
                    rotat.setPixel(W-1-j,H-1-i,  k, pixell);
                }
            }
        }
        return rotat;}
    else if (x==270) { Image rotat(H, W);
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                for (int k = 0; k < 3; k++) {
                    unsigned char pixell = image(j,i,  k);
                    rotat.setPixel(i, W-1-j,k, pixell);
                }

            }
        }
        return rotat;

    }

}
Image frame(Image image) {
    int n; cout<<"enter 1 for simple frame\n"
                 "enter 2 for double frame\n"
                 "enter 3 for decorated frame\n";
    cin>>n;
    if (n!=1&&n!=2&&n!=3) {
        cout<<"wrong input\n";
        cout<<"entre 1 or 2 or 3\n";
        cin>>n;
    }
    cout<<"enter frame size \n";
    int frameSize; cin>>frameSize;
    Image newImage(image.width+frameSize*2,image.height+frameSize*2);
    if (n==1)
    {
        for(int i =0 ; i<newImage.width ;i++) {
        for(int j=0; j<newImage.height;j++) {

                if (i<=frameSize||j<=frameSize|| i >= image.width+frameSize || j >= image.height+frameSize) {
                    newImage(i,j,0) = 220;
                    newImage(i,j,1) = 245;
                    newImage(i,j,2) = 245;
                }
            else
                for (int k = 0; k < 3; k++) {
                    newImage(i, j, k) = image(i - frameSize, j - frameSize, k);
                }

        }
    }
    }
    if (n==2) {int w=frameSize/2;

        for(int i =0 ; i<newImage.width ;i++) {
            for(int j=0; j<newImage.height;j++) {

                if (i<w||j<w|| i > newImage.width-w || j > newImage.height-w) {
                    newImage(i,j,0) = 220;
                    newImage(i,j,1) = 220;
                    newImage(i,j,2) = 220;
                }
                else if (i<frameSize||j<frameSize||i>=newImage.width-frameSize||j>=newImage.height-frameSize) {
                    newImage(i,j,1) = 180;
                    newImage(i,j,2) =180;
                    newImage(i,j,0) = 180;
                }
                else
                    for (int k = 0; k < 3; k++) {
                        newImage(i, j, k) = image(i - frameSize, j - frameSize, k);
                    }

            }
        }
    }
   if (n==3)
    {


        for (int i = 0; i < newImage.width; i++) {
            for (int j = 0; j < newImage.height; j++) {


                if (i <= frameSize || j <= frameSize ||i >= image.width + frameSize || j >= image.height + frameSize) {

                    if (((i / 5) + (j / 5)) % 2 == 0){

                        newImage(i, j, 0) = 220;
                        newImage(i, j, 1) = 220;
                        newImage(i, j, 2) = 220;
                    } else {
                        newImage(i, j, 0) = 180;
                        newImage(i, j, 1) = 180;
                        newImage(i, j, 2) = 180;
                    }
                    }
                else {

                    for (int k = 0; k < 3; k++) {
                        newImage(i, j, k) = image(i - frameSize, j - frameSize, k);
                    }
                }
            }
        }
    }

    cout<<" frame added \n";
    return newImage;

}


void blackandwhite(Image &image) {
    for(int i=0;i<image.width; i++) {
        for(int j=0;j<image.height; j++){
            unsigned int avg =0;
            for(int k=0;k<3; k++){
                avg+= image(i,j,k) ;
            }
            avg = avg/3;
            if(avg>=128){
                image(i,j,0)=255 ;
                image(i,j,1)=255;
                image(i,j,2)=255;}
            else{
                image(i,j,0)=0 ;
                image(i,j,1)=0;
                image(i,j,2)=0;
            }}
    }
    cout<<"Black & White filter applied successfully!\n";

}

void flip(Image &image){
    cout<<" flip horizontal (h)or vertical (v)"<<endl;
    char m;
    cin >> m;

    if (m=='h'){
        for(int i =0 ; i<image.width/2 ;i++){
          for(int j=0; j<image.height;j++){
           for(int k=0;k<3;k++){
                int x=image(i,j,k);
                image(i,j,k)=image(image.width-1-i,j,k);
                image(image.width-1-i,j,k)=x;}
           }}}
    else {
        for(int i =0 ; i<image.width ;i++){
            for(int j=0; j<image.height/2;j++){
                for(int k=0;k<3;k++){
                    int x=image(i,j,k);
                    image(i,j,k)=image(i,image.height-1-j,k);
                    image(i,image.height-1-j,k)=x;}
            }}}
            cout<<"Image flipped successfully!\n";
    }

void crop(Image &image){
int x ,y ,w,h;
    while (true)
    {
    cout << "enter starting point you want to crop from"<<endl;
    cin >> x >>y;
    cout << "enter the dimensions of new photo"<<endl;
    cin >> w>>h;
     if(w+x> image.width || y+h > image.height)
    {
        cout<<"enter valid dimensions"<<endl;
        continue;
    }
    else{
     break;
    }
    }
    Image newimg(w,h);
    for(int i=0 ; i<h ; i++){
        for(int j=0 ; j<w ; j++){
            for(int k=0 ; k<3 ; k++){
                newimg(j,i,k)=image(j+x,i+y,k);
            }
        }
    }
    image=newimg;
    cout<<"image cropped successfully!\n";

}
void resize(Image &image){
    cout<<" enter dimensions you want"<<endl;
    int x,y;
    cin>>x>>y;
    double pix_x =(double) image.width/x;
    double pix_y = (double)image.height/y;
    Image newimage(x,y);
    for(int i=0 ; i<y; i++){
        for(int j=0 ; j<x ; j++){
            for(int k=0 ; k<3 ;k++){
             int newpix_x=(int)(j*pix_x);
             int newpix_y=(int)(i*pix_y);
             if(newpix_x>= image.width)
             {newpix_x=image.width-1;}
             if(newpix_y>= image.height)
             {newpix_y=image.height-1;}
             newimage(j,i,k)=image(newpix_x,newpix_y,k);
            }
        }

    }
    image=newimage;
    cout << "image resized successfully!\n";

}

Image blur(Image image) {
    int h=image.height;
    int w=image.width;
    Image res(w,h);
    for(int i =0 ; i<image.width ;i++) {
        for(int j=0; j<image.height;j++) {
            int numofred=0,numofgreen=0,numofblue=0,numofpixel=0;
            for (int ki=-4; ki<=4; ki++) {
                for (int kj=-4; kj<=4; kj++) {
                    if (i+ki>0&&i+ki<image.width&&j+kj<image.height&&j+kj>0) {
                        numofred+=image(i+ki,j+kj,0);
                        numofgreen+=image(i+ki,j+kj,1);
                        numofblue+=image(i+ki,j+kj,2);
                        numofpixel++;
                    }
                }
            }
            res(i,j,0) = numofred/numofpixel;
            res(i,j,1) = numofgreen/numofpixel;
            res(i,j,2) = numofblue/numofpixel;
        }
    }
    cout<<"added blur to the image\n";
    return res;
}

Image resizeimage(const Image &image, int neww, int newh) {
    Image resized(neww, newh);
    for (int i = 0; i < newh; i++) {
        for (int j = 0; j < neww; j++) {
            int orig_j = j * image.width / neww;
            int orig_i = i * image.height / newh;
            for (int k = 0; k < image.channels; k++) {
                resized.setPixel(j, i, k, image.getPixel(orig_j, orig_i, k));
            }
        }
    }
    return resized;
}
Image cropimage(const Image &image, int w, int h) {
    Image cropped(w, h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < image.channels; k++) {
                cropped.setPixel(j, i, k, image.getPixel(j, i, k));
            }
        }
    }
    return cropped;
}
Image mergeimages(Image &image1, Image &image2) {
    if (image1.width == image2.width && image1.height == image2.height) {
        Image merged(image1.width, image1.height);
        for (int i = 0; i < image1.height; i++) {
            for (int j = 0; j < image1.width; j++) {
                for (int k = 0; k < image1.channels; k++) {
                    merged.setPixel(j, i, k, (image1.getPixel(j, i, k)+image2.getPixel(j,i,k))/2);
                }
            }
        }
        return merged;
    }
    else {
        cout<<"Images have diff sizes\n";
        cout<<"Enter(1) to resize both to the bigger size ,(2) to crop the smaller common area\n";
        int choice;
        cin>>choice;
        if (choice == 1) {
            int neww=max(image1.width,image2.width);
            int newh=max(image1.height,image2.height);
            Image resized1=resizeimage(image1,neww,newh);
            Image resized2=resizeimage(image2,neww,newh);
            return mergeimages(resized1,resized2);
        }
        else {
            int neww=min(image1.width,image2.width);
            int newh=min(image1.height,image2.height);
            Image croped1=cropimage(image1,neww,newh);
            Image croped2=cropimage(image2,neww,newh);
            return mergeimages(croped1,croped2);
        }
    }
}
Image merge(Image &image) {
    string  Imagename2;
    cout<<"Enter Second Image Name: \n";
    cin>>Imagename2;

    Image image2(Imagename2);
    Image merged=mergeimages(image,image2);
  return merged;

}
void gray(Image &image) {


    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int avg = 0;
            for (int k = 0; k < image.channels; k++) {
                avg += image(i, j, k);
            }
            avg /= image.channels;

            for (int k = 0; k < image.channels; k++) {
                image(i, j, k) = avg;
            }
        }
    }

}
void Darkenandlighten(Image &image,string mode,int persentage) {

    double f;
    if (mode=="1") {
        f=1+(persentage/100.0);
    }
    else if (mode=="0") {
        f=1-(persentage/100.0);
    }

    for (int i=0;i<image.width;i++) {
        for (int j=0;j<image.height;j++) {
            for (int k=0;k<image.channels;k++) {
                int newvalue=0;
                newvalue=int(image(i,j,k)*f);
                if (newvalue>255) {
                    newvalue=255;
                }
                else if (newvalue<0) {
                    newvalue=0;
                }
                image(i,j,k)=newvalue;
            }
        }
    }

}
void Detect_Image_Edges(Image &image) {

    Image gimage(image.width,image.height);
    for(int i=0;i<image.height;i++) {
        for(int j=0;j<image.width;j++) {
            int avg=0;
            for (int k=0;k<image.channels;k++) {
                avg+=image(i,j,k);

            }
            avg/=image.channels;
            for (int k=0;k<image.channels;k++) {
                gimage(i,j,k)=avg;
            }
        }

    }

    Image edgeimg(gimage.width,gimage.height);
    for(int y=1;y<gimage.height-1;y++) {
        for(int x=1;x<gimage.width-1;x++) {
            int left,right,up,down,dx,dy,totalchange,res;
            left = gimage(x - 1, y, 0);
            right = gimage(x + 1, y, 0);
            up = gimage(x, y - 1, 0);
            down = gimage(x, y + 1, 0);
            dx = abs(right-left);
            dy = abs(down-up);
            totalchange = dx + dy;
            if(totalchange>50)
                res = 0;
            else
                res=255;
            for(int k=0;k<gimage.channels;k++) {
                edgeimg(x,y,k) = res;
            }

        }
    }
   image=edgeimg;
}
void saveimage(Image &image , string &imageName){
    string newname;
    cout<<"save image with same name y/n"<<endl;
    char k;
    cin>>k;
    if(k=='y'||k=='Y'){
        image.saveImage(imageName);
        cout<<"saved as "<< imageName<<endl;
    }
    else{
        cout<<"enter new name"<<endl;
        while(true){
        cin>>newname;
        vector <string> extensions = {".jpg", ".jpeg", ".png", ".bmp",".JPG",".JPEG",".PNG",".BMP"};
        int n=newname.size();
        bool right=false;
        for(string ext : extensions){
            if(newname.substr(n-ext.size())==ext){
                image.saveImage(newname);
                cout<<"saved as "<< newname<<endl;
                right=true;
                break;
            }
        }
        if(right){
            break;
        }
        else{
            cout<<"enter valid extension"<<endl;
        }
        }
    }
}


int main() {
 string imageName;
    Image image;
    cout<<"Enter Image Name to load "<<endl;
    cin>>imageName;
    do {

            if (!filesystem::exists(imageName)) {
            cout<<"file not exist try agin"<<endl;
            cin>>imageName;
            continue;
        }



        vector <string> extensions = {".jpg", ".jpeg", ".png", ".bmp",".JPG",".JPEG",".PNG",".BMP"};
        int z = imageName.size();
        bool right=false;
        for(string ext : extensions){
        if(imageName.substr(z-ext.size())==ext){
                image= Image(imageName);
                right=true;
                break;
        }}

        if(right){
            break;
        }
        else{cout<<"enter valid extension"<<endl;
        cin >> imageName;
    }


    }while (true);


int option;
do {

    cout<<" Filters Menu :\n";
    cout<<"0 to exit \n";
    cout<<" enter 1 for grayscale  \n";
    cout<<"enter 2 for Black & White filter \n";
    cout<<"enter 3 for invert image \n";
    cout<<"enter 4 for darken&lighten image \n";
    cout<<"enter 5 for flip image \n";
    cout<<"enter 6 for rotate image \n";
    cout<<"enter 7 for blur image \n";
    cout<<"enter 8 for  frame \n";
    cout<<"enter 9 for  merge image \n";
    cout<<"enter 10 for crop image \n";
    cout<<"enter 11 for resize image \n";
    cout<<"enter 12 for  Detect Image Edges\n";
    cout<<"enter 13 for save the image \n";
    cin>>option;
    switch (option) {
        case 1:
            gray(image);

           cout<<"The image has been converted to grayscale successfully\n";

            break;
        case 2:
            blackandwhite(image);
            break;
        case 3:
            invert(image);
            break;
        case 4: {
            string mode;
            int persentage;
            cout << "enter mode: 1 for lighten, 0 for darken ";
            cin >> mode;
            if (mode!="0"&&mode!="1") {
                cout<<"invalid mode\n";cout<<"enter 0 or 1\n";
                cin>>mode;
            }
            cout << "Enter percentage ";
            cin >> persentage;
            if (persentage<0&&persentage>100) {
                cout<<"invalid percentage\n";
                cout<<"enter between or equal 0 and 100\n";
                cin>>persentage;
            }
            Darkenandlighten(image, mode, persentage);
            if (mode=="1") {
                cout<<"Brightness increased successfully\n";
            }
            else if (mode=="0") {
                cout<<"Brightness decreased successfully\n";
            }

            break;
        }
        case 5:
        { flip(image);
            break;
        }
        case 6: {
            int x;
            cout << "Enter rotation angle (90 / 180 / 270): ";
            cin >> x;
            if (x!=90&&x!=180&&x!=270) {
                cout<<"invalid angel\n";
                cout<<"enter 90 or 180 or 270\n";
                cin>>x;
            }
            image=rotate(image,x);cout<<"Image rotated successfully!\n";
            break;
        }
        case 7:
            image=blur(image);
            break;
        case 8:
            image=frame(image);
            break;
        case 9:
            image=merge(image);
            cout<<"Image merged successfully!\n";
            break;
        case 10:
            crop(image);
            break;
        case 11 :
            resize(image);
            break;
        case 12:
            Detect_Image_Edges(image);
            cout<<"The image edges have been detected successfully\n";
            break;

        case 13:
             saveimage(image ,imageName);
             break;

        case 0:
            cout<<"exiting program \n";
            break;
            default:
            cout<<"invalid option\n";
            break;



    }

}while (option !=0);


    return 0;
}