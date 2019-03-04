/*

 ------------------------------------------------------------------------ 
 |                    Analysis of C12E2 Mixed Bilayers                  | 
 ------------------------------------------------------------------------
 
 Author = "Sang Young Noh"

 Version = "0.0.1"
 
 Updated = 02/03/2019 

 The papers referenced for this work is:

 1. "F. C. MacKintosh and S. A. Safran, Phase Separation and curvature of bilayer membranes, Physical Review E, 47, 2, 1993"

 2. "R. Lipowsky, Domain-induced budding of fluid membranes, Biophysical Society, 64, 1993, 1133 - 1138"

 3. "J. Wolff and S. Komura and D. Andelman, Budding of domains in mixed bilayer domains, 91, Physical Review E, 91, 012708, 2015" 

*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>   // std::multiplies
#include <numeric>      // std::adjacent_differenc#include <cmath>
#include <bits/stdc++.h> 
#include <utility>
#include <cerrno>
#include <cstdlib> 
#include <cmath>
#include <tuple>
#include <boost/progress.hpp>

#include <complex> // Library for complex numbers

//#include <Eigen>
//#include <Eigen/Dense>
//using namespace Eigen;

const int numberOfPolymers = 998; // The number of polymers of each type - C12E2 or mimic 
const int numberofatoms = 71313; // Total number of beads in the simulation
const int indexCG = 7;
int numberofSS = 100; /*The number of screenshots in the dump file*/
const int boxdim = 3;

typedef struct {                                                                                                                              
  int index[7];
} C12E2_skeleton;

typedef struct {
  int a;
  int b;
  double x;
  double y;
  double z;
} inputCoord;

typedef struct { // Used to input the center of masses for each lipid
  double x;
  double y;
  double z;
} COMstruct;

typedef struct { // Used to input the center of masses for each lipid
  double dist;
  int topPhiC12E2Count;
  int topPhiC12E2MCount;
  int botPhiC12E2Count;
  int botPhiC12E2MCount;
} phiStruct;

typedef struct { // Used to input the center of masses for each lipid
  double phip;
  double phim;
} phipm;

typedef struct { // Used to identify the group and distance to compute the orderphobic effect  
  int index;
  double dist;
  double Xcoord;
  double Ycoord;
  double Zcoord;
} OPHstruct;


double CalculateOrderphobicEffect() {  
  std::complex<double>

  return double;
}

double trueDist(double* COM1x, double* COM1y, double* COM1z, double* COM2x, double* COM2y, double* COM2z) {
  double dist = pow((pow(*COM1x-*COM2x,2) + pow(*COM1y-*COM2y,2) + pow(*COM1z-*COM2z,2)),0.5);
  return dist;
}

// Function used for sorting vector of structs 
bool compareByIndex(const inputCoord &a, const inputCoord &b) {
    return a.a < b.a;
}

