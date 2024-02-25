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
    void save(const char*imagePath){
        std::ofstream output;
        output.open(imagePath);
        output<<"P6\n"<<width<<" "<<height<<"\n255\n";
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
