#include <stdio.h>
#include <string.h>
#define ARRAYSIZE 366

enum LMCconst {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ONZE, DOUZE, 
TREIZE, QUATORZE, QUINZE, SEIZE, DIXSEPT, DIXHUIT, DIXNEUF, VINGT, VINGTHUN, VINGTDEUX,
VINGTTROIS, VINGTQUATRE, VINGTCINQ, QUATREVINGT=80, NONANTEUN=91, NONANTEQUATRE=94};//just the way i like my constants, in Assembly
//Dix = ten, quatrevingt = eigthy, nonante = ninety, vingt = twenty
double yearlyaverage(double lacs[][EIGHT], int amount);
void compareAVG(double list[],double *avg, int *refferenceIndex, char state);
void higherThenTotalAVG(double tavg, double list[], double higher[]);
void lowerThenTotalAVG(double tavg, double list[], double lower[]);
void compareIndividual(double list[][EIGHT],double *largest, double *smallest, double *dateL, double *dateS, int lake);
void order(double *smallest, double *largest);

//helper funxtion for inputing all values in 2D array
void input(FILE *fp, double list[][EIGHT]){
        for(int i=0; i<ARRAYSIZE;i++){
            for(int j=0;j<EIGHT;j++){
                fscanf(fp,"%lf", list[i]+j);
            }
        }   
}

//basically Jaiveer's helper function for the date format thing
//but adjusted to work for this code
void ConvertDateFormat(double date,int *jour, int *moi){
    if (date<=31){
        *moi = ONE;//Janvier
        *jour=(int)date;
    }else if (date<=60){
        *moi = TWO;//fevrier
        *jour=(int)date-31;
    }else if (date<=91){
        *moi = THREE;//mars
        *jour=(int)date-60;
    }else if (date<=121){
        *moi=FOUR;//avril
        *jour=(int)date-91;
    }else if (date<=152){
        *moi=FIVE;//mai
        *jour=(int)date-121;
    }else if (date<=182){
        *moi=SIX;//juin
        *jour=(int)date-152;
    }else if (date<=213){
        *moi=SEVEN;//juillet
        *jour=(int)date-182;
    }else if (date<=244){
        *moi=EIGHT;//aout
        *jour=(int)date-213;
    }else if (date<=274){
        *moi=NINE;//septembre
        *jour=(int)date-244;
    }else if (date<=305){
        *moi=TEN;//octobre
        *jour=(int)date-274;
    }else if (date<=335){
        *moi=ONZE;//novembre
        *jour=(int)date-305;
    }else if (date<=366){
        *moi=DOUZE;//decembre
        *jour=(int)date-335;
    }
}

