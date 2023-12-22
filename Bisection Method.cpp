//This program is for finding root of a equation using Bisection method.
//Before runing the program find and insert the value of x1(line 13) and x2(line 15). The rest will be calculated by the program.
//I couldn't manage the spacing properly, so the output is little dirty. If anyone can manage the output s/he is request.

#include <iostream> 
#include <iomanip>
using namespace std;

float requiredError = 0.001;   //Required Error precision
float check = 0;   //Error checking precision

float Iteration = 0;
float x1 = 5;  // insert the value of x1
float fx1 = 0;
float x2 = 6;  // insert the value of x2
float fx2 = 0;
float x0 = 0;
float fx0 = 0;
float error = 0;

std::ostream& setGlobalPrecision(std::ostream& os) {
    return os << std::setprecision(5);    //Setting float precision to 5, not working properly tho ...
}

float valueOfX(float x)
{
   return ((x*x)-(4*x)-10);  //eq x^2 - 4*x - 10 = 0
}

float valueOfx0(float x1, float x2)
{
   return ((x1+x2)/2);
}

float valueOfError(float x1, float x2)
{
   return ((x2-x1)/x2);
}


int main()
{
   
   setGlobalPrecision(std::cout);   //calling line 18
   
   cout<<"Iteration\tx1\t\tf(x1)\t\tx2\t\tf(x2)\t\tx0\t\tf(x0)\t\tChange\t\tError"<<endl;

   while(check > requiredError | check == 0)
   {  
      ++Iteration;
      cout<<Iteration<<"\t\t";

      cout<<x1<<"\t\t";
      fx1 = valueOfX(x1);  //finding f(x1)
      cout<<fx1<<"\t\t\t";

      cout<<x2<<"\t\t";
      fx2 = valueOfX(x2);  //finding f(x2)
      cout<<fx2<<"\t\t";

      x0 = valueOfx0(x1,x2);  //finding X0
      cout<<x0<<"\t\t";

      fx0 = valueOfX(x0);  //finding f(X0)
      cout<<fx0<<"\t\t";

      error = valueOfError(x1,x2);

      if((fx1*fx0)<0)
      {
         x2 = x0;
         cout<<"x2=x0"<<"\t\t";
      }

      else if ((fx2*fx0)<0)
      {
         x1=x0;
         cout<<"x1=x0"<<"\t\t";
      }

      else
      {
         cout<<"ERROR OCCOUR"<<endl;
      }

      
      cout<<error<<"\t\t";

      cout<<endl;

    
      if(fx0 < 0){
         check = fx0 * -1;
      }
      else{
         check = fx0;
      }
      cout<<endl<<endl;
   }
   cout<<"The root is (x1+x2)/2="<<x1<<"+"<<x2<<"/2 = "<<((x1+x2)/2)<<endl;
return 0;
}
