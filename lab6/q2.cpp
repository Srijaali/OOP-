/*
Name: Syeda Rija Ali
ID: 23K-0057
desc: Image updating values using random values and pointer
*/

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Image {
    private:
        int height;
        int width;
        int* image_data;
    public:
        Image(int height, int width , const int* image_data){
            this -> height = height;
            this -> width = width;
            //DMA to allocate memory
            this -> image_data = new int [height*width];
            //copying memory for allocation
            memcpy(this-> image_data , image_data , height*width*sizeof(int));
             for(int i=0; i< height*width; i++){
                this -> image_data[i] = image_data[i];
            }
        }

        Image(const Image& obj): height(obj.height),width(obj.width){
           //DMA to allocate memory
            this -> image_data = new int[height*width];
            //copying memory
            memcpy(this -> image_data , obj.image_data , height*width*sizeof(int));
            for(int i=0; i< height*width; i++){
                this -> image_data[i] = image_data[i];
            }
        }

        ~Image(){
            delete[] image_data;
        }

        void display(){
            cout<< "Image height: " << height << endl;
            cout << "Image Width: " << width << endl;
            cout << "Image data: " ;
            for(int i=0; i<height*width; i++){
                cout<< image_data[i] << " ";
            }
            cout << endl;
        }

        void updateData(){
            for(int i=0; i< height*width; i++){
                if(image_data[i]<=0){
                    image_data[i] = rand() % 255 + 1;
                }
            }
        }
};

int main(){
   int image_data[6] = {1,2,3,4,-5,6};

    Image i1(2,3,image_data);
    Image i2(i1);
//displaying the original data
    cout << "Original Image: " << endl;
    i1.display();
    cout << endl;
    cout << "Copied Image: " << endl;
    i2.display();
    cout << endl;
//updating the data
    i1.updateData();
    i2.updateData();
    cout << endl;
//displaying the updated data
cout<< "After updating: " << endl;
    i1.display();
    cout << endl;
    i2.display();

return 0;

}
