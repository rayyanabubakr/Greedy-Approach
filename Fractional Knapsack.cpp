// 1. You are given a number n, representing the count of items.
// 2. You are given n numbers, representing the values of n items.
// 3. You are given n numbers, representing the weights of n items.
// 3. You are given a number "cap", which is the capacity of a bag you've.
// 4. You are required to calculate and print the maximum value that can be created in the bag without overflowing it's capacity.
// Note1 -> Items can be added to the bag even partially. But you are not allowed to put same items again and again to the bag

#include<iostream>
#include <iomanip>
#include<math.h>
#include <string>

using namespace std;

float fractionalKnapsack(float profits[], float weights[], int capacity, int n)
{
  float pv[n];
  int temp ;
  for (int i = 0; i < n ; i++)
  {
    pv[i] = (float) (profits[i] / weights[i]);
  }
  for (int i = 0 ; i < n - 1 ; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (pv[i] < pv[j])
      {
        temp = pv[i];
        pv[i] = pv[j];
        pv[j] = temp;
        temp = profits[i];
        profits[i] = profits[j];
        profits[j] = temp;
        temp = weights[i];
        weights[i] = weights[j];
        weights[j] = temp;
      }
    }
  }
  float weight = 0.0, profit = 0.0;
  for (int i = 0 ; i < n ; i++)
  {
    if (weight + weights[i] <= capacity)
    {
      weight +=  (float) weights[i];
      profit +=  (float) profits[i];
    }
    else
    {
      profit +=  profits[i] * ((float) (capacity - weight) / (float) weights[i]);
      weight +=  weights[i] * ((float) (capacity - weight) / (float) weights[i]);
      break;
    }
  }
  return  profit;
}
int main()
{
  int n;
  float ans;
  string s1, s2;
  cin >> n;
  float profits[n], weights[n];
  int capacity;
  for (int i = 0; i < n ; i++)
  {
    cin >> profits[i];
  }
  for (int i = 0; i < n ; i++)
  {
    cin >> weights[i];
  }
  cin >> capacity;
  ans = fractionalKnapsack(profits, weights, capacity, n);
  if (ceil(ans) == floor(ans))
  {
    cout << fixed << setprecision(1) << ans;
  }
  else
  {
    cout << ans;
  }
}
