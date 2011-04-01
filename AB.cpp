#include "AB.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#define MAX_LINE_LENGTH 256

using namespace std;

/* ----------------------------------------------------------------------
   To select the orientation of the lattice
------------------------------------------------------------------------- */
AB::AB() : lattice()
{
  char str[MAX_LINE_LENGTH];
  alat = 1.; ca = 1.;
  // print out the menu
  printf("\n===========================================================\n");
  int lattype = 1;
  printf("Please select the type of your lattice:\n");
  printf("   1. B1 (NaCl);        4. L10 (CuAu);\n");
  printf("   2. B2 (CsCl);        5. B81 (a-NiAs);\n");
  printf("   3. B3 (Zincblende);\n");
  printf("Your choice[1]: ");
  if (count_words(gets(str)) > 0) sscanf(str,"%d",&lattype);
  printf("You selected  : %d\n", lattype);

  printf("Please input the lattice constant of the AB lattice [1.]:");
  if (count_words(gets(str)) > 0) sscanf(str,"%lg",&alat);
  if (lattype == 4 || lattype == 5){
    printf("Please input the c/a ratio of your lattice [1.]:");
    if (count_words(gets(str)) > 0) sscanf(str,"%lg",&ca);
  }
  printf("\n===========================================================\n");
  
  // initialize according to orientation
  initialized = 0;
  switch (lattype){
  case 1:
    AB_B1();
    break;
  case 2:
    AB_B2();
    break;
  case 3:
    AB_B3();
    break;
  case 4:
    AB_L10();
    break;
  case 5:
    AB_NiAs();
    break;
  default:
    break;
  }

}

/* ----------------------------------------------------------------------
   Deconstructor does nothing
------------------------------------------------------------------------- */
AB::~AB()
{

}