int main(){
    FILE *fichier;
    int ref;// to store index for list of lac strings
    double megaArray[ARRAYSIZE][EIGHT];
    double superior;
    double michigan, huron, erie, ontario, stClaireAvenueEast;
    double lacslist[SIX];
    double totalAvg;
    char largestAVG[VINGTCINQ];double largestAVGnum, largestdate; int largestDay, largestmonth;
    char smallestAVG[VINGTCINQ];double smallestAVGnum, smallestdate; int smallestDay, smallestmonth;
    double listHigher[SIX], listLower[SIX];
    char referenceArray[SIX][VINGTCINQ] ={"superior", "michigan", "huron", "erie", "ontario", "stClair"};

    fichier =fopen("CleanAvgWaterTemps.txt","r");
    for(int i=ZERO; i<SIX; i++){//put all the values of the list beack to zero
        listHigher[i]=ZERO;
        listLower[i]=ZERO;
    }
        //Question 1_____________________________________________________________________________________________________
        puts("");
        puts("__________Question 1__________");
        puts("");
        input(fichier,megaArray);
        superior = yearlyaverage(megaArray,TWO);
        michigan = yearlyaverage(megaArray,THREE);
        huron = yearlyaverage(megaArray,FOUR);
        erie = yearlyaverage(megaArray,FIVE);
        ontario = yearlyaverage(megaArray,SIX);
        stClaireAvenueEast = yearlyaverage(megaArray,SEVEN);
        lacslist[ZERO] =superior; lacslist[ONE]=michigan; lacslist[TWO]=huron; 
        lacslist[THREE]=erie;lacslist[FOUR]=ontario; lacslist[FIVE]=stClaireAvenueEast;

        totalAvg = (superior+michigan+huron+erie+ontario+stClaireAvenueEast)/SIX;

        printf("\nThe average yearly temperatures in lake Superior is %.2lf C", superior);
        printf("\nThe average yearly temperatures in lake Michigan is %.2lf C", michigan);
        printf("\nThe average yearly temperatures in lake Huron is %.2lf C", huron);
        printf("\nThe average yearly temperatures in lake Erie is %.2lf C", erie);
        printf("\nThe average yearly temperatures in lake Ontario is %.2lf C", ontario);
        printf("\nThe average yearly temperatures in lake StClair is: %.2lf C", stClaireAvenueEast);
        printf("\nThe total yearly average temperature is %.2lf C", totalAvg);

    /*//debug
    puts("");
    for(int i=0;i<ARRAYSIZE;i++){
        for(int j=0;j<EIGHT;j++){
            printf(" %lf", megaArray[i][j]);
        }
        puts("");
    }*/

    //Question 2_________________________________________________________________________________________________________________
    puts("");
    puts("__________Question 2__________");
    puts("");
    compareAVG(lacslist, &largestAVGnum, &ref, 'l'); strncpy(largestAVG, referenceArray[ref],VINGTCINQ); 
    compareAVG(lacslist, &smallestAVGnum, &ref, 's'); strncpy(smallestAVG, referenceArray[ref], VINGTCINQ);
    printf("\nThe lake with the largest average temperature is lake %s, with avg temp %.2lf C\n", largestAVG, largestAVGnum);
    printf("The lake with the smallest average temperature is lake %s, with avg temp %.2lf C\n", smallestAVG, smallestAVGnum);

    higherThenTotalAVG(totalAvg, lacslist, listHigher);
    printf("\nThe following lakes have an averge temperature higher than the overall average temperature: ");
    for(int i=ZERO; i<SIX; i++){
        if(listHigher[i]!=ZERO){
            printf("\t%s", referenceArray[i]);
        }
    }
    lowerThenTotalAVG(totalAvg, lacslist, listLower);
    printf("\nThe following lakes have an averge temperature lower than the overall average temperature: ");
    for(int i=ZERO; i<SIX; i++){
        if(listLower[i]!=ZERO){
            printf("\t%s", referenceArray[i]);
        }
    }

    //Question 3______________________________________________________________________________________________________________
    puts("");
    puts("__________Question 3__________");
    //variables are reused from question 2 so if your directyl copying this
    //make sure to change the appropriate variable name
    puts("");
    //Superior
    compareIndividual(megaArray, &largestAVGnum, &smallestAVGnum, &largestdate, &smallestdate, TWO);
    ConvertDateFormat(largestdate, &largestDay, &largestmonth);
    ConvertDateFormat(smallestdate,&smallestDay,&smallestmonth);
    printf("\nFor lake %s, the largest temp was %.2lf C on %d/%d/2020",referenceArray[TWO-TWO], largestAVGnum, largestDay, largestmonth);
    printf("\n\tThe smallest temp was %.2lf C on %d/%d/2020\n\n",smallestAVGnum, smallestDay, smallestmonth);

    //mchigan
    compareIndividual(megaArray, &largestAVGnum, &smallestAVGnum, &largestdate, &smallestdate, THREE);
    ConvertDateFormat(largestdate, &largestDay, &largestmonth);
    ConvertDateFormat(smallestdate,&smallestDay,&smallestmonth);
    printf("\nFor lake %s, the largest temp was %.2lf C on %d/%d/2020",referenceArray[THREE-TWO], largestAVGnum, largestDay, largestmonth);
    printf("\n\tThe smallest temp was %.2lf C on %d/%d/2020\n\n",smallestAVGnum, smallestDay, smallestmonth);

    //huron
    compareIndividual(megaArray, &largestAVGnum, &smallestAVGnum, &largestdate, &smallestdate, FOUR);
    ConvertDateFormat(largestdate, &largestDay, &largestmonth);
    ConvertDateFormat(smallestdate,&smallestDay,&smallestmonth);
    printf("\nFor lake %s, the largest temp was %.2lf C on %d/%d/2020",referenceArray[FOUR-TWO], largestAVGnum, largestDay, largestmonth);
    printf("\n\tThe smallest temp was %.2lf C on %d/%d/2020\n\n",smallestAVGnum, smallestDay, smallestmonth);

    //erie
    compareIndividual(megaArray, &largestAVGnum, &smallestAVGnum, &largestdate, &smallestdate, FIVE);
    ConvertDateFormat(largestdate, &largestDay, &largestmonth);
    ConvertDateFormat(smallestdate,&smallestDay,&smallestmonth);
    printf("\nFor lake %s, the largest temp was %.2lf C on %d/%d/2020",referenceArray[FIVE-TWO], largestAVGnum, largestDay, largestmonth);
    printf("\n\tThe smallest temp was %.2lf C on %d/%d/2020\n\n",smallestAVGnum, smallestDay, smallestmonth);

    //ontario
    compareIndividual(megaArray, &largestAVGnum, &smallestAVGnum, &largestdate, &smallestdate, SIX);
    ConvertDateFormat(largestdate, &largestDay, &largestmonth);
    ConvertDateFormat(smallestdate,&smallestDay,&smallestmonth);
    printf("\nFor lake %s, the largest temp was %.2lf C on %d/%d/2020",referenceArray[SIX-TWO], largestAVGnum, largestDay, largestmonth);
    printf("\n\tThe smallest temp was %.2lf C on %d/%d/2020\n\n",smallestAVGnum, smallestDay, smallestmonth);

    //St Clair
    compareIndividual(megaArray, &largestAVGnum, &smallestAVGnum, &largestdate, &smallestdate, SEVEN);
    ConvertDateFormat(largestdate, &largestDay, &largestmonth);
    ConvertDateFormat(smallestdate,&smallestDay,&smallestmonth);
    printf("\nFor lake %s, the largest temp was %.2lf C on %d/%d/2020",referenceArray[SEVEN-TWO], largestAVGnum, largestDay, largestmonth);
    printf("\n\tThe smallest temp was %.2lf C on %d/%d/2020\n\n",smallestAVGnum, smallestDay, smallestmonth);

    //Question #4______________________________________________________________________________________
    puts("");
    puts("__________Question 4__________");
    puts("");
    double warmest, coldest;
    int warmestDay, warmestMonth, coldestDay, coldestMonth;
    int warmrow, warmcol, coldrow, coldcol;
    warmest=megaArray[ZERO][TWO];
    coldest=megaArray[ZERO][TWO];
    for(int i=ZERO;i<ARRAYSIZE;i++){
    for(int j=TWO;j<EIGHT;j++){
      if(warmest<megaArray[i][j]){
        warmest=megaArray[i][j]; 
        warmrow=i+ONE; 
        warmcol=j-TWO;  
      }
      if(coldest>megaArray[i][j]){
        coldest=megaArray[i][j];
        coldrow=i+ONE;  
        coldcol=j-TWO; 
      }
    }
  }
  puts("");
  ConvertDateFormat(warmrow, &warmestDay, &warmestMonth);
  ConvertDateFormat(coldrow,&coldestDay, &coldestMonth);
  printf(" Overall warmest temperature: %0.2lf for lake %s at %d/%d/2020\n", 
  warmest, referenceArray[warmcol], warmestDay, warmestMonth);
  printf(" Overall coldest temperature: %0.2lf for lake %s at %d/%d/2020\n\n", 
  coldest, referenceArray[coldcol], coldestDay, coldestMonth);

    
    // Question #5_________________________________________________________________________________________________________
    puts("");
    puts("__________Question 5__________");
    puts("");

    double col[SIX]={ZERO,ZERO,ZERO,ZERO,ZERO,ZERO}, average[SIX]={ZERO,ZERO,ZERO,ZERO,ZERO,ZERO};

    for (int j=TWO;j<EIGHT;j++){
        for (int i=ZERO;i<ARRAYSIZE;i++){
            if (i>=171 && i<=264){
                col[j-TWO]=col[j-TWO] + megaArray[i][j];
            }
        }
        average [j-TWO]= col[j-TWO]/NONANTEQUATRE;
        printf ("Summer average temp for lake %s is %.2lf\n",referenceArray[j-TWO],average[j-TWO]);
    } 
    printf("\n");
 
    double supave;
    supave = col[ZERO]/NONANTEQUATRE;

    double michave;
    michave = col[ONE]/NONANTEQUATRE;
     
    double hurave;
    hurave = col[TWO]/NONANTEQUATRE;

 
    double erieave;
    erieave = col[THREE]/NONANTEQUATRE;
    
     
    double ontave;
    ontave = col[FOUR]/NONANTEQUATRE;
    
     
    double clairave;
    clairave = col[FIVE]/NONANTEQUATRE;
    
     
    printf("For summer, the lakes in order from warmest to coldest are: \n");
 
    order(&supave, &michave);
    order(&supave, &hurave);
    order(&supave, &erieave);
    order(&supave, &ontave);
    order(&supave, &clairave);
    order(&michave, &hurave);
    order(&michave, &erieave);
    order(&michave, &ontave);
    order(&michave, &clairave);
    order(&hurave, &erieave);
    order(&hurave, &ontave);
    order(&hurave, &clairave);
    order(&erieave, &ontave);
    order(&erieave, &clairave);
    order(&ontave, &clairave);

    printf("%s: %.2lf\n%s: %.2lf\n%s: %.2lf\n%s: %.2lf\n%s: %.2lf\n%s: %.2lf\n",
    referenceArray[THREE], supave, referenceArray[FIVE], michave, referenceArray[FOUR], hurave, referenceArray[ONE],
    erieave, referenceArray[TWO], ontave, referenceArray[ZERO], clairave);

// Question #6 ___________________________________________________________________________________________________________ 
puts("");
puts("__________Question 6__________");
puts("");

    double colw1[SIX] = {ZERO,ZERO,ZERO,ZERO,ZERO,ZERO};
    double colw2[SIX] = {ZERO,ZERO,ZERO,ZERO,ZERO,ZERO};
    double colw[SIX] = {ZERO,ZERO,ZERO,ZERO,ZERO,ZERO};
    double averagew[SIX] = {ZERO,ZERO,ZERO,ZERO,ZERO,ZERO};
    for (int j=TWO; j<EIGHT;j++){
            for (int i=ZERO;i<ARRAYSIZE;i++){
                if (i>=ZERO && i<=QUATREVINGT) {
                    colw1[j-TWO]+= megaArray[i][j];
                }
                
                if (i>=355 && i<=ARRAYSIZE){
                    colw2[j-TWO]+=megaArray[i][j];
                }
            }
            colw[j-TWO] = colw2[j-TWO] + colw1[j-TWO];
            averagew[j-TWO]= colw[j-TWO]/NONANTEUN;
            printf ("Winter average temp for lake %s is %.2lf\n", referenceArray[j-TWO], averagew[j-TWO]);
        } 
    printf("\n");
     
    double wsupave;
    wsupave = colw[ZERO]/NONANTEUN;


    double wmichave;
    wmichave = colw[ONE]/NONANTEUN;

 
    double whurave;
    whurave = colw[TWO]/NONANTEUN;
    
     
    double werieave;
    werieave = colw[THREE]/NONANTEUN;
    
 
    double wontave;
    wontave = colw[FOUR]/NONANTEUN;
    
     
    double wclairave;
    wclairave = colw[FIVE]/NONANTEUN;
     
    printf("For winter, the lakes in order from warmest to coldest are: \n");

    order(&wsupave, &wmichave);
    order(&wsupave, &whurave);
    order(&wsupave, &werieave);
    order(&wsupave, &wontave);
    order(&wsupave, &wclairave);
    order(&wmichave, &whurave);
    order(&wmichave, &werieave);
    order(&wmichave, &wontave);
    order(&wmichave, &wclairave);
    order(&whurave, &werieave);
    order(&whurave, &wontave);
    order(&whurave, &wclairave);
    order(&werieave, &wontave);
    order(&werieave, &wclairave);
    order(&wontave, &wclairave);

    printf("%s: %.2lf\n%s: %.2lf\n%s: %.2lf\n%s: %.2lf\n%s: %.2lf\n%s: %.2lf\n",referenceArray[THREE], 
    wsupave, referenceArray[FIVE], wmichave, referenceArray[FOUR], whurave, referenceArray[ONE], werieave, referenceArray[TWO], 
    wontave, referenceArray[ZERO], wclairave);
    printf ("\n");

    //Question 7_________________________________________________________________________________________________________________
    //Assuming that you can swim comfortably in the lake if the temperature is above 20 degrees. 
    //Calculate the number of days in the year you can swim for each of the 6 lakes.  
    puts("");
    puts("__________Question 7__________");
    puts("");

    int Superior, Michigan, Huron, Erie, Ontario, StClair;

    for (int i = ZERO; i < ARRAYSIZE; i++)
	{
		if (megaArray[i][TWO] > VINGT){
			Superior++;
		}
		if (megaArray[i][THREE] > VINGT){
			Michigan++;
		}
		if (megaArray[i][FOUR] > VINGT){
			Huron++;
		}
		if (megaArray[i][FIVE] > VINGT){
			Erie++;
		}
		if (megaArray[i][SIX] > VINGT){
			Ontario++;
		}
		if (megaArray[i][SEVEN] > VINGT){
			StClair++;
		}
	}

	printf ("The Number of Days you can swim comfortably thorughout the year in lake are the folllowing: \n\t||Superior = %d\tMichigan = %d\tHuron = %d||\n\t||Erie = %d\tOntario = %d\tSaint Clair = %d||\n", Superior, Michigan, Huron, Erie, Ontario, StClair);
    
    //Question 8________________________________________________________________________________________________________________
    //Calculate the number of days in the year that the lake is frozen for each of the 6 lakes.
    puts("");
    puts("__________Question 8__________");
    puts("");

	Superior = ZERO;Michigan = ZERO;Huron = ZERO;Erie = ZERO;Ontario = ZERO;StClair = ZERO;

	for (int i = ZERO; i < ARRAYSIZE; i++){
		if (megaArray[i][TWO] < ZERO){
			Superior++;
		}
		if (megaArray[i][THREE] < ZERO){
			Michigan++;
		}
		if (megaArray[i][FOUR] < ZERO){
			Huron++;
		}
		if (megaArray[i][FIVE] < ZERO){
			Erie++;
		}
		if (megaArray[i][SIX] < ZERO){
			Ontario++;
		}
		if (megaArray[i][SEVEN] < ZERO){
			StClair++;
		}
	}

	printf ("\nThe Number of days each lake freezes throughout the year are the following:\n\t||Superior = %d \tMichigan = %d \tHuron = %d||\n\t||Erie = %d \tOntario = %d \tSaint Clair = %d||\t", 
    Superior, Michigan, Huron, Erie, Ontario, StClair);
    fclose(fichier);//dont need the 2020 file anymore

    //Question 9__________________________________________________________________________________________________________________
    //Calculate the yearly average temperature for each of the lakes, 
    //and the yearly average for all six lakes put together for year 2019.
    puts("");
    puts("__________Question 9__________");
    puts("");
    FILE *ot = fopen ("2019Data.txt", "r");
    double avg2019;

	int y;
	double lakee[ARRAYSIZE-ONE][EIGHT];
	double n1 = ZERO, n2 = ZERO, n3 = ZERO, n4 = ZERO, n5 = ZERO, n6 = ZERO;

    input(ot, lakee);

	for (int w = ZERO; w < (ARRAYSIZE-ONE); w++){
		n1 += lakee[w][TWO];
		n2 += lakee[w][THREE];
		n3 += lakee[w][FOUR];
		n4 += lakee[w][FIVE];
		n5 += lakee[w][SIX];
		n6 += lakee[w][SEVEN];
	}
// lakee is the varibale used for the 2019 data for water temperatures. 
    // Scanned data put into a counter. Counts up once the initial average diviison is completed. 
	n1 /=(ARRAYSIZE-ONE);
	n2 /=(ARRAYSIZE-ONE);
	n3 /=(ARRAYSIZE-ONE);
	n4 /=(ARRAYSIZE-ONE);
	n5 /=(ARRAYSIZE-ONE);
	n6 /=(ARRAYSIZE-ONE);

	printf ("\n\nThe yearly average temperature for each lake in 2019 is as follows:\n\t||Lake Superior: %.2lf \tLake Michigan: %.2lf \tLake Huron: %.2lf|| \n\t||Lake Erie: %.2lf\tLake Ontario: %.2lf\tLake Saint Clair: %.2lf||\t",
     n1, n2, n3, n4, n5, n6);

	avg2019 = (n1 + n2 + n3 + n4 + n5 + n6) / SIX;
	printf ("\nThe average temperature for all the lakes in the year 2019 is: %.2lf",avg2019);

    printf("\n\nAverages for 2020 and 2019 (all measurements in degrees Celcius)\n");
    printf("Lakes|\tSuperior\tMichigan\tHuron\t\tErie\t\tOntario\t\tStClair\t\tTotal\n");
    puts("___________________________________________________________________________________________________________________");
    printf("2019 |\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\n", n1,n2,n3,n4, n5, n6, avg2019);
    printf("2020 |\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\n", superior,michigan,huron,erie, ontario, stClaireAvenueEast, totalAvg);

    fclose(ot);

    // close file  -- NOTE* major french variables where used becuase of the lact of certin repeaing variable.
    return ZERO;
}

