#include<iostream>
#include<math.h>
#include<string.h>

using namespace std;
template<typename T>
class MySet
{
    private:
    int n;
    T *p;
    public:
    MySet()
    {
        n=0;
    }

    MySet(int m)
    {
        n=m;
    	p= new T[n];
        input();
    }
    void set(int m)
    {
    	n=m;
    	p= new T[n];
	}
    void input()
    {

            cout<<"Enter element of your set : \n";
            for(int i =0;i<n;i++)
            {
                cin>>p[i];
            }
            removeduplicate();
            display();
    }
    void display()
    {
        cout<<"\nYour set is : {";
        for(int i =0;i<n;i++)
            {
                cout<<p[i];
                if(i!=n-1)
                    cout<<",";
            }
            cout<<"}"<<endl;
            cout<<"Cardinality of this set is : "<<this->n<<endl;
    }
    void removeduplicate()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;)
            {
                if(p[i]==p[j])
                {
                    for(int k=j;k<n-1;k++)
                    {
                        p[k]=p[k+1];
                    }
                    n--;
                }
                else
                {
                    j++;
                    
                }
                
            }
        }
    }

    void powerset() 
	{ 
    	int pow_set_size = pow(2,n); 
    	int counter, j; 

		cout<<"{ ";
	    for(counter = 0; counter < pow_set_size; counter++) 	
   		{ 
   			if(counter!=0)
   			cout<<",";
   			
   			cout<<"{ ";
    		for(j = 0; j < n; j++) 
    		{ 	
        		if(counter & (1 << j)) 
        		{
        			if(j!=0)
					cout<<" ";
					cout <<p[j];
				}
         	 
    		} 
    		cout<<"} ";
    	
    	}
		cout<<"}"; 
	} 
    
    MySet operator +(MySet b)
    {
         MySet temp;
        temp.set(this->n+b.n);
        int index=0;
        for(int i=0;i<this->n;i++)
        {
            temp.p[index++]=this->p[i];
        }
        for(int i=0;i<b.n;i++)
        {
            temp.p[index++]=b.p[i];
        }
        temp.removeduplicate();
        return temp;
    }
    MySet operator *(MySet b)
    {
        int index=0;
        for(int i=0;i<this->n;i++)
        {
            for(int j=0;j<b.n;j++)
            {
                if(this->p[i]==b.p[j])
                    index++;
            }           
        }
        MySet temp;
        temp.set(index);
        index=0;
        for(int i=0;i<this->n;i++)
        {
            for(int j=0;j<b.n;j++)
            {
                if(this->p[i]==b.p[j])
                    temp.p[index++]=b.p[j];
            }           
        }
        temp.removeduplicate();
        return temp;
    }

    MySet operator -(MySet b)
    {
    	bool flag=false;
        int index=0;
        for(int i=0;i<this->n;i++)
        {
        	flag=false;
            for(int j=0;j<b.n;j++)
            {
                if(this->p[i]==b.p[j])
                {
                	flag=true;
                	break;
				}
            }  
			if(flag)
				index++;        
        }
        
        MySet temp;
        temp.set(this->n-index);
        index=0;
        for(int i=0;i<this->n;i++)
        {
            
            for(int j=0;j<b.n;j++)
            {
            	flag=false;
                if(this->p[i]==b.p[j])
                    break;
                else
                {
                	flag =true;
				}
            }
            if(flag==true)
            {
            	temp.p[index++]=this->p[i];
			}    
        }
        temp.removeduplicate();
        return temp;
    }

    void operator =(MySet b)
    {
        b.n=this->n;
        for(int i=0;i<b.n;i++)
            b.p[i]=this->p[i];
    }

    bool operator ==(MySet b)
    {
        if(this->n!=b.n )
            return false;
        else
        {
            int j=0;
            bool flag=false;

            while(true)
            {
                for(int i=j;i<this->n;i++)
                {
                   if(this->p[i]==b.p[i])
                       {
                           flag=true;
                           break;
                       }
                       else
                       {
                           flag=false;
                       }
               }
               if(flag==false)
                    break;
               else if(flag && j==this->n-1)
                    break;
               j++;
            }
            if(flag)
                return true;
            
            return false;
        }
    }
};

