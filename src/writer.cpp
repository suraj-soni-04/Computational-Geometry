#include <fstream>
#include <stdexcept>
#include <iostream>
#include "../headers/Writer.h"
using namespace std;

void Writer::write(std::string &filePath,std::vector<GeomVector> &vectors)
{
    std::ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        cout << "Error while opening the file for writing."<<std::endl;
    }

    // Write triangles to the STL file
    for (const GeomVector &vector : vectors)
    {
        // Write each vertex of the triangle to the STL file
        outFile<<0.0<<" "<<0.0<<" "<<0.0<<endl;
        outFile <<vector.getX() << " " << vector.getZ() << " " << vector.getZ() << endl;
        
    }
    cout<<"Data written successfully...."<<endl;
    outFile.close();
}