void CenterOfMass(std::vector<int>* vec1, std::vector<int>* vec2, std::vector<std::vector<inputCoord> >* inputVec,   std::vector<COMstruct>* COM1, std::vector<COMstruct>* COM2, std::vector<std::vector<COMstruct> >* C12E2final, std::vector<std::vector<COMstruct> >* C12E2Mfinal) {

  double C12E2comX, C12E2McomX; // X coordinate COM 
  double C12E2comY, C12E2McomY; // Y coordinate COM 
  double C12E2comZ, C12E2McomZ; // Z coordinate cCOM
  
  COMstruct C12E2input; // struct to store COM coordinates for C12E2
  COMstruct C12E2Minput; // struct to store cOM coordinates for C12E2M
  
  for (unsigned int i = 0; i < inputVec->size(); ++i) {
    for (unsigned int index = 0; index <= vec1->size()-1; ++index) {

      C12E2comX = (inputVec->at(i).at(vec1->at(index)).x + inputVec->at(i).at((vec1->at(index))+1).x + inputVec->at(i).at((vec1->at(index))+2).x + inputVec->at(i).at((vec1->at(index))+3).x + inputVec->at(i).at((vec1->at(index))+4).x + inputVec->at(i).at((vec1->at(index))+5).x + inputVec->at(i).at((vec1->at(index))+6).x)/7.0;

      C12E2comY = (inputVec->at(i).at(vec1->at(index)).y + inputVec->at(i).at((vec1->at(index))+1).x + inputVec->at(i).at((vec1->at(index))+2).y + inputVec->at(i).at((vec1->at(index))+3).y + inputVec->at(i).at((vec1->at(index))+4).y + inputVec->at(i).at((vec1->at(index))+5).y + inputVec->at(i).at((vec1->at(index))+6).y)/7.0;

      C12E2comZ = (inputVec->at(i).at(vec1->at(index)).z + inputVec->at(i).at((vec1->at(index))+1).z + inputVec->at(i).at((vec1->at(index))+2).z + inputVec->at(i).at((vec1->at(index))+3).z + inputVec->at(i).at((vec1->at(index))+4).z + inputVec->at(i).at((vec1->at(index))+5).z + inputVec->at(i).at((vec1->at(index))+6).z)/7.0;

      C12E2input.x = C12E2comX;
      C12E2input.y = C12E2comY;
      C12E2input.z = C12E2comZ;
      COM1->push_back(C12E2input);     
    }
    
    for (unsigned int index = 0; index < vec2->size()-1; ++index) {

      C12E2McomX = (inputVec->at(i).at(vec2->at(index)).x + inputVec->at(i).at((vec2->at(index))+1).x + inputVec->at(i).at((vec2->at(index))+2).x + inputVec->at(i).at((vec2->at(index))+3).x + inputVec->at(i).at((vec2->at(index))+4).x + inputVec->at(i).at((vec2->at(index))+5).x + inputVec->at(i).at((vec2->at(index))+6).x)/7.0;

      C12E2McomY = (inputVec->at(i).at(vec2->at(index)).y + inputVec->at(i).at((vec2->at(index))+1).x + inputVec->at(i).at((vec2->at(index))+2).y + inputVec->at(i).at((vec2->at(index))+3).y + inputVec->at(i).at((vec2->at(index))+4).y + inputVec->at(i).at((vec2->at(index))+5).y + inputVec->at(i).at((vec2->at(index))+6).y)/7.0;

      C12E2McomZ = (inputVec->at(i).at(vec2->at(index)).z + inputVec->at(i).at((vec2->at(index))+1).z + inputVec->at(i).at((vec2->at(index))+2).z + inputVec->at(i).at((vec2->at(index))+3).z + inputVec->at(i).at((vec2->at(index))+4).z + inputVec->at(i).at((vec2->at(index))+5).z + inputVec->at(i).at((vec2->at(index))+6).z)/7.0;
      C12E2Minput.x = C12E2comX;
      C12E2Minput.y = C12E2comY;
      C12E2Minput.z = C12E2comZ;
      COM2->push_back(C12E2Minput);   
    }
    
    C12E2final->push_back(*COM1);
    C12E2Mfinal->push_back(*COM2);
    COM1->clear();
    COM2->clear();

  }
}

bool sortbysec_int(const std::pair<int,int> &a, const std::pair<int,int> &b) { 
    return (a.second < b.second); 
}

bool sortbysec_double(const std::pair<int,double> &a, const  std::pair<int,double> &b) { 
    return (a.second < b.second); 
} 

//pointCluster* regionQuery (int , double*, double*, double*, double*, double*, double*);
//#define minClust 5 // the minimum sizes cluster we want to count as a cluster
class compute {
public:
  compute() {}; // Default constructor
  compute(std::string file) {}; // constructor reading file

