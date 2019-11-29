// C++ program to count the number 
// of occurrence of a word in 
// the given string given string 
#include <bits/stdc++.h>
#include <iostream>
//#include <string> 
using namespace std; 
  
//COMPARA PALABRA DE DICCONARIO CON LINEA  
  
int countOccurences(char *str, string word) 
{ 
    char *p; 
  
    // split the string by spaces in a 
    vector<string> a; 
  
    p = strtok(str, " "); 
    while (p != NULL) 
    { 
        a.push_back(p); 
        p = strtok(NULL, " "); 
    } 
  
    // search for pattern in a 
    int c = 0; 
    int d = 0;
    for (int i = 0; i < a.size(); i++) 
  	{
        // if not match found increase count 
        if (word != a[i]) 
            c++;
     
        
          // if match found increase count 
        if (word == a[i]) 
            d++;
           }
        //cout << "palabras que no son: "<< word << ": " << c << endl;
        //cout << "palabras que son: "<< word << ": " << d << endl;
        
        return c;
} 
  
  
  
  
 //TOMA PALABRA DE DICCIONARIO
  
 string PalabraDic(string filename)
 {	string word;
 	
 	string palabra;
 	ifstream Myfile;
     Myfile.open (filename.c_str());
     
     for(int i=0;i<2;i++){
     	Myfile >> word;
     } 	
 
 	return word;
 }
  
  
  
  
// Driver code 
int main() 
{ 
    string filename = "text.txt";
    string palBusca = PalabraDic(filename);
    
    cout << palBusca << endl;
    
    FILE *file;
    file=fopen("harry.txt", "r");
    char *line_buf=NULL;
    size_t line_buf_size=0;
    ssize_t tamLinea;
    int count_linea=0;
    int c;
    int cuentafinal=0;
    
    //char* str[];
    string word =palBusca;
    
     tamLinea=getline(&line_buf, &line_buf_size, file);
    while (tamLinea >= 0){
    		printf("%s", line_buf);
    		tamLinea=getline(&line_buf, &line_buf_size, file);
    		
   
    		
    		//str=line_buf;
    		c=countOccurences(line_buf, word); 
    		cuentafinal= cuentafinal+c;
    }
    
    
    cout << cuentafinal;
    
    
    /*char str[] = "GeeksforGeeks de A portal portal computer science de portal for degeeks sdfgdsg sdgfdgerg reger gre ger de "; 
    string word = palBusca;
    cout << countOccurences(str, word); 
    */
    return 0;
} 
