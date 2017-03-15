/* Author: Jingyu LI
 * Created at: Tue 30 Nov, 2016
 * Usage: 1. To splicing all the chromesomes to one
 * 	  2. To eliminate the useless data on the beginning and the end of each chromesome
 * Parameter: 1. input reference file
 * 	      2. output reference file
 * example: g++ preprocessing.cpp -o preprocessing
 * 	    ./preprocessing human_g1k_v37.fasta human_g1k_v37_new.fasta
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char * argv[]){
	ifstream fin;
	ofstream fout;
	string str;

	fin.open(argv[1]);
	if(!fin.is_open()){
		cout<<"Unable to access the input chromesome file."<<endl;
		return -1;
	}
	fout.open(argv[2]);
	getline(fin,str);
	fout<<str<<"\n";
	int length=40;
	
	while(!fin.eof()){
		getline(fin,str);
		
		if(str[0]=='>') continue;
		if(str[0]=='N'&&str[1]=='N') continue;
		
		if(str[str.length()-1]=='N'&&str[str.length()-2]=='N') continue;
		else fout << str <<"\n";	
		
	}



	fin.close();
	fout.close();
	return 0;
}