  void storeFile() {    
    boost::progress_display show_progress(numberofSS);
    // open file for reading 
    ipf = fopen("dump.final", "r");  // Needs correction 
    // check for error opening file */

    if (ipf == NULL) {  
      std::cout << "Error opening file\n";
      exit(1);
    }
    // loop over the values  
    for (int SSno = 0; SSno < numberofSS; SSno++) {  

      l = 0;
      n = 0;
      index = 0;
      // Make sure to clear all vectors before going on to the next snapshot
      inputVector.clear();
      for (int k = 0; k < nlines; k++) { 
	// get a line from the file 
	// fgets() returns NULL when it reaches an error or end of file  

	fgets(line,sizeof(line),ipf);
	//while (fgets(line,sizeof(line),ipf) != NULL) {

	if (l < 5) {	
	  /* We are doing nothing */
	  //	printf("%s l= %d", line,l);
	  l++;
	}
	else if ((l > 4 && l < 8)) {
	  /*We are scanning the bit with just the box parameters*/
	  sscanf(line, "%lf %lf", &box1, &box2);
	  //	printf("%lf %lf \n",box1,box2 );
	  boxlength[l-5] = box2-box1; 
	  l++;
	}
	else if (l == 8) {
	  // printf(" **** l= %d \n",l);
	  /* We are doing nothing */
	  l++;
	}
	else {
	  //	printf(" ***** l = %d \n",l );
	  /* convert the text to numbers */
	  
	  sscanf(line,"%d %d %lf %lf %lf",&index,&atomtype,&x,&y,&z);
	  //std::cout << index << " " << atomtype << " " << x << " " << y << " " << z; 
	  //a.push_back(std::make_pair(index, index)); // Push back indices 
	  //b.push_back(std::make_pair(index, atomtype)); // Push back atomtypes
	  //xco.push_back(std::make_pair(index, x*boxlength[0])); // Push back boxlengths - x coordinates
	  //yco.push_back(std::make_pair(index, y*boxlength[1])); // Push back boxlengths - y coordinates
	  //zco.push_back(std::make_pair(index, z*boxlength[2])); // Push back boxlengths - z coordinates
	  inputline.a = index;
	  inputline.b = atomtype;
	  inputline.x = x*boxlength[0];
	  inputline.y = y*boxlength[1];
	  inputline.z = z*boxlength[2];
	  inputVector.push_back(inputline);
	  n++;
	  l++;
	  //printf("%d %d %lf %lf %lf\n",index,atomtype,x,y,z);
	}

      }
      inputTotal.push_back(inputVector);
      ++show_progress;
    }
  }

  void sortVectors () { // Sort vector values based on indices of the dump files 
    for (unsigned int i = 0; i < inputTotal.size(); ++i) {
      sort(inputTotal[i].begin(), inputTotal[i].end(), compareByIndex);
    }
  }
  
  void printVectorElements() {
     for (unsigned int i = 0; i < inputTotal.size(); ++i) {
	for (unsigned int j = 0; j < inputTotal[1].size(); ++j) {
	  //std::cout << i << " " << j << " " << " " << inputTotal[i][j].a << " " << inputTotal[i][j].b << " " <<  inputTotal[i][j].x << " " << inputTotal[i][j].y << " " << inputTotal[i][j].z << std::endl;

	}
     }
  }
 
