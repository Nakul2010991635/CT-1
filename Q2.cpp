//Name = Nakul
//Roll no. = 2010991635
//Set = 05
//Q2

#include <bits/stdc++.h>
using namespace std;

// Function to print all subarrays in the array which
// has sum 0
vector<pair<int, int>> findSubArrays(int arr[], int n)
{
    // create an empty map
    unordered_map<int, vector<int>> map;

    // create an empty vector of pairs to store
    // subarray starting and ending index
    vector<pair<int, int>> out;

    // Maintains sum of elements so far
    int a = 0;

    for (int i = 0; i < n; i++)
    {
        // add current element to sum
        a += arr[i];

        // if sum is 0, we found a subarray starting
        // from index 0 and ending at index i
        if (a == 0)
            out.push_back(make_pair(0, i));

        // If sum already exists in the map there exists
        // at-least one subarray ending at index i with
        // 0 sum
        if (map.find(a) != map.end())
        {
            // map[sum] stores starting index of all subarrays
            vector<int> vc = map[a];
            for (auto it = vc.begin(); it != vc.end(); it++)
                out.push_back(make_pair(*it + 1, i));
        }

        // Important - no else
        map[a].push_back(i);
    }

    // return output vector
    return out;
}

// Utility function to print all subarrays with sum 0
void print(vector<pair<int, int>> out, int arr[])
{
    for (auto it = out.begin(); it != out.end(); it++)
    {
        cout<<"{";
        for (int i = it->first; i <= it->second; i++)
        {
            cout << arr[i] << " ";
        }
    cout<<"}";
        cout << endl;
    }
}

// Driver code
int main()
{
    int arr[50];
    int m;
    cout<<"Enter array size : ";
    cin>>m;
    cout<<"Enter array elements"<<endl;
    for (int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    cout<<"Subarrays with sum-zero are : "<<endl;
    int n = m;

    vector<pair<int, int>> out;

    try
    {
        out = findSubArrays(arr, n);
        if (out.size() == 0)
            throw(0);
    }
    catch (int size)
    {
        cout << "Size is " << size << endl;
    }

    // if we didn�t find any subarray with 0 sum,
    // then subarray doesn�t exists
    if (out.size() == 0)
        cout << "No subarray exists";
    else
        print(out, arr);

    return 0;
}