/* ----------------------------------------------------------------------
   Initialize for B1 lattice
------------------------------------------------------------------------- */
void AB::AB_B1()
{
  char str[MAX_LINE_LENGTH];
  int surftype = 1;
  // print out the menu
  printf("\n===========================================================\n");
  printf("Please selection the type of AB-B1 (NaCl) surface:\n");
  printf("   1. (001), small;\n");
  printf("   2. (001), conventional;\n");
  printf("   3. (110), long along y;\n");
  printf("   4. (111), long along x, orthogonal;\n");
  printf("   5. primitive cell;\n");
  printf("Your  choice [1]: ");
  if (count_words(gets(str)) > 0) sscanf(str,"%d",&surftype);
  printf("You selected: %d", surftype);
  printf("\n===========================================================\n");
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++) latvec[i][j] = 0.;
  }

  // initialize according to surface type
  switch (surftype){
  case 1:
    name = new char[11];
    strcpy(name, "AB-B1(001)");

    ntype  = 2;
    nucell = 4;
    
    latvec[0][0] = 1./sqrt(2.);
    latvec[1][1] = 1./sqrt(2.);
    latvec[2][2] = 1.;

    atpos = memory->create_2d_double_array(nucell, 3, "AB_B1_001_atpos");
    attyp = new int[nucell];
    
    attyp[0] = 2;
    atpos[0][0] = 0.5;
    atpos[0][1] = 0.5;
    atpos[0][2] = 0.;
    
    attyp[1] = 1;
    atpos[1][0] = 0.;
    atpos[1][1] = 0.;
    atpos[1][2] = 0.;
    
    attyp[2] = 2;
    atpos[2][0] = 0.;
    atpos[2][1] = 0.;
    atpos[2][2] = 0.5;
    
    attyp[3] = 1;
    atpos[3][0] = 0.5;
    atpos[3][1] = 0.5;
    atpos[3][2] = 0.5;

    initialized = 1;
    break;
  case 2:
    name = new char[11];
    strcpy(name, "AB-B1(001)");

    ntype  = 2;
    nucell = 8;
    
    latvec[0][0] = 1.;
    latvec[1][1] = 1.;
    latvec[2][2] = 1.;

    atpos = memory->create_2d_double_array(nucell, 3, "AB_B1_100_atpos");
    attyp = new int[nucell];

    attyp[0] = 2;
    atpos[0][0] = 0.5;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;
    
    attyp[1] = 2;
    atpos[1][0] = 0.;
    atpos[1][1] = 0.5;
    atpos[1][2] = 0.;
    
    attyp[2] = 1;
    atpos[2][0] = 0.;
    atpos[2][1] = 0.;
    atpos[2][2] = 0.;
    
    attyp[3] = 1;
    atpos[3][0] = 0.5;
    atpos[3][1] = 0.5;
    atpos[3][2] = 0.;
    
    attyp[4] = 2;
    atpos[4][0] = 0.5;
    atpos[4][1] = 0.5;
    atpos[4][2] = 0.5;
    
    attyp[5] = 2;
    atpos[5][0] = 0.;
    atpos[5][1] = 0.;
    atpos[5][2] = 0.5;
    
    attyp[6] = 1;
    atpos[6][0] = 0.;
    atpos[6][1] = 0.5;
    atpos[6][2] = 0.5;
    
    attyp[7] = 1;
    atpos[7][0] = 0.5;
    atpos[7][1] = 0.;
    atpos[7][2] = 0.5;
    
    initialized = 1;
    break;
  case 3:
    name = new char[11];
    strcpy(name, "AB-B1(110)");

    ntype  = 2;
    nucell = 4;
    
    latvec[0][0] = 1.;
    latvec[1][1] = 1./sqrt(2.);
    latvec[2][2] = 1./sqrt(2.);

    atpos = memory->create_2d_double_array(nucell, 3, "AB_B1_110_atpos");
    attyp = new int[nucell];
    
    attyp[0] = 1;
    atpos[0][0] = 0.;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;
    
    attyp[1] = 2;
    atpos[1][0] = 0.5;
    atpos[1][1] = 0.;
    atpos[1][2] = 0.;
    
    attyp[2] = 2;
    atpos[2][0] = 0;
    atpos[2][1] = 0.5;
    atpos[2][2] = 0.5;
    
    attyp[3] = 1;
    atpos[3][0] = 0.5;
    atpos[3][1] = 0.5;
    atpos[3][2] = 0.5;

    initialized = 1;
    break;
  case 4:
    name = new char[11];
    strcpy(name, "AB-B1(111)");

    ntype  = 2;
    nucell = 12;
    
    latvec[0][0] = sqrt(6.)/2.;
    latvec[1][1] = 1./sqrt(2.);
    latvec[2][2] = sqrt(3.);

    atpos = memory->create_2d_double_array(nucell, 3, "AB_B1_111_atpos");
    attyp = new int[nucell];
    
    attyp[0] = 1;
    atpos[0][0] = 0.;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;
    
    attyp[1] = 1;
    atpos[1][0] = 0.5;
    atpos[1][1] = 0.5;
    atpos[1][2] = 0.;
    
    attyp[2] = 2;
    atpos[2][0] = 1./3.;
    atpos[2][1] = 0.;
    atpos[2][2] = 1./6.;
    
    attyp[3] = 2;
    atpos[3][0] = 5./6.;
    atpos[3][1] = 0.5;
    atpos[3][2] = 1./6.;
    
    attyp[4] = 1;
    atpos[4][0] = 2./3.;
    atpos[4][1] = 0.;
    atpos[4][2] = 1./3.;
    
    attyp[5] = 1;
    atpos[5][0] = 1./6.;
    atpos[5][1] = 0.5;
    atpos[5][2] = 1./3.;
    
    attyp[6] = 2;
    atpos[6][0] = 0.;
    atpos[6][1] = 0.;
    atpos[6][2] = 0.5;
    
    attyp[7] = 2;
    atpos[7][0] = 0.5;
    atpos[7][1] = 0.5;
    atpos[7][2] = 0.5;
    
    attyp[8] = 1;
    atpos[8][0] = 1./3.;
    atpos[8][1] = 0.;
    atpos[8][2] = 2./3.;
    
    attyp[9] = 1;
    atpos[9][0] = 5./6.;
    atpos[9][1] = 0.5;
    atpos[9][2] = 2./3.;
    
    attyp[10] = 2;
    atpos[10][0] = 2./3.;
    atpos[10][1] = 0.;
    atpos[10][2] = 5./6.;
    
    attyp[11] = 2;
    atpos[11][0] = 1./6.;
    atpos[11][1] = 0.5;
    atpos[11][2] = 5./6.;

    initialized = 1;
    break;
  case 5:
    name = new char[16];
    strcpy(name, "AB-B1-primitive");

    ntype  = 2;
    nucell = 2;
    
    latvec[0][1] = 0.5;
    latvec[0][2] = 0.5;
    latvec[1][0] = 0.5;
    latvec[1][2] = 0.5;
    latvec[2][0] = 0.5;
    latvec[2][1] = 0.5;

    atpos = memory->create_2d_double_array(nucell, 3, "AB_B1_prim_atpos");
    attyp = new int[nucell];
    
    attyp[0] = 1;
    atpos[0][0] = 0.;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;
    
    attyp[1] = 2;
    atpos[1][0] = 0.5;
    atpos[1][1] = 0.5;
    atpos[1][2] = 0.5;
    
    initialized = 1;
    break;
  default:
    break;
  }
