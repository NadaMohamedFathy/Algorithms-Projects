//Nada Mohamed Fathy 20186031
//Ayat Hany 20186007
//Sarah Khaled 20186008
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
class StudentName
{
	private:
		string name;
		vector <string> vec;
		static int spaceCounter; 
	public:
		
	    StudentName(string na)
        {
	        name=na;
	        
	        for(int i = 0; name[i]!='\0'; i++)
			{
	            if(name[i]==' ') 
			    {
                    spaceCounter++;
                }
            }   
	       if(spaceCounter==0)
	       { 
	            for(int i=0;i<3;i++)
	            {
	            	vec.push_back(name);
				}
				for(int i=0;i<vec.size();i++)
	            {
	            	cout<<vec[i]<<" ";
				}
				cout<<endl;
	       }
	       else if(spaceCounter==1)
        	{ 
	            int j=0;
	            for(int i=0; i<2 ;i++)
		        {
			        string n="";
			
			        while(j<=name.length())
	                {
	        	        if(name[j]==' '||j==name.length())
	                    {
	        	            vec.push_back(n);
	        	            j++;
	        	            n="";
	        	            break;
			            }
			            else
			            {
			                n += name[j];
	                        j++;
			        	}
	                } 
		        }
				vec.push_back(vec[1]);
				 for(int i=0;i<vec.size();i++)
	            {
	            	cout<<vec[i]<<" ";
				} 
				cout<<endl;
	        }
	        else
	        {
		        int j=0;
	            for(int i=0; i<spaceCounter+1 ;i++)
		        {
			        string n="";
			
			        while(j<=name.length())
	                {
	        	        if(name[j]==' '||j==name.length())
	                    {
	        	            vec.push_back(n);
	        	            j++;
	        	            n="";
	        	            break;
			            }
			            else
			            {
			                n += name[j];
	                        j++;
			        	}
	                } 
		        } 
		        for(int i=0;i<vec.size();i++)
	            {
	            	cout<<vec[i]<<" ";
				}
				cout<<endl;
	        }
		}
	
    void setname(string n)
    {
	    name=n;
    }
		
    string getname()const
    {
	    return name ; 
    }
    void print()
    {
	    for(int i=0;i<vec.size();i++)
        {
    		cout<<i+1<<") "<<vec[i]<<endl;
    	}		
    }
    void replace(int s,int w)
    {
    	s--;
    	w--;
    	if(s>=vec.size() || w>=vec.size() || s<0 || w<0)
    	{
    		cout<<"Error"<<endl;
    	}
    	else
    	{ 
    		cout<<endl;
    		swap(vec[s],vec[w]);
    		for(int i=0;i<vec.size();i++)
    		{
    			cout<<vec[i]<<"   ";
    		}
    	}
    	cout<<endl;
    }
};
int StudentName::spaceCounter=0;
int main(int argc, char** argv) {
	string n;
    StudentName	m("nada");
    m.print();
	m.replace(1,2);
	StudentName s("nada mohamed");
	s.print();
	s.replace(1,3);
	StudentName d("nada mohamed fathy");
	d.print();
	d.replace(2,3);
	StudentName f("nada mohamed fathy omar");
	f.print();
	f.replace(2,4);
	StudentName g ("nada mohamed fathy omar haggag");
	g.print();
	g.replace(1,3);
	int a,b;
	cout<<"Enter your name : ";
	getline(cin, n);
	StudentName Name(n);
	Name.print();
	cout<<endl<<"Enter index  ";
    cin>>a>>b;
	Name.replace(a,b);
	return 0;
}