int main()
{


	
    int choice,choice2,n,m;
    char h;
    do 
     {
        cout<<"1 for powerset of a set"<<endl;
        cout<<"2 for union of two set"<<endl;
        cout<<"3 for intersection of two set"<<endl;
        cout<<"4 for difference between two set"<<endl;
        cout<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
            case 1:
                cout<<"\nenter 1 for numeric elenemt in a set "<<endl;
                cout<<"ente 2 for character element in a set "<<endl;
                cout<<"enter 3 for string type element "<<endl;
                cout<<endl;
                cout<<"Ente your type : ";
                cin>>choice2;
                cout<<endl;
        
                   if(choice2!=2&&choice2!=3)
                        {
                       	cout<<"Enter the size of set : ";
                        cin>>n;
                        cout<<endl;
                    	MySet<double> a(n);
                        a.powerset();
                        break;
						}
                    
                    
                    else if(choice2==2)
                       {
                       	cout<<"Enter the size of set : ";
                        cin>>n;
                        cout<<endl;
                        MySet<char> c(n);
                        c.powerset();
                        break;
					   }
                    
                    
                    else if(choice2==3)
                    {
                    	cout<<"Enter the size of set : ";
                        cin>>n;
                        cout<<endl;
                        MySet<string> e(n);
                        e.powerset();
                        break;
					}
                        
                
            case 2:
                cout<<"\nenter 1 for numeric elenemt in a set "<<endl;
                cout<<"enter 2 for character element in a set "<<endl;
                cout<<"enter 3 for string type element "<<endl;
                cout<<endl;
                cout<<"Ente your type : ";
                cin>>choice2;
                cout<<endl;
               
                    if(choice2!=2&&choice2!=3)
                    {
                    	                    
                    	cout<<"Enter the size of first set : ";
                        cin>>n;
                        cout<<endl;
                        MySet<double> a(n);
                        cout<<"\nEnter the size of second set : ";
                        cin>>m;
                        cout<<endl;
                        MySet<double> b(m);
                        MySet<double> x=a+b;
                        x.display();
                        break;	
					}

                    else if(choice2==2)
                    {
                    	cout<<"Enter the size of first set : ";
                        cin>>n;
                        cout<<endl;
                        MySet<char> c(n);
                        cout<<"\nEnter the size of second set : ";
                        cin>>m;
                        cout<<endl;
                        MySet<char> d(m);
                        MySet<char> y=c+d;
                        y.display();
                        break;
					}
           
                   else if(choice2==3)
                   {
                   	    cout<<"Enter the size of first set : ";
                        cin>>n;
                        cout<<endl;
                        MySet<string> c(n);
                        cout<<"\nEnter the size of second set : ";
                        cin>>m;
                        cout<<endl;
                        MySet<string> d(m);
                        MySet<string> z=c+d;
                        z.display();
                        break;
				   }
  
                case 3:

                cout<<"\nenter 1 for numeric elenemt in a set "<<endl;
                cout<<"enter 2 for character element in a set "<<endl;
                cout<<"enter 3 for string type element "<<endl;
                cout<<endl;
                cout<<"Ente your type : ";
                cin>>choice2;
                cout<<endl;
                    
                    if(choice2!=2&&choice2!=3)
                    {
                    	cout<<"Enter the size of first set : ";
                        cin>>n;
                        cout<<endl;
                        MySet<double> a(n);
                        cout<<"\nEnter the size of second set : ";
                        cin>>m;
                        cout<<endl;
                        MySet<double> b(m);
                        MySet<double> x=a*b;
                        x.display();
                        break;
					}
                    


                    else if(choice2==2)
                    {
                    	cout<<"Enter the size of first set : ";
                        cin>>n;
                        cout<<endl;
                        MySet<char> c(n);
                        cout<<"\nEnter the size of second set : ";
                        cin>>m;
                        cout<<endl;
                        MySet<char> d(m);
                        MySet<char> y=c*d;
                        y.display();
                        break;
					}

                    else if(choice2==3)
                   {
                   	    cout<<"Enter the size of first set : ";
                        cin>>n;
                        cout<<endl;
                        MySet<string> c(n);
                        cout<<"\nEnter the size of second set : ";
                        cin>>m;
                        cout<<endl;
                        MySet<string> d(m);
                        MySet<string> z=c*d;
                        z.display();
                        break;
				   }

                case 4:
                cout<<"\nenter 1 for numeric elenemt in a set "<<endl;
                cout<<"enter 2 for character element in a set "<<endl;
                cout<<"enter 3 for string type element "<<endl;
                cout<<endl;
                cout<<"Ente your type : ";
                cin>>choice2;
                cout<<endl;

                    if(choice2!=2&&choice2!=3)
                    {
                    	cout<<"Enter the size of first set : ";
                        cin>>n;
                        cout<<endl;
                        MySet<double> a(n);
                        cout<<"\nEnter the size of second set : ";
                        cin>>m;
                        cout<<endl;
                        MySet<double> b(m);
                        MySet<double> x=a-b;
                        x.display();
                        break;
					}
                    


                    else if(choice2==2)
                    {
                    	cout<<"Enter the size of first set : ";
                        cin>>n;
                        cout<<endl;
                        MySet<char> c(n);
                        cout<<"\nEnter the size of second set : ";
                        cin>>m;
                        cout<<endl;
                        MySet<char> d(m);
                        MySet<char> y=c-d;
                        y.display();
                        break;
					}

                    else if(choice2==3)
                   {
                   	    cout<<"Enter the size of first set : ";
                        cin>>n;
                        cout<<endl;
                        MySet<string> c(n);
                        cout<<"\nEnter the size of second set : ";
                        cin>>m;
                        cout<<endl;
                        MySet<string> d(m);
                        MySet<string> z=c-d;
                        z.display();
                        break;
				   }
                default:
                cout<<"Invalid choice "<<endl; 
        }
        cout<<"\nDo you want to continue y/n : ";
        cin>>h;
        cout<<endl;
        

    }while(h=='y');
    return 0;
}