return;
}

/* ----------------------------------------------------------------------
   Initialize for B2
------------------------------------------------------------------------- */
void AB::AB_B2()
{
  char str[MAX_LINE_LENGTH];
  int surftype = 1;
  // print out the menu
  printf("\n===========================================================\n");
  printf("Please selection the type of AB-B2 (CsCl) surface:\n");
  printf("   1. (100);\n");
  printf("   2. (110);\n");
  printf("   3. (111);\n");
  printf("Your  choice [1]: ");
  if (count_words(gets(str)) > 0) sscanf(str,"%d",&surftype);
  printf("You selected: %d", surftype);
  printf("\n===========================================================\n");
  
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++) latvec[i][j] = 0.;
  }

  // initialize according to surface type
  switch (surftype){
  case 1:
    name = new char[11];
    strcpy(name, "AB-B2(001)");

    ntype  = 2;
    nucell = 2;
    
    latvec[0][0] = 1.;
    latvec[1][1] = 1.;
    latvec[2][2] = 1.;

    atpos = memory->create_2d_double_array(nucell, 3, "AB_B2_001_atpos");
    attyp = new int[nucell];
    
    attyp[0]    = 1;
    atpos[0][0] = 0.;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;

    attyp[1]    = 2;
    atpos[1][0] = 0.5;
    atpos[1][1] = 0.5;
    atpos[1][2] = 0.5;

    initialized = 1;
    break;
  case 2:
    name = new char[11];
    strcpy(name, "AB-B2(110)");

    ntype  = 2;
    nucell = 4;
    
    latvec[0][0] = 1.;
    latvec[1][1] = sqrt(2.);
    latvec[2][2] = sqrt(2.);

    atpos = memory->create_2d_double_array(nucell, 3, "AB_B2_110_atpos");
    attyp = new int[nucell];
    
    attyp[0] = 2;
    atpos[0][0] = 0.;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;
    
    attyp[1] = 1;
    atpos[1][0] = 0.5;
    atpos[1][1] = 0.5;
    atpos[1][2] = 0.;
    
    attyp[2] = 2;
    atpos[2][0] = 0.;
    atpos[2][1] = 0.5;
    atpos[2][2] = 0.5;
    
    attyp[3] = 1;
    atpos[3][0] = 0.5;
    atpos[3][1] = 0.;
    atpos[3][2] = 0.5;

    initialized = 1;
    break;
  case 3:
    name = new char[11];
    strcpy(name, "AB-B2(111)");

    ntype  = 2;
    nucell = 12;
    
    latvec[0][0] = sqrt(2.);
    latvec[1][1] = sqrt(6.);
    latvec[2][2] = sqrt(3.);

    atpos = memory->create_2d_double_array(nucell, 3, "AB_B2_111_atpos");
    attyp = new int[nucell];
    
    attyp[0] = 2;
    atpos[0][0] = 0.;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;
    
    attyp[1] = 2;
    atpos[1][0] = 0.5;
    atpos[1][1] = 0.5;
    atpos[1][2] = 0.;
    
    attyp[2] = 1;
    atpos[2][0] = 0.;
    atpos[2][1] = 2./3.;
    atpos[2][2] = 1./6.;
    
    attyp[3] = 1;
    atpos[3][0] = 0.5;
    atpos[3][1] = 1./6.;
    atpos[3][2] = 1./6.;
    
    attyp[4] = 2;
    atpos[4][0] = 0.;
    atpos[4][1] = 1./3.;
    atpos[4][2] = 1./3.;
    
    attyp[5] = 2;
    atpos[5][0] = 0.5;
    atpos[5][1] = 5./6.;
    atpos[5][2] = 1./3.;
    
    attyp[6] = 1;
    atpos[6][0] = 0.;
    atpos[6][1] = 0.;
    atpos[6][2] = 0.5;
    
    attyp[7] = 1;
    atpos[7][0] = 0.5;
    atpos[7][1] = 0.5;
    atpos[7][2] = 0.5;
    
    attyp[8] = 2;
    atpos[8][0] = 0.;
    atpos[8][1] = 2./3.;
    atpos[8][2] = 2./3.;
    
    attyp[9] = 2;
    atpos[9][0] = 0.5;
    atpos[9][1] = 1./6.;
    atpos[9][2] = 2./3.;
    
    attyp[10] = 1;
    atpos[10][0] = 0.;
    atpos[10][1] = 1./3.;
    atpos[10][2] = 5./6.;
    
    attyp[11] = 1;
    atpos[11][0] = 0.5;
    atpos[11][1] = 5./6.;
    atpos[11][2] = 5./6.;

    initialized = 1;
    break;
  default:
    break;
  }
