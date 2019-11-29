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
        if (word != a[i]) c++;
        if (word == a[i]) d++;
     }
        return d;
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
    
    cout << "Palabra a buscar: " <<palBusca << endl;
    
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
    		//printf("%s", line_buf);
    		tamLinea=getline(&line_buf, &line_buf_size, file);

    		c=countOccurences(line_buf, word); 
    		cuentafinal= cuentafinal+c;
    }
    cout <<"Veces que aparece la palabra: "<<cuentafinal << endl;
    return 0;
} 
