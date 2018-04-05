/*////////////////////////////////////////////////////////////////////////////
Given an array of integers, calculate the fractions of its elements that are positive, negative, and are zeros. Print the decimal value of each fraction on a new line.

Note: This challenge introduces precision problems. The test cases are scaled to six decimal places, though answers with absolute error of up to  are acceptable.

Input Format

The first line contains an integer, , denoting the size of the array. 
The second line contains  space-separated integers describing an array of numbers .

Output Format

You must print the following  lines:

A decimal representing of the fraction of positive numbers in the array compared to its size.
A decimal representing of the fraction of negative numbers in the array compared to its size.
A decimal representing of the fraction of zeros in the array compared to its size.
Sample Input

6
-4 3 -9 0 4 1         
Sample Output

0.500000
0.333333
0.166667
Explanation
*/


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the plusMinus function below.
 */
void plusMinus(vector<int> arr) {
    /*
     * Write your code here.
     */
    float fPositive=0.0;
    float fNegative =0.0;
    float fZero = 0.0;
    int nPositive =0, nNegative=0,nZero=0;
    
    for(auto const& value: arr) {
        if(0==value){
            nZero++;
        }
        else if(value>0){
            nPositive++;
        }
        else{
            nNegative++;
        } 
    }
    
    fPositive = (float)nPositive/arr.size();
    fNegative = (float)nNegative/arr.size();
    fZero = (float)nZero/arr.size();
    
    cout<<fPositive<<endl;
    cout<<fNegative<<endl;
    cout<<fZero<<endl;

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int arr_itr = 0; arr_itr < n; arr_itr++) {
        int arr_item = stoi(arr_temp[arr_itr]);

        arr[arr_itr] = arr_item;
    }

    plusMinus(arr);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
