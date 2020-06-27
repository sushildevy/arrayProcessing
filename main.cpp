//file:          <main.cpp>
//Name:          <Sushil Pandey>
//class:          CSIS 252
//program:        assignment 4
//date:          <02/016/2018>

#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
//program description
//This program is related to array processing and functions.
//constant initilization
const int arraySize =30;
const int sentinel= -1;

const float A_min = 90; 
const float B_min = 80;
const float C_min = 70;
const float D_min = 60;

// read input  
void read(int scores[],int& count,int& maxScore)
  {
    count=0;
    
    cout<<"please enter the maximum possible value:"<<endl;
    cin>>maxScore;
    int testScore;
    cout<<"please enter the student test scores:"<<endl;
    cin>>testScore;
    while (testScore!=sentinel && count<arraySize)
    {
      if (testScore <= maxScore)
      {
	scores[count]=testScore;
        count++;
      }
      else
	cout<<"Sry!! your score is bigger than maximum score"<<endl;
      
      cout<<"please enter the student test scores:"<<endl; 
           cin>>testScore;
    }
  }
  
//sort an array of scores descendingly
void sort(int scores[] , int& count)
{
   int temp;
   int large;
   for (int i=0; i<count-1; i++)   // put n-1 ints in their correct spot
   {
      large=i;
      for (int j=i+1;j<count;j++)//loop to find the largest
         if (scores[j] > scores[large])
            large=j;
      temp = scores[i];         // put largeest in proper position
      scores[i] = scores[large];
      scores[large] = temp;
   }
}

//function for average calculation
double avg(const int scores[],int count)
{    
     int sum=0;
     for(int i=0; i<count;i++)
     {
         sum+=scores[i];
	 
     }
     double average;   
     cout<<fixed<<showpoint<<setprecision(2)<<endl;
     return static_cast<double>(sum )/count;
     
}

//function for median calculation
double median( const int scores[] , int& count)
{
  int c1,c2;
  double even, odd;
  c1=(count/2);
  c2=(count/2)-1;
  even=static_cast<double>((scores[c1]+scores[c2]))/2;
  odd=scores[c1];
  
    if(count%2==0)
      return even;
    else
      return odd;
  
}
//function for tabulation form of output
void outputScores(const int scores[],int count,int maxScore)
{ 
  char grade;
  
  cout  << setw(10) <<left<<"score" <<setw(16) <<"Prercentage(%)"<<setw(9)<<right<<"Grade"<<endl;
  for(int i=0;i<count;i++)
  {
    cout<<fixed<<showpoint<<setprecision(2);
    double pct = static_cast<double>(scores[i]) / maxScore * 100;
  if (pct >= A_min)
     grade='A';
  else if (pct>=B_min)
      grade='B';
  else if (pct>=C_min)
      grade='C';
  else if (pct >=D_min)
    grade='D';
  else
    grade='F';
  cout<<setw(10)<<left<<scores[i]<<setw(3)<<setw(6)<<right<<pct<<" %"<<setw(15)<<right<<grade<<endl;
       
  }
}
    
//standard deviation calculation    
double stDeviation(const int scores[], int count)
{
  double mean;
  double sqr ;
  double tot=0;
  double stDeviation;
  mean=avg(scores,count);
  for(int i=0;i <count;i++)
  {
    sqr=pow((scores[i]-mean),2);
    tot+=sqr;
  }
    stDeviation=sqrt(tot/count);
    return stDeviation;
}
//function for output summary
double outputSummary(const int scores[],int count, int maxScore)
{ 
  
  cout<<"The output summary goes like this:"<<endl<<endl;
  cout<<"The maximum score is "<< maxScore<<endl<<endl;
  cout<<"The number of students processed is "<<count<<endl<<endl;
  cout<<"The high score is "<<scores[0]<<endl<<endl;
  cout<<"The low score is "<<scores[count-1]<<endl<<endl;
  cout<<"The range of the score is "<<scores[0]-scores[count-1]<<endl;
  cout<<"The average of the scores is "<<avg(scores,count)<<endl<<endl;
  cout<<"The median score is "<<median (scores,count)<<endl;
  cout<<"The standard deviation is "<<stDeviation(scores,count)<<endl<<endl;
  return 0;
}

int main() 
{
  //variables 
  int scores[arraySize]; 
  int maxScore;           //maximum scores
  int count;              // count of scores
  
  //calling above function
  read(scores,count,maxScore);
  sort(scores,count);
  cout<<"The table form is:"<<endl;
  outputScores(scores,count,maxScore);
  outputSummary(scores,count,maxScore);
  return 0;
  
}    