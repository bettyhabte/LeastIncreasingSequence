#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>

using namespace std;

void LIS(vector<int>& L){
    
    vector< vector<int> > LIS(L.size());// vector LIS stores the longest subsequences
    
    LIS[0].push_back(L[0]);//push back the first subsequence that ends at L[0]
    
    /*
     for each element in vector L,
     checks if the current element in vector L, L[i], grater than L[j] where j is from 0 to i, and
     checks if the length of the subsequences of LIS[i] is less than LIS[j]
     to get the longest incresing subsequence that ends at L[j]
     */
    for(int i = 1; i < L.size(); i++){
        for(int j =0; j<i; j++){
            if(L[i]> L[j] && LIS[i].size()<LIS[j].size()){
                LIS[i] = LIS[j] ;
                
            }
        }
        LIS[i].push_back(L[i]);// then add L[i] into the subsequence in LIS[i]
    }
    /*
     prints the contents( the subsequences) in vector LIS
     */
    for(int i=0; i<LIS.size(); i++){
        for( int j = 0; j < LIS[i].size(); j++) {
            cout << LIS[i][j] <<" ";
        }
        cout << endl;
    }
    
    int longestValue =0  ;
    vector<int> sequence;
    /*
     adds the sizes of the subsequences in vector sequence
     */
    for( int i =0; i< LIS.size(); i++){
        sequence.push_back(LIS[i].size());
    }
    /*
     prints the contents of vector "sequence" that holds the lenght of each subsequences
     */
    cout << "The sequence of the lengths of each subsequences is : ";
    for(int i =0; i<sequence.size(); i++){
        cout << sequence[i]<< " ";
    }
    cout << endl;
    /*
     finds the longest length
     */
    int index;
   int maximumValue = sequence[0];
   for(int i=1; i< sequence.size() ; i++){
        
        if(sequence[i]>maximumValue){
            maximumValue = sequence[i];
            index = i;
        }
    
    }
    cout <<"The length of the longest subsequence is ; " << maximumValue<< endl;
    
    /*
     prints the longest increasing subsequence from vector LIS
     */
    cout <<"The sequence of the longest increasing subsequence is : " ;
    for ( int i : LIS[index]){
        cout << i << " ";
    }
    cout << endl;
    
    
}

int main(){

  

   ifstream myfile("incseq.txt");
   string line;
   vector<int> L;
   /*
    each element from the file added to the vector L
    */
   int i = 0;
   while (!myfile.eof()){
        getline(myfile, line);
        L.push_back(stoi(line));
        i++;
   }

   int n = L.size();
    
    /*
     prints the sequence of the input
     */
   cout << "The input sequence is : ";
   for( int i  = 0; i< n; i++){
       cout << L[i] << " " ;
   }
    cout << endl;
    LIS(L);


    return 0;
   }