return;
}

/* ----------------------------------------------------------------------
   Initialize for B3 lattice
------------------------------------------------------------------------- */
void AB::AB_B3()
{
  char str[MAX_LINE_LENGTH];
  int surftype = 1;
  // print out the menu
  printf("\n===========================================================\n");
  printf("Please selection the type of AB-B3 surface:\n");
  printf("   1. (100), small;\n");
  printf("   2. (100), conventional;\n");
  printf("   3. (110), long along y, orthogonal;\n");
  printf("   4. (111), long along y, orthogonal;\n");
  printf("   5. primitive;\n");
  printf("Your  choice [1]: ");
  if (count_words(gets(str)) > 0) sscanf(str,"%d",&surftype);
  printf("You selected: %d", surftype);
  printf("\n===========================================================\n");
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++) latvec[i][j] = 0.;
  }

  // initialize according to surface type
  switch (surftype){
  case 1:
    name = new char[11];
    strcpy(name, "AB-B3(100)");

    ntype  = 2;
    nucell = 4;
    
    latvec[0][0] = 1./sqrt(2.);
    latvec[1][1] = 1./sqrt(2.);
    latvec[2][2] = 1.;

    atpos = memory->create_2d_double_array(nucell, 3, "AB_B3_001_atpos");
    attyp = new int[nucell];
    
    attyp[0] = 1;
    atpos[0][0] = 0.;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;
    
    attyp[1] = 2;
    atpos[1][0] = 0.;
    atpos[1][1] = 0.50;
    atpos[1][2] = 0.25;
    
    attyp[2] = 1;
    atpos[2][0] = 0.50;
    atpos[2][1] = 0.50;
    atpos[2][2] = 0.50;
    
    attyp[3] = 2;
    atpos[3][0] = 0.50;
    atpos[3][1] = 0.00;
    atpos[3][2] = 0.75;

    initialized = 1;
    break;
  case 2:
    name = new char[11];
    strcpy(name, "AB-B3(100)");

    ntype  = 2;
    nucell = 8;
    
    latvec[0][0] = 1.;
    latvec[1][1] = 1.;
    latvec[2][2] = 1.;

    atpos = memory->create_2d_double_array(nucell, 3, "AB_B3_100_atpos");
    attyp = new int[nucell];
    
    attyp[0] = 1;
    atpos[0][0] = 0.;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;
    
    attyp[1] = 1;
    atpos[1][0] = 0.5;
    atpos[1][1] = 0.5;
    atpos[1][2] = 0.;
    
    attyp[2] = 2;
    atpos[2][0] = 0.25;
    atpos[2][1] = 0.25;
    atpos[2][2] = 0.25;
    
    attyp[3] = 2;
    atpos[3][0] = 0.75;
    atpos[3][1] = 0.75;
    atpos[3][2] = 0.25;
    
    attyp[4] = 1;
    atpos[4][0] = 0.;
    atpos[4][1] = 0.5;
    atpos[4][2] = 0.5;
    
    attyp[5] = 1;
    atpos[5][0] = 0.5;
    atpos[5][1] = 0.;
    atpos[5][2] = 0.5;
    
    attyp[6] = 2;
    atpos[6][0] = 0.75;
    atpos[6][1] = 0.25;
    atpos[6][2] = 0.75;
    
    attyp[7] = 2;
    atpos[7][0] = 0.25;
    atpos[7][1] = 0.75;
    atpos[7][2] = 0.75;

    initialized = 1;
    break;
  case 3:
    name = new char[11];
    strcpy(name, "AB-B3(110)");

    ntype  = 2;
    nucell = 4;
    
    latvec[0][0] = 1.;
    latvec[1][1] = 1./sqrt(2.);
    latvec[2][2] = 1./sqrt(2.);

    atpos = memory->create_2d_double_array(nucell, 3, "AB_B3_110_atpos");
    attyp = new int[nucell];
    
    attyp[0] = 1;
    atpos[0][0] = 0.;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;

    attyp[1] = 2;
    atpos[1][0] = 0.75;
    atpos[1][1] = 0.50;
    atpos[1][2] = 0.;
    
    attyp[2] = 2;
    atpos[2][0] = 0.25;
    atpos[2][1] = 0.;
    atpos[2][2] = 0.50;
    
    attyp[3] = 1;
    atpos[3][0] = 0.5;
    atpos[3][1] = 0.5;
    atpos[3][2] = 0.5;
    
    initialized = 1;
    break;
  case 4:
    name = new char[11];
    strcpy(name, "AB-B3(111)");

    ntype  = 2;
    nucell = 12;
    
    latvec[0][0] = sqrt(2.)*0.5;
    latvec[1][1] = sqrt(6.)*0.5;
    latvec[2][2] = sqrt(3.);

    atpos = memory->create_2d_double_array(nucell, 3, "AB_B3_111_atpos");
    attyp = new int[nucell];
    
    attyp[0] = 1;
    atpos[0][0] = 0.;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;
    
    attyp[1] = 1;
    atpos[1][0] = 0.50;
    atpos[1][1] = 0.50;
    atpos[1][2] = 0.;
    
    attyp[2] = 2;
    atpos[2][0] = 0.;
    atpos[2][1] = 0.;
    atpos[2][2] = 0.25;
    
    attyp[3] = 2;
    atpos[3][0] = 0.5;
    atpos[3][1] = 0.5;
    atpos[3][2] = 0.25;
    
    attyp[4] = 1;
    atpos[4][0] = 0.;
    atpos[4][1] = 2./3.;
    atpos[4][2] = 1./3.;
    
    attyp[5] = 1;
    atpos[5][0] = 0.5;
    atpos[5][1] = 1./6.;
    atpos[5][2] = 1./3.;
    
    attyp[6] = 2;
    atpos[6][0] = 0.;
    atpos[6][1] = 2./3.;
    atpos[6][2] = 7./12.;
    
    attyp[7] = 2;
    atpos[7][0] = 0.5;
    atpos[7][1] = 1./6.;
    atpos[7][2] = 7./12.;
    
    attyp[8] = 1;
    atpos[8][0] = 0.;
    atpos[8][1] = 1./3.;
    atpos[8][2] = 2./3.;
    
    attyp[9] = 1;
    atpos[9][0] = 0.5;
    atpos[9][1] = 5./6.;
    atpos[9][2] = 2./3.;
    
    attyp[10] = 2;
    atpos[10][0] = 0.5;
    atpos[10][1] = 5./6.;
    atpos[10][2] = 11./12.;
    
    attyp[11] = 2;
    atpos[11][0] = 0.;
    atpos[11][1] = 1./3.;
    atpos[11][2] = 11./12.;

    initialized = 1;
    break;
  case 5:
    name = new char[16];
    strcpy(name, "AB-B3-primitive");

    ntype  = 2;
    nucell = 2;
    
    latvec[0][1] = 0.5;
    latvec[0][2] = 0.5;
    latvec[1][0] = 0.5;
    latvec[1][2] = 0.5;
    latvec[2][0] = 0.5;
    latvec[2][1] = 0.5;

    atpos = memory->create_2d_double_array(nucell, 3, "AB_B3_primitive_atpos");
    attyp = new int[nucell];
    
    attyp[0] = 1;
    atpos[0][0] = 0.;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;

    attyp[1] = 2;
    atpos[1][0] = 0.25;
    atpos[1][1] = 0.25;
    atpos[1][2] = 0.25;
    
    initialized = 1;
    break;
  default:
    break;
  }
