#include <bits/stdc++.h>

//problem statement : https://www.hackerrank.com/challenges/lilys-homework/
//https://www.youtube.com/watch?v=W8oGaAEOeRU
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int lilysHomework(vector<int> arr)
{
    vector<int> sortedIncrease = arr;
    vector<int> sortedDescreas = arr;
    vector<int> tempArray = arr;
    sort(begin(sortedIncrease), end(sortedIncrease));
    sort(begin(sortedDescreas), end(sortedDescreas), greater<int>());
    unordered_map<int, int> valIdxMapInc, valIdxMapDesc;

    // Get sorted indices for INC
    for (int i = 0; i < sortedIncrease.size(); i++)
    {
        valIdxMapInc[sortedIncrease[i]] = i;
    }
    // Get sorted indices for DESC
    for (int i = 0; i < sortedDescreas.size(); i++)
    {
        valIdxMapDesc[sortedDescreas[i]] = i;
    }

    int szI = 0, szD = 0, size = arr.size() - 1;
    // Inc
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != sortedIncrease[i])
        {
            swap(arr[i], arr[valIdxMapInc[arr[i]]]);
            szI++;
            i--;
        }
    }

    // Desc
    for (int i = 0; i < tempArray.size(); i++)
    {
        if (tempArray[i] != sortedDescreas[i])
        {
            swap(tempArray[i], tempArray[valIdxMapDesc[tempArray[i]]]);
            szD++;
            i--;
        }
    }

    //return the min of two solution
    return min(szI, szD);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
