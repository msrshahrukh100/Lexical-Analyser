/*Lexical Analyser for the semester Assignment by Mohammad Shahrukh 
Enter the DFA in info.txt in the format
initial state
final states
transitions like current state and transition to final state
eg.
0 
1
# a b
0 0 1
1 ? 1

*/

#include <iostream>
#include <string.h> 
#include <fstream>

using namespace std;

int main()
{
		int i=0;
		char a;
		string istate,fstate,productions[20],str;
		char currentstate;
		fstream infile;
		infile.open("info.txt", ios::in );
		cout<<"The contents of the file is : "<<endl;
		getline(infile,istate);
		currentstate = istate[0];        //Setting the initial state as the currentstate 

		getline(infile,fstate);
			

		while(getline(infile,str))
			productions[i++] = str;

	

		cout<<"Please enter the string you want to test: \n\t";
		cin>>str;
		int flag=0;

		for (int k=0; k<str.length(); k++)
		{
			int l,j;

			for (j=0;j<i;j++)						//The production to be used is found 
				if (productions[j][0] == currentstate)
					break;

			for(l=0;l<productions[0].length();l++)  //The index of the input symbol is founf
				if(productions[0][l] == str[k])
					break;

			currentstate = productions[j][l];
			if(currentstate == '?')
				break;

			for (j=0;j<i;j++)						//The production to be used is found 
				if (productions[j][0] == currentstate)
					break;			
		}

		for (int k=0; k<fstate.length(); k++)
		{
			if(fstate[k] == currentstate)
			{flag=1;cout<<"Yes this statement could be obtained from given DFA "<<endl;break;}
		}
		if(flag == 0)
			cout<<"This statement could not be achieved by  this DFA ! "<<endl;

		// cout<<currentstate<<endl;

		
	return 0;
}