  /*
  void CompositionProfile() {        
    //Calculating the composition profile 
    for (int i = 0; i <= sizeof(C12E2_struct)/sizeof(C12E2_struct[1])-1; i++) { // TODO

      //double truedist(double COM1x, double COM1y, double COM1z, double COM2x, double COM2y, double COM2z) {
      // See if the distance between the nanopparticle is smaller than 15 
      //std::cout << zco[71312] << std::endl;

      if (trueDist(xco[71312], yco[71312], zco[71312], headGroupC12_E2xCOM[i], headGroupC12_E2yCOM[i], headGroupC12_E2zCOM[i]) <= 25.000) { 
	// Check if the c12e2 molecule is on the top layer or the bottom layer
	if (headGroupC12_E2zCOM[i] > zco[71312]) { // If on the top layer
	  tophead++;
	}
	else if (headGroupC12_E2zCOM[i] < zco[71312]) { // If on the bottom layer
	  downhead++;
	}
      }
      
      // This time, working with mimics 
       if(trueDist(xco[71312], yco[71312], zco[71312], headGroupMIMCxCOM[i], headGroupMIMICyCOM[i], headGroupMIMICzCOM[i] ) <= 25.000) { 
	 if (headGroupMIMICzCOM[i] > zco[71312]) {
	   mimictophead++;
	 }
	 else if (headGroupMIMICzCOM[i] < zco[71312]) {
	   mimicdownhead++;
	   }
	 }  
       }
    
    
    //std::cout << SSno << " " << tophead/(tophead + mimictophead) << " " << mimictophead/(tophead + mimictophead) << " " << downhead/(downhead + mimicdownhead) << " " << mimicdownhead/(downhead + mimicdownhead) << " " << (tophead-mimictophead)/(tophead + mimictophead) << " " << (downhead-mimicdownhead)/(downhead + mimicdownhead) << " " << ((tophead-mimictophead)/(tophead + mimictophead) + (downhead-mimicdownhead)/(downhead + mimicdownhead))/2- << " " <<  ((tophead-mimictophead)/(tophead + mimictophead) - (downhead-mimicdownhead)/(downhead + mimicdownhead))/2 <<   std::endl; 
    }
  */
  
  void check() {  
    for (unsigned int i = 0; i < inputTotal.size(); ++i) {	
      for (unsigned int j = 0; j <= inputTotal[1].size(); j++) {
	if (inputTotal[i][j].b == 7) {
	  std::cout << inputTotal[i][j].a << " " << inputTotal[i][j].b << std::endl;
	  std::cout << inputTotal[i][j+1].a << " " << inputTotal[i][j+1].b << std::endl;
	  std::cout << inputTotal[i][j+2].a << " " << inputTotal[i][j+2].b << std::endl;
	  std::cout << inputTotal[i][j+3].a << " " << inputTotal[i][j+3].b << std::endl;
	  std::cout << inputTotal[i][j+4].a << " " << inputTotal[i][j+4].b << std::endl;
	  std::cout << inputTotal[i][j+5].a << " " << inputTotal[i][j+5].b << std::endl;
	  std::cout << inputTotal[i][j+6].a << " " << inputTotal[i][j+6].b << std::endl;
	} else if (inputTotal[i][j].b == 13) {
	  std::cout << inputTotal[i][j].a << " " << inputTotal[i][j].b << std::endl;
	  std::cout << inputTotal[i][j+1].a << " " << inputTotal[i][j+1].b << std::endl;
	  std::cout << inputTotal[i][j+2].a << " " << inputTotal[i][j+2].b << std::endl;
	  std::cout << inputTotal[i][j+3].a << " " << inputTotal[i][j+3].b << std::endl;
	  std::cout << inputTotal[i][j+4].a << " " << inputTotal[i][j+4].b << std::endl;
	  std::cout << inputTotal[i][j+5].a << " " << inputTotal[i][j+5].b << std::endl;
	  std::cout << inputTotal[i][j+6].a << " " << inputTotal[i][j+6].b << std::endl;
	}
      }
    }
  }

  void headGroupVectorFormation() {  
    for (unsigned int j = 0; j <= inputTotal[1].size(); j++) {   
      if (inputTotal[1][j].b == 7) {
        C12E2IndexVector.push_back(inputTotal[1][j].a); // push back C12E2 bead 7 indices (headgroups) 	
      } else if (inputTotal[1][j].b == 13) {
	C12E2MIndexVector.push_back(inputTotal[1][j].a); // push back C12E2 bead 7 indices (headgroups) 	
      }
    }
    for (unsigned int index = 0; index <  C12E2IndexVector.size(); ++index) {
      std::cout << C12E2IndexVector[index] << " " << C12E2MIndexVector[index]  << " " << std::endl; 
    }    
  }

