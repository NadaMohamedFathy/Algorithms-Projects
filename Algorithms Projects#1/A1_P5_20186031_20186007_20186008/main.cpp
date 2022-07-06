//Nada Mohamed Fathy 20186031
//Ayat Hany 20186007
//Sarah Khaled 20186008
#include <iostream>
#include <vector>
using namespace std;
vector <string> vec;
void RecPermute(string soFar, string rest) 
 
{ 
 if (rest == "") // No more characters 
  {
	 vec.push_back(soFar);
	 
//cout << soFar << endl; // Print the word 
}
else // Still more chars 
// For each remaining char 
 
for (int i = 0; i < rest.length(); i++) { 
 
string next = soFar + rest[i]; // Glue next char 
 
string remaining = rest.substr(0, i)+ rest.substr(i+1); 
RecPermute(next, remaining); 
} 
 
}

// "wrapper" function 
 
 
void ListPermutations(string s) { 
RecPermute("", s); 

} 
void prnter(vector <string> v)
{
	for(int i=0;i<vec.size();i++)
	 {
	 	bool prnt=true;
	 	for(int j=i;j<vec.size();j++)
	 	{
	 		
	 		if(i!=j && vec[i]==vec[j])
	 		{
	 			prnt=false;
	 			break;
			 }
			 
			 	
		 } 
		 if (prnt)
		 cout<<vec[i]<<endl;
		 }
}
int main(int argc, char** argv) {
    string str;
    cout<<"Enter a word : ";
    cin>>str;
    ListPermutations(str);
    prnter(vec);
	return 0;
}
