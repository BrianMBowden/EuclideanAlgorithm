#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdio.h>

using namespace std;

#define __DEBUG 1

int* extendedEuclidean(int a, int b, int s1, int s2, int t1, int t2);

int main(){

  int a;
  int b;
  int q[3];
  int* q_ptr;
  
  cout << "enter a number: ";
  cin >> a;
  cout << "enter a divisor: ";
  cin >> b;

  q_ptr = extendedEuclidean(a, b, 1, 0, 0, 1);
  for(int i = 0; i < 3; i++){
    q[i] = *(q_ptr + i);
    
#if __DEBUG
    cout << q[i] << " ";
#endif
    
  }

#if __DEBUG
  cout << "gcd is: " << q[0] << endl;
  cout << "s_k is: " << q[1] << endl;
  cout << "t_k is: " << q[2] << endl;
#endif
  
  cout << "full equation: " << endl;
  printf("gcd(%d,%d) = %d = %d * %d + %d * %d \n", a,b,q[0],a,q[1],b,q[2]);
  
  
  return 0;
  
  
}
/*
 * Author: Brian Bowden
 * Date: November 3, 2018
 * Function: extendedEuclidean(int a, int b, int s1, int s2, int t1, int t2)
 *
 * Purpose: return the result of the extended euclidean algorithm to find the 
 *          gcd and Bezout coefficients associated with it. 
 *          the algorithm is given by the equation:
 *
 *          gcd(a, b) = r_k = a * s_k + b * t_k
 *
 * Return: results are stored in order of: a, s_k, t_k in an integer array
 */
int* extendedEuclidean(int a, int b, int s1, int s2, int t1, int t2){

  int q;
  int r;
  int si;
  int ti;
  static int answers[3];
  
  q = a/b;
  r = a - (q * b);
  si = s1 - (q * s2);
  ti = t1 - (q * t2);

#if __DEBUG
  cout << "quotient is: " << q << endl;
  cout << "remainder is: " << r << endl;
  cout << "si is: " << si << endl;
  cout << "ti is: " << ti << endl;
#endif
  
  if (r == 0){
    answers[0] = b; // gcd
    answers[1] = s2; // Bezout coefficient sk
    answers[2] = t2; // Bezout coefficient tk
    return (answers);
  }
  else {
    // b >> a
    // r >> b
    // s2 >> s1
    // si >> s2
    // t2 >> t1
    // ti >> t2
    return(extendedEuclidean(b, r, s2, si, t2, ti));
  }
  
  
}
