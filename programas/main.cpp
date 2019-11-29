// C++ program to count the number
// of occurrence of a word in
// the given string given string
#include <bits/stdc++.h>
#include <iostream>
//#include <string>
using namespace std;

//COMPARA PALABRA DE DICCONARIO CON LINEA

int countOccurences(char *str, string word){
    char *p;
    vector<string> a;

    p = strtok(str, " ");
    while (p != NULL){
        a.push_back(p);
        p = strtok(NULL, " ");
    }

    int c = 0;
    int d = 0;
    int j =0;
    for(int q=0;q<a.size();q++){
        string min=a[q];
        int j=0;
        while(min[j]){
            min[j]=tolower(min[j]);
            j++;
        }
        a[q]=min;
    }

    for (int i = 0; i < a.size(); i++){
        if (word != a[i]) c++;
        if (word == a[i]){
            d++;
            //cout<<a[i]<<' '<<a[i+1]<<endl;
        }
    }
    //cout<<"val: "<<d<<endl;
    return d;
}




 //TOMA PALABRA DE DICCIONARIO

string PalabraDic(string filename){
    string word;
 	string palabra;
 	ifstream Myfile;
    Myfile.open (filename.c_str());
    for(int i=0;i<2;i++){
     	Myfile >> word;
    }
 	return word;
}


int main(){
    string filename = "text.txt";
    string palBusca = PalabraDic(filename);
    FILE *file;
    file=fopen("harry.txt", "r");
    char *line_buf=NULL;
    size_t line_buf_size=0;
    ssize_t tamLinea;
    int count_linea=0, c, cuentafinal=0, d;

    tamLinea=getline(&line_buf, &line_buf_size, file);
    while (tamLinea >= 0){
    		//printf("%s", line_buf);
    		tamLinea=getline(&line_buf, &line_buf_size, file);
    		d = countOccurences(line_buf, palBusca);
    		cout<<d<<endl;
    		cuentafinal= cuentafinal+d;

    }
    //cout<<"Total palabras: "<<c+d<<endl;

    cout << cuentafinal;


    /*char str[] = "GeeksforGeeks de A portal portal computer science de portal for degeeks sdfgdsg sdgfdgerg reger gre ger de ";
    string word = palBusca;
    cout << countOccurences(str, word);
    */
    return 0;
}
