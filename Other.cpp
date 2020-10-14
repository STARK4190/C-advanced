#include<iostream>
using namespace std;
/* this project include advanced topics of C++ .
 static memeber function
 friend function classs
 generics data type (template,overloading too)
 namespace
*/

namespace abc{					//namespace abc
	
	void hello()
	{
		cout<<"inside namespace abc "<<endl;
	}
	
}
namespace xyz{					//namespace xyz
	
	void hello()
	{
		cout<<"inside namespace xyz"<<endl;
	}
	
}



class H{											//--- Class H start here
	
private:
	int key=90;				//private key can be accessed with frnd fucntion as mentioned below
		
public:
	
	static int count;
	H()	{									//constrcutor called
		cout<<"constrcutor called H"<<endl;
	}

	~H() {									//destructor called
		cout<<"Destructor called H"<<endl;
	}
	
public:	
	
	void static greet()	{			//static funtion
		cout<<"hello from H"<<endl;
		cout<<count<<" object made of H"<<endl;
	}
	
	friend void show(H);	//frnd function
};															//---Class H ends here
//----------------------------
//outide class 

int H::count=0;

void show(H s){				//frnd function with class H parameter 
		cout<<s.key;
	}

//--------------------------
class I{													//---Class I start here
		
	friend class H;
		
		
public:
	
	I()	{										//constructor called
		cout<<"constrcutor called I"<<endl;
	}
	
	int securitykey()	{				
			return 990;
				
		}
	
	template <class T,class U>		//template here 
	void adding(T a,U b){			//additon of two number of any type
		
		cout<<"addition is "<<a+b<<endl;
	}
	
	template <class T>		//template overloading called if only one paramter is passed
	void adding(T a){			
		
		cout<<"enter two number"<<endl;
	}
		
};															//---Class I ends here

int  main()
{
H h;
H::greet();		//static function calling 
I i;				
i.adding(23,2.3);	//adding two diff type of data type
i.adding(23);		//template overloading
show(h);

abc::hello(); //abs namespace and hello is function inside it
xyz::hello(); //xyz namespace and hello function inside too
}