  void ComputePhi() { // Computes the phi, or the mismatch between the bilayer leaflets around the NP

    /*
      Following Python's comment system """ """ 

      We are explcitily ignoring flip-flops in the case of this study       
    */
    
    for (unsigned int index = 0; index <= C12E2IndexVector.size(); index++) {	
	if (inputTotal[0][C12E2IndexVector[index]].z > 160.0)  {
	  topC12E2Index.push_back(C12E2IndexVector[index]);
	} else if (inputTotal[0][C12E2IndexVector[index]].z < 160.0) {
	  botC12E2Index.push_back(C12E2IndexVector[index]);
	}
      }

      for (unsigned int index = 0; index <= C12E2MIndexVector.size(); index++) {
	
	if (inputTotal[0][C12E2MIndexVector[index]].z > 160.0)  {
	  topC12E2MIndex.push_back(C12E2MIndexVector[index]);
	} else if (inputTotal[0][C12E2MIndexVector[index]].z < 160.0) {
	  botC12E2MIndex.push_back(C12E2MIndexVector[index]);
	}
      }

      for (std::vector<int>::iterator it = topC12E2Index.begin(); it != topC12E2Index.end(); it++) {
	//std::cout << *it << " " << std::endl;
	//	std::cout << topC12E2Index.size() << std::endl;
      }

      for (std::vector<int>::iterator it = botC12E2Index.begin(); it != botC12E2Index.end(); it++) {
	//std::cout << *it << " " << std::endl; 
	//	std::cout << botC12E2Index.size() << std::endl;
      }

      std::cout << topC12E2Index.size() << std::endl;
      std::cout << botC12E2Index.size() << std::endl;
		
      std::cout << topC12E2MIndex.size() << std::endl;
      std::cout << botC12E2MIndex.size() << std::endl;
      
      	 
      phiStruct phitemplate;


      for (unsigned int i = 0; i <= inputTotal.size()-1; ++i) {   

	for (unsigned phiIndex = 0; phiIndex <= 100; ++phiIndex) {
	  phitemplate.dist = phiIndex;
	  phitemplate.topPhiC12E2Count = 0;
	  phitemplate.botPhiC12E2Count = 0;
	  phitemplate.topPhiC12E2MCount = 0;
	  phitemplate.botPhiC12E2MCount = 0;
	  phiCount.push_back(phitemplate);
	}
	
	NPX = inputTotal[i][71312].x; // x coordinate of the NP  
	NPY = inputTotal[i][71312].y; // y coordinate of the NP
	NPZ = inputTotal[i][71312].z; // z coordinate of the NP 	

	int topC12E2Counter, botC12E2Counter, topC12E2MCounter, botC12E2MCounter;
	
	for (unsigned int dist = 0; dist <= 100; ++dist) {
	  
	  for (unsigned int index = 0; index < topC12E2Index.size(); index++) {
	    DistVec1 = trueDist(&NPX, &NPY, &NPZ, &inputTotal[i][topC12E2Index[index]].x, &inputTotal[i][topC12E2Index[index]].y, &inputTotal[i][topC12E2Index[index]].z);
	    if (DistVec1 <= dist + 0.5  && DistVec1 >= dist - 0.5) {
	      phiCount[dist].topPhiC12E2Count += 1;
	    }
	  }
	
	  for (unsigned int index = 0; index < botC12E2Index.size(); index++) {
	    DistVec2 = trueDist(&NPX, &NPY, &NPZ, &inputTotal[i][botC12E2Index[index]].x, &inputTotal[i][botC12E2Index[index]].y, &inputTotal[i][botC12E2Index[index]].z);
	    if (DistVec2 <= dist + 0.5  && DistVec2 >= dist - 0.5) {
	      phiCount[dist].botPhiC12E2Count += 1;
	    }
	  }
	  for (unsigned int index = 0; index < topC12E2MIndex.size(); index++) {
	    DistVec3 = trueDist(&NPX, &NPY, &NPZ, &inputTotal[i][topC12E2MIndex[index]].x, &inputTotal[i][topC12E2MIndex[index]].y, &inputTotal[i][topC12E2MIndex[index]].z);
	     if (DistVec3 <= dist + 0.5  && DistVec3 >= dist - 0.5) {
	       phiCount[dist].topPhiC12E2MCount += 1;
	     }
	  }
	  for (unsigned int index = 0; index < botC12E2MIndex.size(); index++) {
	    DistVec4 = trueDist(&NPX, &NPY, &NPZ, &inputTotal[i][botC12E2MIndex[index]].x, &inputTotal[i][botC12E2MIndex[index]].y, &inputTotal[i][botC12E2MIndex[index]].z);
	    if (DistVec4 <= dist + 0.5  && DistVec4 >= dist - 0.5) {
	      phiCount[dist].botPhiC12E2MCount += 1;
	    }
	  } 
	}
	phiTotal.push_back(phiCount);
	phiCount.clear();
      }
  }
  void PhiPrint () {
    phipm A; 

    for (unsigned phiIndex = 0; phiIndex <= 100; ++phiIndex) {
      A.phim = 0.0;
      A.phip = 0.0;
      NewNew.push_back(A);
    }
    
    double phi1, phi2;
    double phip, phim;
     
    for (unsigned int index = 0; index <= phiTotal.size()-1; index++) {

      for (unsigned int index2 = 0; index2 <= phiTotal[0].size(); index2++) {

	phi1 = 0.0;
	phi2 = 0.0;
	phip = 0.0;
	phim = 0.0;

	//std::cout << index << " " << index2 << " " <<  phiTotal[index][index2].topPhiC12E2Count << " " << phiTotal[index][index2].botPhiC12E2Count << " " << phiTotal[index][index2].topPhiC12E2MCount << " " << phiTotal[index][index2].botPhiC12E2MCount << std::endl;  
	if ((double)(phiTotal[index][index2].topPhiC12E2Count + phiTotal[index][index2].topPhiC12E2MCount) == 0.0 || (double)(phiTotal[index][index2].botPhiC12E2Count + phiTotal[index][index2].botPhiC12E2MCount) == 0) {
	  // Do nothing
	
	} else  {

	  phi1 = (double)(phiTotal[index][index2].topPhiC12E2Count - phiTotal[index][index2].topPhiC12E2MCount)/(double)(phiTotal[index][index2].topPhiC12E2Count + phiTotal[index][index2].topPhiC12E2MCount);  
	  phi2 = (double)(phiTotal[index][index2].botPhiC12E2Count - phiTotal[index][index2].botPhiC12E2MCount)/(double)(phiTotal[index][index2].botPhiC12E2Count + phiTotal[index][index2].botPhiC12E2MCount);

      }

	phip = phi2 + phi1/2.0;
	phim = phi2 - phi1/2.0; 

	NewNew[index2].phim += phim;
	NewNew[index2].phip += phip;
	
	std::cout << index << " " << index2 << " " << phip << " " << phim << std::endl;
      }
    }
  }
  void blah() {

    for (std::vector<phipm>::iterator it = NewNew.begin(); it != NewNew.end(); it++) {
      std::cout << " "  << it - NewNew.begin() << " " << (it->phim)/inputTotal.size() << " " << (it->phip)/inputTotal.size() << " " <<  std::endl;
    }
  }
  
