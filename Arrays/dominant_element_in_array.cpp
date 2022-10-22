#include <iostream>
using namespace std;
int main() {
	int t;
  cout<<"Enter number of test cases: ";
	cin>>t;
	while(t--)
	{
	    int n;
    cout<<"\nEnter size of array: ";
	    cin>>n;
	    int a[n],i,c,b[n],max=0;
    cout<<"\nEnter array elements: ";
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    for(i=0;i<n;i++)
	    {
	        c=0;
	        for(int j=i;j<n;j++)
	        {
	           if(a[i]==a[j])
	                c++;
	        }
	        b[i]=c;
	        if(b[i]>max){
	            max=b[i];
	        }
	    }
	    c=0;
	    for(i=0;i<n;i++)
	    {
	        if(max==b[i])
	        {
	            c++;
	            if(c==2)
	            {
    	            cout<<"\nThere are no dominant elements";
    	            break;
	            }
	        }
	    }
	    if(i==n)
	        cout<<"\nThere are dominant elements.";
	    cout<<endl;
}
return 0;
}
