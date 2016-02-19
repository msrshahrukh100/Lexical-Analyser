#include <iostream>
#include <string.h> 
#include <fstream>

using namespace std;

int main()
{
		int i=0;
		char a;
		string istate,fstate,productions[20],str,currentstate;
		fstream infile;
		infile.open("info.txt", ios::in );
		cout<<"The contents of the file is : "<<endl;
		getline(infile,istate);
		currentstate = istate;        //Setting the initial state as the currentstate 

		getline(infile,fstate);
			

		while(getline(infile,str))
			productions[i++] = str;

		// int k=0;
		// while(k<i)
		// 	{cout<<productions[k];k++;}

		cout<<"Please enter the string you want to test: \n\t";
		cin>>str;


		for (int k=0; k<str.length(); k++)
		{

			for(int l=0;l<productions[0].length();l++)  //The index of the input symbol is founf
				if(productions[0][l] == str[k])
					break;

			cout<<l;

			for (int j=0;j<i;j++)						//The production to be used is found 
				if (productions[j][0] == currentstate)
					break;
			




			// Finding the current state



		}

		
	return 0;
}