  void ComputeOrderphobic() { // Computes the phi, or the mismatch between the bilayer leaflets around the NP

    double DIST, DIST2; // TODO
    double DISTM, DISTM2; // TODO

    OPHstruct C12E2sample;
    OPHstruct C12E2Msample;

    std::vector<std::vector<OPHstruct> > c12E2orderphobicVec; // TODO
    std::vector<std::vector<OPHstruct> > c12E2MorderphobicVec; // TODO
    std::vector<OPHstruct> c12E2orderphobic;
    std::vector<OPHstruct> c12E2Morderphobic;

    for (unsigned int i = 0; i < inputTotal.size(); ++i) {
      
      for (unsigned int index = 0; index <  C12E2IndexVector.size(); ++index) {
	
	for (unsigned int newindex = 0; newindex <  C12E2IndexVector.size(); ++newindex) {
	  DIST =  trueDist(&inputTotal[i][C12E2IndexVector[index]+4].x, &inputTotal[i][C12E2IndexVector[index]+4].y, &inputTotal[i][C12E2IndexVector[index]+4].z, &inputTotal[i][C12E2IndexVector[newindex]+4].x, &inputTotal[i][C12E2IndexVector[newindex]+4].y, &inputTotal[i][C12E2IndexVector[newindex]+4].z);
	  C12E2sample.index = C12E2IndexVector[index];
	  C12E2sample.dist = DIST;
	  C12E2sample.Xcoord = inputTotal[i][C12E2IndexVector[newindex]+4].x;
	  C12E2sample.Ycoord = inputTotal[i][C12E2IndexVector[newindex]+4].y;
	  C12E2sample.Ycoord = inputTotal[i][C12E2IndexVector[newindex]+4].z;
	  c12E2orderphobic.push_back(C12E2sample);
	}

	for (unsigned int newindex = 0; newindex <  C12E2IndexVector.size(); ++newindex) {
	  DISTM =  trueDist(&inputTotal[i][C12E2IndexVector[index]+4].x, &inputTotal[i][C12E2IndexVector[index]+4].y, &inputTotal[i][C12E2IndexVector[index]+4].z, &inputTotal[i][C12E2MIndexVector[newindex]+4].x, &inputTotal[i][C12E2MIndexVector[newindex]+4].y, &inputTotal[i][C12E2MIndexVector[newindex]+4].z);
	  C12E2sample.index = C12E2IndexVector[index];
	  C12E2sample.dist = DISTM;
	  C12E2sample.Xcoord = inputTotal[i][C12E2MIndexVector[newindex]+4].x;
	  C12E2sample.Ycoord = inputTotal[i][C12E2MIndexVector[newindex]+4].y;
	  C12E2sample.Ycoord = inputTotal[i][C12E2MIndexVector[newindex]+4].z;
	  c12E2orderphobic.push_back(C12E2Msample);
	}

	c12E2orderphobicVec.push_back(c12E2orderphobic);

	for (unsigned int newindex = 0; newindex <  C12E2MIndexVector.size(); ++newindex) {
	    DIST2 =  trueDist(&inputTotal[i][C12E2MIndexVector[index]+4].x, &inputTotal[i][C12E2MIndexVector[index]+4].y, &inputTotal[i][C12E2MIndexVector[index]+4].z, &inputTotal[i][C12E2IndexVector[newindex]+4].x, &inputTotal[i][C12E2IndexVector[newindex]+4].y, &inputTotal[i][C12E2IndexVector[newindex]+4].z);
	    C12E2Msample.index = C12E2MIndexVector[index];
	    C12E2Msample.dist = DIST2;
	    C12E2Msample.Xcoord = inputTotal[i][C12E2IndexVector[newindex]+4].x;
	    C12E2Msample.Ycoord = inputTotal[i][C12E2IndexVector[newindex]+4].y;
	    C12E2Msample.Ycoord = inputTotal[i][C12E2IndexVector[newindex]+4].z;
	    c12E2Morderphobic.push_back(C12E2Msample);
	}

	for (unsigned int newindex = 0; newindex <  C12E2MIndexVector.size(); ++newindex) {
	  DISTM2 =  trueDist(&inputTotal[i][C12E2MIndexVector[index]+4].x, &inputTotal[i][C12E2MIndexVector[index]+4].y, &inputTotal[i][C12E2MIndexVector[index]+4].z, &inputTotal[i][C12E2MIndexVector[newindex]+4].x, &inputTotal[i][C12E2MIndexVector[newindex]+4].y, &inputTotal[i][C12E2MIndexVector[newindex]+4].z);
	  C12E2Msample.index = C12E2MIndexVector[index];
	  C12E2Msample.dist = DISTM2;
	  C12E2Msample.Xcoord = inputTotal[i][C12E2MIndexVector[newindex]+4].x;
	  C12E2Msample.Ycoord = inputTotal[i][C12E2MIndexVector[newindex]+4].y;
	  C12E2Msample.Ycoord = inputTotal[i][C12E2MIndexVector[newindex]+4].z;
	  c12E2Morderphobic.push_back(C12E2Msample);  
	}
      
	c12E2MorderphobicVec.push_back(c12E2Morderphobic)
	std::cout << i << " " << index << " " << newindex << " " << DIST <<  " " << DIST2 << " "  << std::endl; 
      }

      // Final push_back 
      orderphobicC12E2.push_back(c12E2orderphobicVec);
      orderphobicC12E2M.push_back(c12E2MorderphobicVec);
      
    }
    
  }


