#include <iostream>
#include <vector>
#include <fstream>
#include "geometry.h"
class Image{
    int width;
    int height;
    std::vector<Vector3<uint8_t>>frameBuffer;
public:
    Image(int width,int height):width(width),height(height){
        frameBuffer.resize(width*height);
    }
    void setPixel(int x,int y,Vector3<uint8_t>color){
        frameBuffer[x*height+y]=color;
    }
    void save(const char*imagePath){
        std::ofstream output;
        output.open(imagePath);
        output<<"P6\n"<<width<<" "<<height<<"\n255\n";
        for(auto color:frameBuffer){
            output<<color.x<<color.y<<color.z;
        }
        output.close();
    }
};
int main() {
    int width=512,height=512;
    Image image(width,height);
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            uint8_t r=255*i*1.0/width;
            uint8_t g=255*j*1.0/height;
            uint8_t b=255*(i*height+j)*1.0/(width*height);
            image.setPixel(i,j,{r,g,b});
        }
    }
    image.save("sample.ppm");
    return 0;
}
