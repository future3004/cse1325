#include <iostream>
#include <fstream>
#include <iomanip>
#include <thread>
#include "mandelbrot.h"

int main(int argc, char *argv[]){
 int width, height, icount, nthreads;
 std::string filename;

 if(argc > 5){
  //for(int i = 1; i < argc; ++i){std::cout << argv[i] << "\n";}
  try{
   width = std::stoi(argv[1]);
   height = std::stoi(argv[2]);
   icount = std::stoi(argv[3]);
   nthreads = std::stoi(argv[4]);
   filename = argv[5];
  } catch(std::runtime_error e){
   std::cerr << "Invalid argument " << e.what() << std::endl;
   return -2;
  }
  
 } else {
   std::cout << "Invalid number of command line parameters, will use defaults \n" << std::endl;
   width = 1000;
   height = 1000;
   icount = 60;
   nthreads = 1;
   filename = "image.ppm";
 }
 
 std::cout << std::setw(10) << "width: " << width << std::setw(10) << "height: " << height << std::setw(10) << "icount: "
            << icount << std::setw(10) << "threads: " << nthreads << std::endl 
            << std::setw(10) << "wrote: " << filename << std::endl;
            
 std::ofstream ofs{filename};
 if(!ofs){
  //throw std::runtime_error{"Can't open file"};
  std::cerr << "Can't open file for storage." << std::endl;
  return -1;
 }
 
  Mandelbrot m{width, height, icount, nthreads};
  ofs << m;


  return 0;
}
