#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int solution(vector<int> citations) 
{
    sort(citations.begin(), citations.end(), greater<int>());
    
    int count = 0;
    for(int i = 0; i < citations.size(); i++)
    {
        if(citations[i] >= i + 1)
            count++;
        else
            break;
    }
    return count;
}
