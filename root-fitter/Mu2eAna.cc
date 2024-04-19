/*
Driving function for analysis
*/

#include <fstream>
#include<iostream>
#include "Mu2eAna.hh"

using namespace std;

void ImportNTuple(std::string filename){

}

void RunFit(){
  std::cout<<" will call the RooFit part of the code "<<std::endl;
  //TODO - output yields of the fits as a tuple
}

int main(int argc, char* argv[]){
  std::cout<<"========== Welcome to Mu2eAna =========="<<std::endl;
  std::cout<<"-------- Analyzing "<<argv[1]<<"s ------------"<<std::endl;

  TString filename = argv[1]; // TrkAna NTuple
  RunFit();
  return 0;
}