//takes average of one function
double yearlyaverage(double lacs[][EIGHT], int j){
    double avg;
    for(int i=0; i<ARRAYSIZE; i++){
        avg += lacs[i][j];
    }
    avg=avg/ARRAYSIZE;
    return avg;
}

void compareAVG(double list[],double *avg, int *refferenceIndex, char state){
    *refferenceIndex=ZERO;
    switch(state){
        case 'l':
        case 'L':
            *avg =list[ZERO];
            for(int i=0; i<SIX; i++){
                if(list[i]>*avg){
                    *avg=list[i];
                    *refferenceIndex =i;
                }
            }
            break;
        case 's':
        case 'S':
            *avg =list[ZERO];
            for(int i=0; i<SIX; i++){
                if(list[i]<*avg){
                    *avg=list[i];
                    *refferenceIndex =i;
                }
            }
            break;
        default:
            printf("\n!code do be broken!\n"); // notif if the porgram is no longer abele to run
            break;
    }
}

void higherThenTotalAVG(double tavg, double list[], double higher[]){
    for(int i=0;i<SIX;i++){
        if(list[i]>tavg){
            higher[i]=list[i];
        }
    }
}

void lowerThenTotalAVG(double tavg, double list[], double lower[]){
    for(int i=0;i<SIX;i++){
        if(list[i]<tavg){
            lower[i]=list[i];
        }
    }
}

void compareIndividual(double list[][EIGHT],double *largest, double *smallest, double *dateL, double *dateS, int lake){
     *largest =list[ZERO][lake];
    *smallest =list[ZERO][lake];
    for(int i=0; i<ARRAYSIZE; i++){
        if(*largest < list[i][lake]){
            *largest=list[i][lake];
            *dateL = list[i][ONE];
        }
        if(*smallest > list[i][lake]){
            *smallest=list[i][lake];
            *dateS = list[i][ONE];
        }
    }
}

void order(double *smallest, double *largest){
    double num;
    
    if (*smallest < *largest) {
        num = *smallest;
        *smallest = *largest;
        *largest = num;
    }
}