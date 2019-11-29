    #include<iostream>
    #include<fstream>
    using namespace std;
    int main(){
        int count = 0;
        int divide= 0;
        string line;
        /* Creating input filestream */ 
        ifstream file("palabras.txt");
        while (getline(file, line))
            count++;
        cout << "Numbers of lines in the file : " << count << endl;
        
        divide= count/4;
        cout << "Lines per computer:" << divide << endl;
        return 0;
    }