  void allocateCOM() {
    CenterOfMass(&C12E2IndexVector, &C12E2MIndexVector, &inputTotal, &C12E2COM, &C12E2MCOM, &C12E2TotalCOMArray, &C12E2MTotalCOMArray);
  }


typedef struct { // Used to identify the group and distance to compute the orderphobic effect  
  int index;
  double dist;
  double Xcoord;
  double Ycoord;
  double Zcoord;
} OPHstruct;



private:    

  std::vector<OPHstruct> inputVector; // push back all structs
  std::vector< std::vector<std::vector<OPHstruct> > > orderphobicC12E2; 
  std::vector< std::vector<std::vector<OPHstruct> > > orderphobicC12E2M; 

  // Vectors to store trajectory values 
  std::vector<inputCoord> inputVector; // push back all structs
  std::vector<std::vector<inputCoord> > inputTotal; // push back vector of structs 
  std::vector<int> C12E2IndexVector; // push back C12E2 bead 7 indices (headgroups) 
  std::vector<int> C12E2MIndexVector; // push back all C12E2M bead 13 indices (headgroups)
  // Vectors to store the Centers of Mass 
  std::vector<COMstruct> C12E2COM;
  std::vector<COMstruct> C12E2MCOM;
  std::vector<phiStruct> phiCount;
  std::vector<std::vector<phiStruct> > phiTotal;   
  std::vector<std::vector<COMstruct> > C12E2TotalCOMArray;
  std::vector<std::vector<COMstruct> > C12E2MTotalCOMArray;
  