return;
}

/* ----------------------------------------------------------------------
   Initialize for L10 lattice
------------------------------------------------------------------------- */
void AB::AB_L10()
{
  char str[MAX_LINE_LENGTH];
  int surftype = 1;
  // print out the menu
  printf("\n===========================================================\n");
  printf("Please selection the type of AB-L10 surface:\n");
  printf("   1. (001);\n");
  printf("   2. (100);\n");
  printf("   3. (110), long along y, orthogonal;\n");
  printf("   4. primitive cell;\n");
  printf("Your  choice [1]: ");
  if (count_words(gets(str)) > 0) sscanf(str,"%d",&surftype);
  printf("You selected: %d", surftype);
  printf("\n===========================================================\n");
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++) latvec[i][j] = 0.;
  }

  // initialize according to surface type
  switch (surftype){
  case 1:
    name = new char[12];
    strcpy(name, "AB-L10(001)");

    ntype  = 2;
    nucell = 4;
    
    latvec[0][0] = 1.;
    latvec[1][1] = 1.;
    latvec[2][2] = ca;

    atpos = memory->create_2d_double_array(nucell, 3, "AB_L10_001_atpos");
    attyp = new int[nucell];

    attyp[0] = 1;
    atpos[0][0] = 0.;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;
    
    attyp[1] = 1;
    atpos[1][0] = 0.5;
    atpos[1][1] = 0.5;
    atpos[1][2] = 0.;
    
    attyp[2] = 2;
    atpos[2][0] = 0.5;
    atpos[2][1] = 0.;
    atpos[2][2] = 0.5;
    
    attyp[3] = 2;
    atpos[3][0] = 0.;
    atpos[3][1] = 0.5;
    atpos[3][2] = 0.5;

    initialized = 1;
    break;
  case 2:
    name = new char[14];
    strcpy(name, "AB-L10(100)");

    ntype  = 2;
    nucell = 4;
    
    latvec[0][0] = 1.;
    latvec[1][1] = ca;
    latvec[2][2] = 1.;

    atpos = memory->create_2d_double_array(nucell, 3, "AB_L10_100_atpos");
    attyp = new int[nucell];
    
    attyp[0] = 2;
    atpos[0][0] = 0.5;
    atpos[0][1] = 0.5;
    atpos[0][2] = 0.;
    
    attyp[1] = 1;
    atpos[1][0] = 0.;
    atpos[1][1] = 0.;
    atpos[1][2] = 0.;
    
    attyp[2] = 2;
    atpos[2][0] = 0.;
    atpos[2][1] = 0.5;
    atpos[2][2] = 0.5;
    
    attyp[3] = 1;
    atpos[3][0] = 0.5;
    atpos[3][1] = 0.;
    atpos[3][2] = 0.5;

    initialized = 1;
    break;
  case 3:
    name = new char[12];
    strcpy(name, "AB-L10(110)");

    ntype  = 2;
    nucell = 4;
    
    latvec[0][0] = ca;
    latvec[1][1] = sqrt(2.);
    latvec[2][2] = sqrt(2.)/2.;

    atpos = memory->create_2d_double_array(nucell, 3, "AB_L10_110_atpos");
    attyp = new int[nucell];
    
    attyp[0] = 1;
    atpos[0][0] = 0.;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;
    
    attyp[1] = 1;
    atpos[1][0] = 0.;
    atpos[1][1] = 0.5;
    atpos[1][2] = 0.;
    
    attyp[2] = 2;
    atpos[2][0] = 0.5;
    atpos[2][1] = 0.75;
    atpos[2][2] = 0.5;
    
    attyp[3] = 2;
    atpos[3][0] = 0.5;
    atpos[3][1] = 0.25;
    atpos[3][2] = 0.5;

    initialized = 1;
    break;
  case 4:
    name = new char[17];
    strcpy(name, "AB-L10-primitive");

    ntype  = 2;
    nucell = 2;
    
    latvec[0][0] = 1./sqrt(2.);
    latvec[1][1] = 1./sqrt(2.);
    latvec[2][2] = ca;

    atpos = memory->create_2d_double_array(nucell, 3, "AB_L10_primitive_atpos");
    attyp = new int[nucell];
    
    attyp[0] = 1;
    atpos[0][0] = 0.;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;
    
    attyp[1] = 2;
    atpos[1][0] = 0.5;
    atpos[1][1] = 0.5;
    atpos[1][2] = 0.5;

    initialized = 1;
    break;
  default:
    break;
  }
