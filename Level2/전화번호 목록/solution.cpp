#include <string>    // size, subsrtr 사용
#include <vector>    
#include <algorithm>  // sort 사용
using namespace std;

bool solution(vector<string> phone_book) 
{
    sort(phone_book.begin(), phone_book.end());
        
    for(int i = 0; i + 1 < phone_book.size(); i++)      // 범위 잘 생각하기
    {
        string a = phone_book[i];
        string b = phone_book[i + 1];
        
        if(b.substr(0, a.size()) == a)    // 문자열.substr(시작 위치, 자를 길이)
            return false;   
    }
    
    return true;
}