  // top head groups C12E2
  std::vector<int> topC12E2Index;
  // top head groups C12E2M
  std::vector<int> botC12E2Index;
  // bot head groups C12E2M
  std::vector<int> topC12E2MIndex;
  // bot head groups C12E2M
  std::vector<int> botC12E2MIndex;
  // TODO 
  std::vector<phipm> NewNew; // TODO - need to rename 
  
  FILE *ipf; /* input file */  

  double tophead = 0;
  double downhead = 0;
  double mimictophead = 0;
  double mimicdownhead = 0;
  
  int MimicCounter = 0;    
  int PolymerCounter = 0;    
  int atomtype; 
  int index, l, n;
  int nlines = numberofatoms + 9;      
  double x,y,z; /*coordinates for the atoms in the box*/
  double box1;
  double box2; 
  double NPX, NPY, NPZ;  
  double boxlength[boxdim];
  char line[100];  
  inputCoord inputline;
  double DistVec1, DistVec2, DistVec3, DistVec4;
  
};

class testClass {
};

// Intitiate test class

compute A;
  
int main (int argc, char *argv[])  {

  A.storeFile();
  A.sortVectors();
  A.check();
  A.headGroupVectorFormation();
  A.allocateCOM();
  //  A.ComputeOrderphobic();
  A.ComputePhi();
  A.PhiPrint();
  A.blah();
  
  return 0;    
}