return;
}

/* ----------------------------------------------------------------------
   Initialize for a-NiAs lattice
------------------------------------------------------------------------- */
void AB::AB_NiAs()
{
  char str[MAX_LINE_LENGTH];
  int surftype = 1;
  // print out the menu
  printf("\n===========================================================\n");
  printf("Please selection the type of AB-a-NiAs surface:\n");
  printf("   1. (001), conventional;\n");
  printf("   2. (001), orthogonal;\n");
  printf("   3. (100);\n");
  printf("   4. (110), orthogonal, long along y;\n");
  printf("   5. (1-10), orthogonal, long along y;\n");
  printf("Your  choice [1]: ");
  if (count_words(gets(str)) > 0) sscanf(str,"%d",&surftype);
  printf("You selected: %d", surftype);
  printf("\n===========================================================\n");
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++) latvec[i][j] = 0.;
  }

  // initialize according to surface type
  switch (surftype){
  case 1:
    name = new char[13];
    strcpy(name, "AB-NiAs(001)");

    ntype  = 2;
    nucell = 4;
    
    latvec[0][0] = 1.;
    latvec[1][0] = -0.5;
    latvec[1][1] = sqrt(3.)/2.;
    latvec[2][2] = ca;

    atpos = memory->create_2d_double_array(nucell, 3, "AB_NiAs_001_atpos");
    attyp = new int[nucell];

    attyp[0] = 1;
    atpos[0][0] = 0.;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;
    
    attyp[1] = 2;
    atpos[1][0] = 1./3.;
    atpos[1][1] = 2./3.;
    atpos[1][2] = 0.25;
    
    attyp[2] = 1;
    atpos[2][0] = 0.;
    atpos[2][1] = 0.;
    atpos[2][2] = 0.5;
    
    attyp[3] = 2;
    atpos[3][0] = 2./3.;
    atpos[3][1] = 1./3.;
    atpos[3][2] = 0.75;

    initialized = 1;
    break;
  case 2:
    name = new char[13];
    strcpy(name, "AB-NiAs(001)");

    ntype  = 2;
    nucell = 8;
    
    latvec[0][0] = 1.;
    latvec[1][1] = sqrt(3.);
    latvec[2][2] = ca;

    atpos = memory->create_2d_double_array(nucell, 3, "AB_NiAs_001_atpos");
    attyp = new int[nucell];

    attyp[0] = 1;
    atpos[0][0] = 0.;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;
    
    attyp[1] = 1;
    atpos[1][0] = 0.5;
    atpos[1][1] = 0.5;
    atpos[1][2] = 0.;
    
    attyp[2] = 2;
    atpos[2][0] = 0.;
    atpos[2][1] = 2./3.;
    atpos[2][2] = 0.25;
    
    attyp[3] = 2;
    atpos[3][0] = 0.5;
    atpos[3][1] = 1./6.;
    atpos[3][2] = 0.25;
    
    attyp[4] = 1;
    atpos[4][0] = 0.;
    atpos[4][1] = 0.;
    atpos[4][2] = 0.5;
    
    attyp[5] = 1;
    atpos[5][0] = 0.5;
    atpos[5][1] = 0.5;
    atpos[5][2] = 0.5;
    
    attyp[6] = 2;
    atpos[6][0] = 0.;
    atpos[6][1] = 1./3.;
    atpos[6][2] = 0.75;
    
    attyp[7] = 2;
    atpos[7][0] = 0.5;
    atpos[7][1] = 5./6.;
    atpos[7][2] = 0.75;
    
    initialized = 1;
    break;
  case 3:
    name = new char[13];
    strcpy(name, "AB-NiAs(100)");

    ntype  = 2;
    nucell = 8;
    
    latvec[0][0] = 1.;
    latvec[1][1] = ca;
    latvec[2][2] = sqrt(3.);

    atpos = memory->create_2d_double_array(nucell, 3, "AB_NiAs_100_atpos");
    attyp = new int[nucell];

    attyp[0] = 1;
    atpos[0][0] = 0.;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;
    
    attyp[1] = 1;
    atpos[1][0] = 0.;
    atpos[1][1] = 0.5;
    atpos[1][2] = 0.;
    
    attyp[2] = 2;
    atpos[2][0] = 0.5;
    atpos[2][1] = 0.25;
    atpos[2][2] = 1./6.;
    
    attyp[3] = 2;
    atpos[3][0] = 0.;
    atpos[3][1] = 0.75;
    atpos[3][2] = 1./3.;
    
    attyp[4] = 1;
    atpos[4][0] = 0.5;
    atpos[4][1] = 0.;
    atpos[4][2] = 0.5;
    
    attyp[5] = 1;
    atpos[5][0] = 0.5;
    atpos[5][1] = 0.5;
    atpos[5][2] = 0.5;
    
    attyp[6] = 2;
    atpos[6][0] = 0.;
    atpos[6][1] = 0.25;
    atpos[6][2] = 2./3.;
    
    attyp[7] = 2;
    atpos[7][0] = 0.5;
    atpos[7][1] = 0.75;
    atpos[7][2] = 5./6.;

    initialized = 1;
    break;
  case 4:
    name = new char[13];
    strcpy(name, "AB-NiAs(110)");

    ntype  = 2;
    nucell = 8;
    
    latvec[0][0] = ca;
    latvec[1][1] = sqrt(3.);
    latvec[2][2] = 1.;

    atpos = memory->create_2d_double_array(nucell, 3, "AB_NiAs_110_atpos");
    attyp = new int[nucell];

    attyp[0] = 2;
    atpos[0][0] = 0.25;
    atpos[0][1] = 1./3.;
    atpos[0][2] = 0.;
    
    attyp[1] = 2;
    atpos[1][0] = 0.75;
    atpos[1][1] = 2./3.;
    atpos[1][2] = 0.;
    
    attyp[2] = 1;
    atpos[2][0] = 0.;
    atpos[2][1] = 0.;
    atpos[2][2] = 0.;
    
    attyp[3] = 1;
    atpos[3][0] = 0.5;
    atpos[3][1] = 0.;
    atpos[3][2] = 0.;
    
    attyp[4] = 2;
    atpos[4][0] = 0.25;
    atpos[4][1] = 5./6.;
    atpos[4][2] = 0.5;
    
    attyp[5] = 2;
    atpos[5][0] = 0.75;
    atpos[5][1] = 1./6.;
    atpos[5][2] = 0.5;
    
    attyp[6] = 1;
    atpos[6][0] = 0.;
    atpos[6][1] = 0.5;
    atpos[6][2] = 0.5;
    
    attyp[7] = 1;
    atpos[7][0] = 0.5;
    atpos[7][1] = 0.5;
    atpos[7][2] = 0.5;

    initialized = 1;
    break;
  case 5:
    name = new char[14];
    strcpy(name, "AB-NiAs(1-10)");

    ntype  = 2;
    nucell = 8;
    
    latvec[0][0] = 1.;
    latvec[1][1] = ca;
    latvec[2][2] = sqrt(3.);

    atpos = memory->create_2d_double_array(nucell, 3, "AB_NiAs_1m0_atpos");
    attyp = new int[nucell];

    attyp[0] = 1;
    atpos[0][0] = 0.;
    atpos[0][1] = 0.;
    atpos[0][2] = 0.;
    
    attyp[1] = 1;
    atpos[1][0] = 0.;
    atpos[1][1] = 0.5;
    atpos[1][2] = 0.;
    
    attyp[2] = 2;
    atpos[2][0] = 0.5;
    atpos[2][1] = 0.75;
    atpos[2][2] = 1./6.;
    
    attyp[3] = 2;
    atpos[3][0] = 0.;
    atpos[3][1] = 0.25;
    atpos[3][2] = 1./3.;
    
    attyp[4] = 1;
    atpos[4][0] = 0.5;
    atpos[4][1] = 0.;
    atpos[4][2] = 0.5;
    
    attyp[5] = 1;
    atpos[5][0] = 0.5;
    atpos[5][1] = 0.5;
    atpos[5][2] = 0.5;
    
    attyp[6] = 2;
    atpos[6][0] = 0.;
    atpos[6][1] = 0.75;
    atpos[6][2] = 2./3.;
    
    attyp[7] = 2;
    atpos[7][0] = 0.5;
    atpos[7][1] = 0.25;
    atpos[7][2] = 5./6.;

    initialized = 1;
    break;
  default:
    break;
  }
return;
}
